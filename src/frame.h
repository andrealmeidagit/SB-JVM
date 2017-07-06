#ifndef FRAME_H_
#define FRAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "leitor.h"
#include "finder.h"
#include "conversions.h"

uint32_t FRAME_AMOUNT;

struct OperandInfo {
    uint32_t ispointer;
    uint32_t array_length;
    uint32_t data;
    struct OperandInfo *previous;
};
typedef struct OperandInfo OperandInfo;

struct Frame {
    MethodInfo* method_info;
    uint32_t pc;
    OperandInfo* operand_stack;
    uint32_t local_variable_count;
    OperandInfo* local_variables;
    uint16_t constant_pool_count;
    ConstantInfo* constant_pool;

    /*
    elementoListaArrays *listaArrays;
    elementoListaObjetos *listaObjetos;
    */

    struct Frame* previous;
};
typedef struct Frame Frame;

Frame* newFrame(ClassFile* class_file, MethodInfo* method_info, Frame* previous_frame);
void freeFrame(Frame* frame);

uint8_t getByteAt(Frame* frame, uint32_t index);

OperandInfo* newOperand(uint32_t data);
OperandInfo* newArrayOperand(uint32_t data, uint32_t array_length);
OperandInfo* dupOperand(OperandInfo* operand);
void copyOperand(OperandInfo* src, OperandInfo* dst);

void pushOperand(Frame* frame, OperandInfo* operand);
OperandInfo* popOperand(Frame* frame);

#endif /* FRAME_H_ */
