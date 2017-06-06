#include "argument_checks.h"
#include "leitor.h"
#include "exibidor.h"

int main(int argc, char* argv[]) {
    ClassFile hello_world_class;
    checkArgumentAmount(argc);
    checkFileExtension(argv[1]);
    int output_to_terminal = checkOutputOption(argv[2]);
    hello_world_class = readClassFile(argv[1]);
    showClassFile(output_to_terminal ? stdout : fopen("output.txt", "w+"), &hello_world_class);
    return 0;
}
