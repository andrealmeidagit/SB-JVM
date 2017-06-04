#include "exibidor.h"

void showClassFile(FILE* stream, ClassFile class_file) {
    fprintf(stream, "Magic number: %#010x\n", class_file.magic);
}
