#include "interpreter.h"

void runFrame(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint8_t verbose = 0;
    uint8_t current_opcode = findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[frame->pc];
    if (verbose)
        printf("\n**************\nFrame #%d: (%u, %#04x): %s\n", FRAME_AMOUNT, current_opcode, current_opcode, OPCODE_ARRAY[current_opcode]);
    INSTRUCTION_ARRAY[current_opcode](frame, class_files, class_files_count);
    if (!isOpcodeReturnStatement(current_opcode)) {
        if (verbose)
            getchar();
        runFrame(frame, class_files, class_files_count);
    }
}

int isOpcodeReturnStatement(uint8_t opcode) {
    uint8_t return_hexes[] = { 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1 };
    for (int i = 0; i < 6; ++i)
        if (opcode == return_hexes[i])
            return 1;
    return 0;
}
