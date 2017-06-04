#include "argument_checks.h"

static void showUsage() {
    printf("Uso: leitor_exibidor.exe nome_da_classe.class\n");
}

void checkArgumentAmount(int argc) {
    if (argc != 2) {
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
