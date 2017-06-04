#include "leitor.h"

static uint8_t readByte(FILE* fp) {
    uint8_t byte;
    fread(&byte, 1, 1, fp);
    return byte;
}

static void readMagicNumber(ClassFile* class_file, FILE* fp_class_file) {
    class_file->magic = readByte(fp_class_file);
    class_file->magic = (class_file->magic << 8) | readByte(fp_class_file);
    class_file->magic = (class_file->magic << 8) | readByte(fp_class_file);
    class_file->magic = (class_file->magic << 8) | readByte(fp_class_file);
}

ClassFile readClassFile(char* file_name) {
    FILE *fp_class_file;
    ClassFile class_file;
    fp_class_file = fopen(file_name, "rb");
    readMagicNumber(&class_file, fp_class_file);
    return class_file;
}
