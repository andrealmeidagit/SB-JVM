#include "argument_checks.h"
#include "leitor.h"

int main(int argc, char* argv[]) {
    ClassFile hello_world_class;

    checkArgumentAmount(argc);
    checkFileExtension(argv[1]);
    hello_world_class = readClassFile(argv[1]);
    return 0;
}
