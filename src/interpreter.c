#include "interpreter.h"

static uint8_t return_instr_opcode = 0xb1;

void runFrame(Frame* frame) {
    uint8_t current_opcode = findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[frame->pc];
    printf("\n\n**************\nCurrent opcode: %u\n", current_opcode);
    INSTRUCTION_ARRAY[current_opcode](frame);
    if (current_opcode != return_instr_opcode) {
        getchar();
        runFrame(frame);
    }
}
