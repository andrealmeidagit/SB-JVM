#include "frame.h"

Frame* newFrame(ClassFile* class_file, MethodInfo* method_info, Frame* previous_frame) {
    Frame* frame = (Frame*)malloc(sizeof(Frame));
    frame->method_info = method_info;
    frame->pc = 0;
    frame->operand_stack = NULL;
    /* TODO: ver se o atributo CODE eh sempre zero mesmo */
    frame->local_variable_count = findCodeAttribute(method_info, class_file->constant_pool)->u.Code.max_locals;
    frame->local_variables = (OperandInfo*)malloc(frame->local_variable_count * sizeof(OperandInfo));
    frame->constant_pool_count = class_file->constant_pool_count;
    frame->constant_pool = class_file->constant_pool;
    frame->previous = previous_frame;
    FRAME_AMOUNT++;
    return frame;
}

void freeFrame(Frame* frame) {
    free(frame->local_variables);
    free(frame);
    FRAME_AMOUNT--;
}

void pushOperand(Frame* frame, OperandInfo* operand) {
    operand->previous = frame->operand_stack;
    frame->operand_stack = operand;
}

OperandInfo* popOperand(Frame* frame) {
    OperandInfo* removed = frame->operand_stack;
    frame->operand_stack = removed->previous;
    return removed;
}

OperandInfo* newOperand(uint32_t data){
    OperandInfo* operand = (OperandInfo*)malloc(sizeof(OperandInfo));
    operand->data = data;
    operand->ispointer = 0;
    operand->array_length = 0;
    operand->previous = NULL;
    return operand;
}

OperandInfo* newArrayOperand(uint32_t data, uint32_t array_length) {
    OperandInfo* operand = (OperandInfo*)malloc(sizeof(OperandInfo));
    operand->data = data;
    operand->ispointer = 1;
    operand->array_length = array_length;
    operand->previous = NULL;
    return operand;
}

OperandInfo* dupOperand(OperandInfo* operand) {
    OperandInfo* op = (OperandInfo*)malloc(sizeof(OperandInfo));
    op->data = operand->data;
    op->ispointer = operand->ispointer;
    op->array_length = operand->array_length;
    op->previous = NULL;
    return op;
}

void copyOperand(OperandInfo* src, OperandInfo* dst) {
    dst->data = src->data;
    dst->ispointer = src->ispointer;
    dst->array_length = src->array_length;
}

uint8_t getByteAt(Frame* frame, uint32_t index){
    return findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[index];
}
