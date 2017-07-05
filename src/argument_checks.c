/** @brief Inclusão da biblioteca de verificação de argumentos */
 
#include "argument_checks.h"

/**  Instrução de uso correto do programa e escolha do tipo de output */
static void showUsage() {
    printf("Uso: leitor_exibidor.exe nome_da_classe.class <opcao de output>\n");
    printf("<opcao de output> = '-a' ou '--arquivo' ou '-t' ou '--terminal'\n");
}

/** Checagem do número de parametros
    @param[in] argc contador de argumentos.
       
*/
void checkArgumentAmount(int argc) {
    if (argc != 3) {
        /** Erro caso o número de parametros seja diferente de 3 */
        fprintf(stderr, "[ERRO]: Quantidade invalida de argumentos.\n");
        showUsage();
        exit(1);
    }
}

/** Checagem da extensão do arquivo. 
    @param[in] file_name Ponteiro do tipo char que aponta para o começo do arquivo.

*/
void checkFileExtension(char* file_name) {
    if (strstr(file_name, ".class") == NULL) {
        fprintf(stderr, "[ERRO]: O arquivo deve ter a extensao .class\n");
        showUsage();
        exit(1);
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
        exit(1);
    }
}
