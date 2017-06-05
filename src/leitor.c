#include "leitor.h"

static uint8_t readByte(FILE* fp) {
    uint8_t byte;
    fread(&byte, 1, 1, fp);
    return byte;
}

static uint16_t read2Byte(FILE* fp) {
    uint16_t byte2;
    byte2 = readByte(fp);
    byte2 = (byte2 << 8) | readByte(fp);
    return byte2;
}

static uint32_t read4Byte(FILE* fp) {
    uint32_t byte4;
    byte4 = read2Byte(fp);
    byte4 = (byte4 << 16) | read2Byte(fp);
    return byte4;
}

ClassFile readClassFile(char* file_name) {
    FILE *fp_class_file;
    ClassFile class_file;
    fp_class_file = fopen(file_name, "rb");

    class_file.magic = read4Byte(fp_class_file);
    class_file.minor_version = read2Byte(fp_class_file);
    class_file.major_version = read2Byte(fp_class_file);
    class_file.constant_pool_count = read2Byte(fp_class_file);
    /* Read constant pool */
    return class_file;
}
