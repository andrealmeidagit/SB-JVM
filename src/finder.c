#include "finder.h"

MethodInfo* findMethod(const char* method_name, ClassFile* class_file) {
    uint16_t i;
    for (i = 0; i < class_file->methods_count; ++i) {
        MethodInfo* method_info = class_file->methods + i;
        ConstantInfo method_name_constant = class_file->constant_pool[method_info->name_index - 1];
        if (strcmp((const char*)method_name_constant.CONSTANT.Utf8_info.bytes, method_name) == 0)
            return method_info;
    }
    fprintf(stderr, "[ERROR]: MethodNameNotFoundError\n");
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
