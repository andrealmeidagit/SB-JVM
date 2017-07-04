#ifndef FINDER_H_
#define FINDER_H_

#include <string.h>
#include "leitor.h"

MethodInfo* findMethod(const char* method_name, ClassFile* class_file);
MethodInfo* findMethodWithDesc(const char* method_name, const char* method_descriptor, ClassFile* class_file);
AttributeInfo* findCodeAttribute(const MethodInfo* method, const ConstantInfo* constant_pool);
ClassFile* findClassFile(char* class_name, ClassFile* class_files, uint16_t class_files_count);

#endif /* FINDER_H_ */
