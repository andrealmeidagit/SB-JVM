/** @file main.c
 *  @brief Arquivo possui a inicialização da JVM.
 *   
 *  Este arquivo possui a função inicial de começo da JVM e do leitor-exibidor
 */
#include "argument_checks.h"
#include "leitor.h"
#include "exibidor.h"
#include "finder.h"
#include "frame.h"
#include "interpreter.h"
#include "instruction.h"

// #define __EXIBIDOR__
#define __JVM__

/** @brief Função de inicialização da JVM ou do leitor-exibidor
 *
 *  @param[in] argc
 *  @param[in] argv
 *
 *
 *  A função main checa a corretude do número de parâmetros recebidos e do tipo de arquivo recebido .class.
 *  Estando tudo correto, o programa carrega o .class em uma ClassFile
 *
 *  Caso o programa esteja no modo EXIBIDOR, a função exibe o .class chamando a função showClassFile.
 *  
 *  Caso o programa esteja no modo JVM, a função começa a execução
 */
int main(int argc, char* argv[]) {
    ClassFile input_class;
    checkArgumentAmount(argc);
    checkFileExtension(argv[1]);
    input_class = readClassFile(argv[1]);

#ifdef __EXIBIDOR__
    int output_to_terminal = checkOutputOption(argv[2]);
    showClassFile(output_to_terminal ? stdout : fopen("output.txt", "w+"), &input_class);
#endif

#ifdef __JVM__
    FRAME_AMOUNT = 0;
    initInstructionArray();
    MethodInfo* main_method = findMethod("main", &input_class);
    Frame* initial_frame = newFrame(&input_class, main_method, NULL);
    runFrame(initial_frame, &input_class, 1);
#endif

    return 0;
}
