#ifndef LEITOR_H_
#define LEITOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/********  Attribute types  *******/
#define CONSTANTE_VALUE      0
#define CODE                 1
#define EXCEPTIONS           2
#define INNER_CLASSES        3
#define SYNTHETIC            4
#define SOURCE_FILE          5
#define LINE_NUMBER_TABLE    6
#define LOCAL_VARIABLE_TABLE 7
#define DEPRECATED           8
#define UNKNOWN              9
#define ATTRIBUTE_TYPE       short
/**********************************/

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

//Constant Pool
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
            float bytes;
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


//LocalVariable
struct LocalVariable_{
    uint16_t start_pc;
    uint16_t length;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t index;
};
typedef struct LocalVariable_ local_variable_table_t;

//LineNumber
struct LineNumber_{
    uint16_t start_pc;
    uint16_t line_number;
};
typedef struct LineNumber_ line_number_table_t;

//InnerClasses
struct InnerClasses_{
    uint16_t    inner_class_info_index;
    uint16_t    outer_class_info_index;
    uint16_t    inner_name_index;
    uint16_t    inner_class_access_flags;
};
typedef struct InnerClasses_ inner_classes_t;

//ExceptionTable
struct ExceptionTable_{
    uint16_t    start_pc;
    uint16_t    end_pc;
    uint16_t    handler_pc;
    uint16_t    catch_type;
};
typedef struct ExceptionTable_ exception_table_t;

//AttributeInfo
struct attribute_info{
    uint16_t attribute_name_index;
    uint32_t attribute_length;
    union{
        struct{
            uint16_t constantvalue_index;
        }ConstantValue;

        struct{
            uint16_t max_stack;
            uint16_t max_locals;
            uint32_t code_length;
            uint8_t* code;
            uint16_t exception_table_length;
            exception_table_t* exception_table;
            uint16_t attributes_count;
            struct attribute_info* attributes;
        }Code;

        struct{
            uint16_t number_of_exceptions;
            uint16_t* exception_index_table;
        }Exceptions;

        struct{
            uint16_t number_of_classes;
            inner_classes_t* classes;
        }InnerClasses;

        struct{

        }Synthetic;

        struct{
            uint16_t sourcefile_index;
        }SourceFile;

        struct{
            uint16_t line_number_table_length;
            line_number_table_t *line_number_table;
        }LineNumberTable;

        struct{
            uint16_t local_variable_table_length;
            local_variable_table_t * local_variable_table;
        }LocalVariableTable;

        struct{

        }Deprecated;

    }u;
};
typedef struct attribute_info attribute_info;

//FieldInfo
struct FieldInfo_{
    uint16_t access_flags;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    attribute_info* attributes;
};
typedef struct FieldInfo_ field_info;

//MethodInfo
struct MethodInfo_ {
    uint16_t access_flags;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    attribute_info* attributes;
};
typedef struct MethodInfo_ MethodInfo;

//ClassFile
struct ClassFile_ {
    uint32_t magic;
    uint16_t minor_version;
    uint16_t major_version;
    uint16_t constant_pool_count;
    CP_table* constant_pool;
    uint16_t access_flags;
    uint16_t this_class;
    uint16_t super_class;
    uint16_t interfaces_count;
    uint16_t* interfaces;
    uint16_t fields_count;
    field_info* fields;
    uint16_t methods_count;
    MethodInfo* methods;
    uint16_t attributes_count;
    attribute_info* attributes;
};
typedef struct ClassFile_ ClassFile;

ClassFile readClassFile(char* file_name);
ATTRIBUTE_TYPE getAttributeType (attribute_info* a_info, ClassFile* class_file);

#endif
