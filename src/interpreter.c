#include "interpreter.h"

static uint8_t return_instr_opcode = 0xb1;

void runFrame(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint8_t current_opcode = findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[frame->pc];
    printf("\n\n**************\n(%u, %#04x): %s\n", current_opcode, current_opcode, OPCODE_ARRAY[current_opcode]);
    INSTRUCTION_ARRAY[current_opcode](frame, class_files, class_files_count);
    if (current_opcode != return_instr_opcode) {
        getchar();
        runFrame(frame, class_files, class_files_count);
    }
}
