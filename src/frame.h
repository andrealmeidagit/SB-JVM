#ifndef FRAME_H_
#define FRAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "leitor.h"

struct OperandInfo {
    uint32_t data;
    struct OperandInfo *next;
};
typedef struct OperandInfo OperandInfo;

struct Frame {
    MethodInfo* methods;
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

    uint32_t return_address;
};
typedef struct Frame Frame;

#endif /* FRAME_H_ */
