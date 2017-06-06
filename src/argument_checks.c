#include "argument_checks.h"

static void showUsage() {
    printf("Uso: leitor_exibidor.exe nome_da_classe.class <opcao de output>\n");
    printf("<opcao de output> = '-a' ou '--arquivo' ou '-t' ou '--terminal'\n");
}

void checkArgumentAmount(int argc) {
    if (argc != 3) {
        fprintf(stderr, "[ERRO]: Quantidade invalida de argumentos.\n");
        showUsage();
        exit(1);
    }
}

void checkFileExtension(char* file_name) {
    if (strstr(file_name, ".class") == NULL) {
        fprintf(stderr, "[ERRO]: O arquivo deve ter a extensao .class\n");
        showUsage();
        exit(1);
    }
}

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
