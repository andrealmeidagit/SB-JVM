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
    validateArguments(argc, argv);

    ClassFile input_classes[argc-2];
    for(int i = 2, k = 0; i < argc; ++i, ++k)
        input_classes[k] = readClassFile(argv[i]);

#ifdef __EXIBIDOR__
    int output_to_terminal = checkOutputOption(argv[1]);
    FILE *fp = NULL;
    if (output_to_terminal)
        fp = fopen("output.txt", "w+");
    for (int i = 0; i < argc-2; ++i)
        showClassFile(output_to_terminal ? stdout : fp, &(input_classes[i]));
#endif

#ifdef __JVM__
    FRAME_AMOUNT = 0;
    initInstructionArray();
    MethodInfo* main_method = NULL;
    for (int i = 0; i < argc-2; ++i) {
         main_method = findMethod("main", input_classes + i);
         if (main_method != NULL) break;
     }
    Frame* initial_frame = newFrame(input_classes, main_method, NULL);
    runFrame(initial_frame, input_classes, argc-2);
#endif

    return 0;
}
