#include "argument_checks.h"
#include "leitor.h"
#include "exibidor.h"
#include "finder.h"
#include "frame.h"
#include "interpreter.h"
#include "instruction.h"

// #define __EXIBIDOR__
#define __JVM__

int main(int argc, char* argv[]) {
    ClassFile hello_world_class;
    checkArgumentAmount(argc);
    checkFileExtension(argv[1]);
    int output_to_terminal = checkOutputOption(argv[2]);
    hello_world_class = readClassFile(argv[1]);

#ifdef __EXIBIDOR__
    showClassFile(output_to_terminal ? stdout : fopen("output.txt", "w+"), &hello_world_class);
#endif

#ifdef __JVM__
    initInstructionArray();
    MethodInfo* main_method = findMethod("main", &hello_world_class);
    Frame* initial_frame = newFrame(&hello_world_class, main_method);
    runFrame(initial_frame);
#endif

    return 0;
}
