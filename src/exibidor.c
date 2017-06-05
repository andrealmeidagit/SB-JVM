#include "exibidor.h"

static void printDivisoryLine(FILE* stream);
static void printGeneralClassInformation(FILE* stream, ClassFile* class_file);
static void printConstantPool(FILE* stream, ClassFile* class_file);
static void printInterfaces(FILE* stream, ClassFile* class_file);
static void printFields(FILE* stream, ClassFile* class_file);
static void printMethods(FILE* stream, ClassFile* class_file);
static void printAttributes(FILE* stream, ClassFile* class_file);
static void printClassAccessFlags(FILE* stream, uint16_t access_flags);

void showClassFile(FILE* stream, ClassFile* class_file) {
    printDivisoryLine(stream);
    printGeneralClassInformation(stream, class_file);
    printDivisoryLine(stream);
    printConstantPool(stream, class_file);
    printDivisoryLine(stream);
    printInterfaces(stream, class_file);
    printDivisoryLine(stream);
    printFields(stream, class_file);
    printDivisoryLine(stream);
    printMethods(stream, class_file);
    printDivisoryLine(stream);
    printAttributes(stream, class_file);
    printDivisoryLine(stream);
}

static void printDivisoryLine(FILE* stream) {
    for (uint8_t i = 0; i < 80; ++i)
        fprintf(stream, "=");
    fprintf(stream, "\n");
}

static void printGeneralClassInformation(FILE* stream, ClassFile* class_file) {
    fprintf(stream, "General Information:\n\n");
    fprintf(stream, "Magic number: %#010x\n", class_file->magic);
    fprintf(stream, "Minor version: %u\n", class_file->minor_version);
    fprintf(stream, "Major version: %u\n", class_file->major_version);
    fprintf(stream, "Constant pool count: %u\n", class_file->constant_pool_count);
    printClassAccessFlags(stream, class_file->access_flags);
    fprintf(stream, "This class: %u\n", class_file->this_class);
    fprintf(stream, "Super class: %u\n", class_file->super_class);
    fprintf(stream, "Interfaces count: %u\n", class_file->interfaces_count);
    fprintf(stream, "Field count: %u\n", class_file->fields_count);
    fprintf(stream, "Method count: %u\n", class_file->methods_count);
    fprintf(stream, "Attribute count: %u\n", class_file->attributes_count);
}

static void printClassAccessFlags(FILE* stream, uint16_t access_flags) {
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

static void printConstantPool(FILE* stream, ClassFile* class_file) {
    fprintf(stream, "Constant pool:\n\n");
}

static void printInterfaces(FILE* stream, ClassFile* class_file) {
    fprintf(stream, "Interfaces:\n\n");
    fprintf(stream, "Interface count: %u\n", class_file->interfaces_count);
    if (class_file->interfaces_count > 0) {
        fprintf(stream, "[ ");
        for (uint16_t i = 0; i < class_file->interfaces_count; ++i)
            fprintf(stream, "%#06x", *(class_file->interfaces + i));
        fprintf(stream, "]\n");
    }
}

static void printFields(FILE* stream, ClassFile* class_file) {
    fprintf(stream, "Fields:\n\n");
    fprintf(stream, "Field count: %u\n", class_file->fields_count);
}

static void printMethods(FILE* stream, ClassFile* class_file) {
    fprintf(stream, "Methods:\n\n");
    fprintf(stream, "Method count: %u\n", class_file->methods_count);
}

static void printAttributes(FILE* stream, ClassFile* class_file) {
    fprintf(stream, "Attributes:\n\n");
    fprintf(stream, "Attribute count: %u\n", class_file->attributes_count);
}
