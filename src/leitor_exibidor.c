#include "argument_checks.h"
#include "leitor.h"
#include "exibidor.h"

int main(int argc, char* argv[]) {
    ClassFile hello_world_class;
    char output_mode = 't';

    checkArgumentAmount(argc);
    checkFileExtension(argv[1]);
    hello_world_class = readClassFile(argv[1]);
    showClassFile(output_mode=='t' ? stdout : fopen("output.txt", "r"), hello_world_class);
    return 0;
}
