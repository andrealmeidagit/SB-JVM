#ifndef LEITOR_H_
#define LEITOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned char uchar;


/*Tabela de tags*/
#define Const_Utf8      1
#define Const_Int       3
#define Const_Float     4
#define Const_Long      5
#define Const_Double    6
#define Const_Class     7
#define Const_String    8
#define Const_FRef      9
#define Const_MRef      10
#define Const_IRef      11
#define Const_NAT       12
#define Const_MHand     15
#define Const_MType     16
#define Const_InDyn     18


struct CP_table{
    uint8_t tag;
    union{
        struct{
            uint16_t name_index;
        }Class_info;   //tag == 7

        struct{
            uint16_t class_index;
            uint16_t name_and_type_index;
        }Fieldref_info;    //tag == 9

        struct{
            uint16_t class_index;
            uint16_t name_and_type_index;
        }Methodref_info;   //tag == 10

        struct{
            uint16_t class_index;
            uint16_t name_and_type_index;
        }InterfaceMethodref_info;  //tag == 11

        struct{
            uint16_t string_index;
        }String_info;    //tag == 8

        struct{
            uint32_t bytes;
        }Integer_info; //tag == 3

        struct{
            uint32_t bytes;
        }Float_info;   //tag == 4

        struct{
            uint32_t high_bytes;
            uint32_t low_bytes;
        }Long_info;    //tag == 5

        struct{
            uint32_t high_bytes;
            uint32_t low_bytes;
        }Double_info;  //tag == 6

        struct{
            uint16_t name_index;
            uint16_t descriptor_index;
        }NameAndType_info; //tag == 12

        struct{
            uint16_t length;
            uint8_t* bytes;
        }Utf8_info;  //tag == 1

        struct{
            uint8_t reference_kind;
            uint16_t reference_index;
        }MethodHandle_info;  //tag == 15

        struct{
            uint16_t descriptor_index;
        }MethodType_info;  //tag == 16

        struct{
            uint16_t bootstrap_method_attr_index;
            uint16_t name_and_type_index;
        }InvokeDynamic_info;  //tag == 18
    }CONSTANT;
};
typedef struct CP_table CP_table;

struct ClassFile_ {
    uint32_t magic;
    uint16_t minor_version;
    uint16_t major_version;
    uint16_t constant_pool_count;
    CP_table* cp_info;
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
