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

    ClassFile input_class;
    checkArgumentAmount(argc);
    checkFileExtension(argv[1]);

    /** Recebe o .class file */
    input_class = readClassFile(argv[1]);


    /** Exibição do arquivo .class se o código EXIBIDOR estiver definido. */

#ifdef __EXIBIDOR__
    int output_to_terminal = checkOutputOption(argv[2]);
    showClassFile(output_to_terminal ? stdout : fopen("output.txt", "w+"), &input_class);
#endif

    /** @brief Busca, Execução do Método e Criação de Frames recursivamente. */

#ifdef __JVM__
    FRAME_AMOUNT = 0;
    initInstructionArray();
    MethodInfo* main_method = findMethod("main", &input_class);
    Frame* initial_frame = newFrame(&input_class, main_method, NULL);
    runFrame(initial_frame, &input_class, 1);
#endif

    return 0;
}
