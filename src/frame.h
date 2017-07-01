#ifndef FRAME_H_
#define FRAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "leitor.h"

struct OperandInfo {
    uint32_t data;
    struct OperandInfo *previous;
};
typedef struct OperandInfo OperandInfo;

struct Frame {
    MethodInfo* method_info;
    uint32_t pc;
    OperandInfo* operand_stack;
    uint32_t local_variable_count;
    uint32_t* local_variables;
    uint16_t constant_pool_count;
    ConstantInfo* constant_pool;

    /*
    elementoListaArrays *listaArrays;
    elementoListaObjetos *listaObjetos;
    */

    struct Frame* previous;
};
typedef struct Frame Frame;

Frame* newFrame(ClassFile* class_file, MethodInfo* method_info, Frame* previous);

#endif /* FRAME_H_ */
