#ifndef CONST_POOL_H_
#define CONST_POOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <locale.h>

#include "access_flags.h"
#include "opcode_array.h"
#include "frame.h"


void printConstantFF(Frame* frame, uint16_t index);
void print_from_index (Frame* frame, uint16_t index);
void printUTF8(char* unicode);
#endif
