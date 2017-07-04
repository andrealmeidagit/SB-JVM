#include "frame.h"

Frame* newFrame(ClassFile* class_file, MethodInfo* method_info, Frame* previous_frame) {
    Frame* frame = (Frame*)malloc(sizeof(Frame));
    frame->method_info = method_info;
    frame->pc = 0;
    frame->operand_stack = NULL;
    /* TODO: ver se o atributo CODE eh sempre zero mesmo */
    frame->local_variable_count = findCodeAttribute(method_info, class_file->constant_pool)->u.Code.max_locals;
    frame->local_variables = (uint32_t*)malloc(frame->local_variable_count * sizeof(uint32_t));
    frame->constant_pool_count = class_file->constant_pool_count;
    frame->constant_pool = class_file->constant_pool;
    frame->previous = previous_frame;
    FRAME_AMOUNT++;
    return frame;
}

void freeFrame(Frame* frame) {
    free(frame->local_variables);
    while (frame->operand_stack != NULL) {
        OperandInfo* op = popOperand(frame);
        free(op);
    }
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
    OperandInfo *operand = (OperandInfo*)malloc(sizeof(OperandInfo));
    operand->data = data;
    operand->previous = NULL;
    return operand;
}

uint8_t getByteAt(Frame* frame, uint32_t index){
    return findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[index];
}
