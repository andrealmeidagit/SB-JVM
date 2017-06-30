#ifndef LEITOR_H_
#define LEITOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/********  Attribute types  *******/
#define CONSTANT_VALUE       0
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

struct LocalVariable {
    uint16_t start_pc;
    uint16_t length;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t index;
};
typedef struct LocalVariable LocalVariable;

struct LineNumber {
    uint16_t start_pc;
    uint16_t line_number;
};
typedef struct LineNumber LineNumber;

struct InnerClasses {
    uint16_t    inner_class_info_index;
    uint16_t    outer_class_info_index;
    uint16_t    inner_name_index;
    uint16_t    inner_class_access_flags;
};
typedef struct InnerClasses InnerClasses;

struct ExceptionTable {
    uint16_t    start_pc;
    uint16_t    end_pc;
    uint16_t    handler_pc;
    uint16_t    catch_type;
};
typedef struct ExceptionTable ExceptionTable;

struct AttributeInfo {
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
            ExceptionTable* exception_table;
            uint16_t attributes_count;
            struct AttributeInfo* attributes;
        }Code;

        struct{
            uint16_t number_of_exceptions;
            uint16_t* exception_index_table;
        }Exceptions;

        struct{
            uint16_t number_of_classes;
            InnerClasses* classes;
        }InnerClasses;

        struct{

        }Synthetic;

        struct{
            uint16_t sourcefile_index;
        }SourceFile;

        struct{
            uint16_t line_number_table_length;
            LineNumber *line_number_table;
        }LineNumberTable;

        struct{
            uint16_t local_variable_table_length;
            LocalVariable * local_variable_table;
        }LocalVariableTable;

        struct{

        }Deprecated;

    }u;
};
typedef struct AttributeInfo AttributeInfo;

struct FieldInfo {
    uint16_t access_flags;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    AttributeInfo* attributes;
};
typedef struct FieldInfo FieldInfo;

struct MethodInfo {
    uint16_t access_flags;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    AttributeInfo* attributes;
};
typedef struct MethodInfo MethodInfo;

struct ClassFile {
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
    FieldInfo* fields;
    uint16_t methods_count;
    MethodInfo* methods;
    uint16_t attributes_count;
    AttributeInfo* attributes;
};
typedef struct ClassFile ClassFile;

ClassFile readClassFile(char* file_name);
ATTRIBUTE_TYPE getAttributeType (AttributeInfo* a_info, ClassFile* class_file);

#endif
