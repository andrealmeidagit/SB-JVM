#include "finder.h"

MethodInfo* findMethod(const char* method_name, ClassFile* class_file) {
    uint16_t i;
    for (i = 0; i < class_file->methods_count; ++i) {
        MethodInfo* method_info = class_file->methods + i;
        ConstantInfo method_name_constant = class_file->constant_pool[method_info->name_index - 1];
        if (strcmp((const char*)method_name_constant.CONSTANT.Utf8_info.bytes, method_name) == 0)
            return method_info;
    }
    return NULL;
}

MethodInfo* findMethodWithDesc(const char* method_name, const char* method_descriptor, ClassFile* class_file) {
    for (uint16_t i = 0; i < class_file->methods_count; ++i) {
        MethodInfo* method_info = class_file->methods + i;
        ConstantInfo method_name_constant = class_file->constant_pool[method_info->name_index - 1];
        ConstantInfo method_descriptor_constant = class_file->constant_pool[method_info->descriptor_index - 1];
        if (strcmp((const char*)method_name_constant.CONSTANT.Utf8_info.bytes, method_name) == 0 &&
            strcmp((const char*)method_descriptor_constant.CONSTANT.Utf8_info.bytes, method_descriptor) == 0)
            return method_info;
    }
    fprintf(stderr, "[ERROR]: MethodNameAndDescriptorNotFoundError: (%s|%s)\n", method_name, method_descriptor);
    exit(EXIT_FAILURE);
    return NULL;
}

AttributeInfo* findCodeAttribute(const MethodInfo* method, const ConstantInfo* constant_pool) {
    uint16_t i;
    for (i = 0; i < method->attributes_count; ++i) {
        AttributeInfo* current_attribute = method->attributes + i;
        if (strcmp("Code", (char *)constant_pool[current_attribute->attribute_name_index - 1].CONSTANT.Utf8_info.bytes) == 0)
            return current_attribute;
    }
    fprintf(stderr, "[ERROR]: CodeAttributeNotFoundError");
    exit(EXIT_FAILURE);
    return NULL;
}

ClassFile* findClassFile(char* class_name, ClassFile* class_files, uint16_t class_files_count) {
    for (int i = 0; i < class_files_count; ++i) {
        ClassFile* class_file = class_files + i;
        char* class_file_name = (char*)class_file->constant_pool[class_file->constant_pool[class_file->this_class-1].CONSTANT.Class_info.name_index-1].CONSTANT.Utf8_info.bytes;
        if (strcmp(class_file_name, class_name) == 0)
            return class_file;
    }
    fprintf(stderr, "[ERROR]: ClassFileNotFoundError: %s\n", class_name);
    exit(EXIT_FAILURE);
    return NULL;
}

uint32_t argumentAmountFromDescriptor(char* descriptor) {
    int i = 0;
    int argument_amount = 0;
    while(descriptor[++i] != ')') {
        argument_amount++;
        if (descriptor[i] == 'D' || descriptor[i] == 'J')
            argument_amount++;
    }
    return argument_amount;
}
