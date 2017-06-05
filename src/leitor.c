#include "leitor.h"

static uint8_t readByte(FILE* fp);
static uint16_t read2Byte(FILE* fp);
static uint32_t read4Byte(FILE* fp);
static void readConstantPool(ClassFile* class_file, FILE* fp);
static void readInterfaces(ClassFile* class_file, FILE* fp);
static void readFields(ClassFile* class_file, FILE* fp);
static void readMethods(ClassFile* class_file, FILE* fp);
static void readAttributes(ClassFile* class_file, FILE* fp);
static AttributeInfo* readAttributeArray(uint16_t attributes_count, FILE* fp);

ClassFile readClassFile(char* file_name) {
    FILE *fp;
    ClassFile class_file;
    fp = fopen(file_name, "rb");

    class_file.magic = read4Byte(fp);
    class_file.minor_version = read2Byte(fp);
    class_file.major_version = read2Byte(fp);
    readConstantPool(&class_file, fp);
    class_file.access_flags = read2Byte(fp);
    class_file.this_class = read2Byte(fp);
    class_file.super_class = read2Byte(fp);
    readInterfaces(&class_file, fp);
    readFields(&class_file, fp);
    fclose(fp);
    return class_file;
    readMethods(&class_file, fp);
    readAttributes(&class_file, fp);
}

static uint8_t readByte(FILE* fp) {
    uint8_t byte;
    fread(&byte, 1, 1, fp);
    return byte;
}

static uint16_t read2Byte(FILE* fp) {
    uint16_t byte2;
    byte2 = readByte(fp);
    byte2 = (byte2 << 8) | readByte(fp);
    return byte2;
}

static uint32_t read4Byte(FILE* fp) {
    uint32_t byte4;
    byte4 = read2Byte(fp);
    byte4 = (byte4 << 16) | read2Byte(fp);
    return byte4;
}

static void readConstantPool(ClassFile* class_file, FILE* fp) {
    class_file->constant_pool_count = read2Byte(fp);
}

static void readInterfaces(ClassFile* class_file, FILE* fp) {
    class_file->interfaces_count = read2Byte(fp);
    if (class_file->interfaces_count > 0) {
        class_file->interfaces = (uint16_t*)malloc(sizeof(uint16_t) * class_file->interfaces_count);
        for(uint16_t* it = class_file->interfaces; it < class_file->interfaces + class_file->interfaces_count; ++it)
            *it = read2Byte(fp);
    }
    else
        class_file->interfaces = NULL;
}

static void readFields(ClassFile* class_file, FILE* fp) {
    class_file->fields_count = read2Byte(fp);
}

static void readMethods(ClassFile* class_file, FILE* fp) {
    class_file->methods_count = read2Byte(fp);
    if (class_file->methods_count > 0) {
        class_file->methods = (MethodInfo*)malloc(sizeof(MethodInfo) * class_file->methods_count);
        for(MethodInfo* it = class_file->methods; it < class_file->methods + class_file->methods_count; ++it) {
            it->access_flags = read2Byte(fp);
            it->name_index = read2Byte(fp);
            it->descriptor_index = read2Byte(fp);
            it->attributes_count = read2Byte(fp);
            it->attributes = readAttributeArray(it->attributes_count, fp);
        }
    }
    else
        class_file->methods = NULL;
}

static void readAttributes(ClassFile* class_file, FILE* fp) {
    class_file->attributes_count = read2Byte(fp);
    class_file->attributes = readAttributeArray(class_file->attributes_count, fp);
}

static AttributeInfo* readAttributeArray(uint16_t attributes_count, FILE* fp) {
    if (attributes_count == 0)
        return NULL;
    AttributeInfo* array = (AttributeInfo*)malloc(sizeof(AttributeInfo) * attributes_count);
    for (AttributeInfo* it = array; it < array + attributes_count; ++it) {
        it->attribute_name_index = read2Byte(fp);
        it->attribute_length = read4Byte(fp);
        if (it->attribute_length == 0)
            it->info = NULL;
        else {
            for(uint8_t* it_info = it->info; it_info < it->info + it->attribute_length; ++it_info)
                *it_info = readByte(fp);
        }
    }
}
