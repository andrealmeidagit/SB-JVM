/** @brief Inclusão da biblioteca de verificação de argumentos */
 
#include "argument_checks.h"

/**  Instrução de uso correto do programa e escolha do tipo de output */
static void showUsage() {
    printf("Uso: leitor_exibidor.exe <opcao de output> nome_da_classe_1.class nome_da_classe_2.class (...)\n");
    printf("<opcao de output> = '-a' ou '--arquivo' ou '-t' ou '--terminal'\n");
}

void validateArguments(int argc, char* argv[]) {
    checkArgumentAmount(argc);
    for (int i = 2; i < argc; ++i)
        checkFileExtension(argv[i]);
}

void checkArgumentAmount(int argc) {
    if (argc < 3) {
        fprintf(stderr, "[ERRO]: Quantidade invalida de argumentos.\n");
        showUsage();
        exit(EXIT_FAILURE);
    }
}

/** Checagem da extensão do arquivo. 
    @param[in] file_name Ponteiro do tipo char que aponta para o começo do arquivo.

*/
void checkFileExtension(char* file_name) {
    if (strstr(file_name, ".class") == NULL) {
        fprintf(stderr, "[ERRO]: O arquivo deve ter a extensao .class\n");
        showUsage();
        exit(EXIT_FAILURE);
    }
}

/** Escolha do tipo de Output definida pelo usuário. 
    @param[in] op Paramentro de escolha de tipo de Output: Terminal ou Arquivo.
*/
int checkOutputOption(char* op) {
    if (strcmp(op, "-a") == 0 || strcmp(op, "--arquivo") == 0)
        return 0;
    else if (strcmp(op, "-t") == 0 || strcmp(op, "--terminal") == 0)
        return 1;
    else {
        fprintf(stderr, "[ERRO]: Opcao de output invalida\n");
        exit(EXIT_FAILURE);
    }
}
