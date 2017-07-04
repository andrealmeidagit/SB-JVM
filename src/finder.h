#ifndef FINDER_H_
#define FINDER_H_

#include <string.h>
#include "leitor.h"

MethodInfo* findMethod(const char* method_name, ClassFile* class_file);
AttributeInfo* findCodeAttribute(const MethodInfo* method, const ConstantInfo* constant_pool);

#endif /* FINDER_H_ */
