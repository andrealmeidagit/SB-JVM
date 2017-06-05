#ifndef LEITOR_H_
#define LEITOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned char uchar;

struct ClassFile_ {
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
    /* method_info methods */
    uint16_t attributes_count;
    /* attribute_info attributes */
};
typedef struct ClassFile_ ClassFile;

ClassFile readClassFile(char* file_name);

#endif /* LEITOR_H_ */
