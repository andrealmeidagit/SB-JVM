#include "interpreter.h"

void runFrame(Frame* frame) {
    uint8_t current_opcode;
    current_opcode = frame->method_info->attributes[0].u.Code.code[frame->pc];
    printf("**************\nCurrent opcode: %u\n", current_opcode);
    INSTRUCTION_ARRAY[current_opcode](frame);
    if (current_opcode != 0xb1)
        runFrame(frame);
    if (frame->previous != NULL)
        runFrame(frame->previous);
}
