#ifndef ARGUMENT_CHECKS_H_
#define ARGUMENT_CHECKS_H_

/** @brief Inclusão de bibliotecas e Declaração de funções de verificação.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void validateArguments(int argc, char* argv[]);
void checkArgumentAmount(int argc);
void checkFileExtension(char* file_name);
int checkOutputOption(char* op);

#endif /* ARGUMENT_CHECKS_H_ */
