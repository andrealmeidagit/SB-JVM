#ifndef LINKER_H_
#define LINKER_H_

#include <stdio.h>
#include <string.h>
#include "interpreter.h"
#include "frame.h"
#include "constant_pool.h"


typedef union FieldType{
    int8_t    byte_type;
    char      char_type;
    double    double_type;
    float     float_type;
    int       integer_type;
    long int  long_type;
    char*     class_name_ref;
    short int short_type;
    int8_t    bool_type;
    char*     array_ref; /*?*/
}FieldType;

//Funções auxiliares
FieldType* read_field_type (char* str);

#endif
