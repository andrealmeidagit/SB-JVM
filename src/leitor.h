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

typedef unsigned char uchar;

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
struct AttributeInfo_{
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
typedef struct AttributeInfo_ attribute_info;

//FieldInfo
struct FieldInfo_{
    uint16_t access_flags;           
    uint16_t name_index;             
    uint16_t descriptor_index;       
    uint16_t attributes_count;       
    attribute_info* attributes;      
};
typedef struct FieldInfo_ field_info;

//ClassFile
struct ClassFile_ {
    uint32_t magic;
    uint16_t minor_version;
    uint16_t major_version;
    uint16_t constant_pool_count;
    /* cp_info constant_pool; */
    uint16_t access_flags;
    uint16_t this_class;
    uint16_t super_class;
    uint16_t interfaces_count;
    uint16_t* interfaces;
    uint16_t fields_count;
    field_info* fields;
    uint16_t methods_count;
    /* method_info methods; */
    uint16_t attributes_count;
    attribute_info* attributes;
};
typedef struct ClassFile_ ClassFile;

ClassFile readClassFile(char* file_name);

#endif