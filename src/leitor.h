#ifndef LEITOR_H_
#define LEITOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct ClassFile;
typedef struct ClassFile ClassFile;
struct MethodInfo;
typedef struct MethodInfo MethodInfo;
struct AttributeInfo;
typedef struct AttributeInfo AttributeInfo;

struct ClassFile {
    uint32_t magic;
    uint16_t minor_version;
    uint16_t major_version;
    uint16_t constant_pool_count;
    /* cp_info constant_pool */
    uint16_t access_flags;
    uint16_t this_class;
    uint16_t super_class;
    uint16_t interfaces_count;
    uint16_t* interfaces;
    uint16_t fields_count;
    /* field_info fields */
    uint16_t methods_count;
    MethodInfo* methods;
    uint16_t attributes_count;
    AttributeInfo* attributes;
};

struct MethodInfo {
    uint16_t access_flags;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    AttributeInfo* attributes;
};

struct AttributeInfo {
    uint16_t attribute_name_index;
    uint32_t attribute_length;
    uint8_t* info;
};

ClassFile readClassFile(char* file_name);

#endif /* LEITOR_H_ */
