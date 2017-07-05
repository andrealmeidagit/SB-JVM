/*
Universidade de Brasília - 01/2017
Software Básico - Turma A
Projeto Java Virtual Machine

Alunos: 		Gabriel Naves da Silva 				12/0011867
				Fernando Lucchesi Alencar 			11/0060571
				Filipe Pereira Fortes 				09/0113799
				André Abreu Rodrigues de Almeida	12/0007100
				Ricardo Hideki Ito 					12/0045818
*/

/**
 * @file main.c
 * @brief Execução do programa pela função 'main'.
 */

/** Inclusão de bibliotecas para checagem de argumentos, leitura do arquivo .class em bytecode, exibição dos
campos do bytecode, criação de frames, implementação de instruções.
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

	/** Verificação do arquivo .class. Checa quantidade de parametros, extensão do arquivo. 	*/

    validateArguments(argc, argv);

    ClassFile input_classes[argc-2];
    for(int i = 2, k = 0; i < argc; ++i, ++k)
        input_classes[k] = readClassFile(argv[i]);


    /** Exibição do arquivo .class se o código EXIBIDOR estiver definido. */

#ifdef __EXIBIDOR__
    int output_to_terminal = checkOutputOption(argv[1]);
    FILE *fp = NULL;
    if (output_to_terminal)
        fp = fopen("output.txt", "w+");
    for (int i = 0; i < argc-2; ++i)
        showClassFile(output_to_terminal ? stdout : fp, &(input_classes[i]));
#endif

    /** @brief Busca, Execução do Método e Criação de Frames recursivamente. */

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
