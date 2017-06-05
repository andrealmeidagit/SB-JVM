#include "exibidor.h"

static void printAccessFlags(FILE* stream, uint16_t access_flags) {
    fprintf(stream, "Access flags: %#06x [ ", access_flags);
    if (access_flags & ACC_PUBLIC)
        fprintf(stream, "public ");
    if (access_flags & ACC_FINAL)
        fprintf(stream, "final ");
    if (access_flags & ACC_SUPER)
        fprintf(stream, "super ");
    if (access_flags & ACC_INTERFACE)
        fprintf(stream, "interface ");
    if (access_flags & ACC_ABSTRACT)
        fprintf(stream, "abstract ");
    if (access_flags & ACC_SYNTHETIC)
        fprintf(stream, "synthetic ");
    if (access_flags & ACC_ANNOTATION)
        fprintf(stream, "annotation ");
    if (access_flags & ACC_ENUM)
        fprintf(stream, "enum ");
    fprintf(stream, "]\n");
}

void showClassFile(FILE* stream, ClassFile class_file) {
    fprintf(stream, "Information:\n\n");
    fprintf(stream, "Magic number: %#010x\n", class_file.magic);
    fprintf(stream, "Minor version: %u\n", class_file.minor_version);
    fprintf(stream, "Major version: %u\n", class_file.major_version);
    fprintf(stream, "Constant pool count: %u\n", class_file.constant_pool_count);
    printAccessFlags(stream, class_file.access_flags);
}
