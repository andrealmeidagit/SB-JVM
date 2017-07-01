#ifndef FINDER_H_
#define FINDER_H_

#include <string.h>
#include "leitor.h"

MethodInfo* findMethod(const char* method_name, ClassFile* class_file);

#endif /* FINDER_H_ */
