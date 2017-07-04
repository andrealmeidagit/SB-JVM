#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include "leitor.h"
#include "frame.h"
#include "instruction.h"
#include "finder.h"
#include "opcode_array.h"

void runFrame(Frame* frame, ClassFile* class_files, int class_files_count);

#endif /* INTERPRETER_H_ */
