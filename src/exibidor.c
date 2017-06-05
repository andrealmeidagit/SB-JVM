#include "exibidor.h"

void showClassFile(FILE* stream, ClassFile class_file) {
    fprintf(stream, "Magic number:\t 0x%x\n", class_file.magic);
    fprintf(stream, "Minor Version:\t %u\n", class_file.minor_version);
    fprintf(stream, "Major Version:\t %u\n", class_file.major_version);
}
