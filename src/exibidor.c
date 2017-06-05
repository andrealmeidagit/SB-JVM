#include "exibidor.h"

void showClassFile(FILE* stream, ClassFile class_file) {
    fprintf(stream, "Magic number: %#010x\n", class_file.magic);
    fprintf(stream, "Minor version: %u\n", class_file.minor_version);
    fprintf(stream, "Major version: %u\n", class_file.major_version);
    fprintf(stream, "Constant pool count: %u\n", class_file.constant_pool_count);
}
