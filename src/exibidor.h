#ifndef EXIBIDOR_H_
#define EXIBIDOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <locale.h>

#include "leitor.h"
#include "access_flags.h"
#include "opcode_array.h"
#include "conversions.h"

void showClassFile(FILE* stream, ClassFile* class_file);

#define NEWLINE(filestream) fprintf(filestream,"\n")

#endif
