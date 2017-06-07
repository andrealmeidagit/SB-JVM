#include "exibidor.h"

static void printDivisoryLine(FILE* stream);
static void printGeneralClassInformation(FILE* stream, ClassFile* class_file);
static void printConstantPool(FILE* stream, ClassFile* class_file);
static void printInterfaces(FILE* stream, ClassFile* class_file);
static void printFields(FILE* stream, ClassFile* class_file);
static void printMethods(FILE* stream, ClassFile* class_file);
static void printAttributes(FILE* stream, ClassFile* class_file);
static void printClassAccessFlags(FILE* stream, uint16_t access_flags);

static void printUTF8 (FILE* stream, char * unicode){
	setlocale (LC_ALL, "" );
    fprintf(stream, "%s", unicode);
  setlocale (LC_ALL, NULL );
}

static void print_from_index (FILE* stream, ClassFile* class_file, uint16_t index){
    printUTF8 (stream, (char *)class_file->constant_pool[index].CONSTANT.Utf8_info.bytes);   //imprime o texto UTF-8
}

void showClassFile(FILE* stream, ClassFile* class_file) {
    printDivisoryLine(stream);
    printGeneralClassInformation(stream, class_file);
    printDivisoryLine(stream);
    printConstantPool(stream, class_file);
    printDivisoryLine(stream);
    printInterfaces(stream, class_file);
    printDivisoryLine(stream);
    printFields(stream, class_file);
    printDivisoryLine(stream);
    printMethods(stream, class_file);
    printDivisoryLine(stream);
    printAttributes(stream, class_file);
    printDivisoryLine(stream);
}

static void printDivisoryLine(FILE* stream) {
    for (uint8_t i = 0; i < 80; ++i)
        fprintf(stream, "=");
    fprintf(stream, "\n");
}

static void printGeneralClassInformation(FILE* stream, ClassFile* class_file) {
    fprintf(stream, "General Information:\n\n");
    fprintf(stream, "Magic number: %#010x\n", class_file->magic);
    fprintf(stream, "Minor version: %u\n", class_file->minor_version);
    fprintf(stream, "Major version: %u\n", class_file->major_version);
    fprintf(stream, "Constant pool count: %u\n", class_file->constant_pool_count);
    printClassAccessFlags(stream, class_file->access_flags);
    fprintf(stream, "This class: %u\n", class_file->this_class);
    fprintf(stream, "Super class: %u\n", class_file->super_class);
    fprintf(stream, "Interfaces count: %u\n", class_file->interfaces_count);
    fprintf(stream, "Field count: %u\n", class_file->fields_count);
    fprintf(stream, "Method count: %u\n", class_file->methods_count);
    fprintf(stream, "Attribute count: %u\n", class_file->attributes_count);
}

static void printConstantPool(FILE* stream, ClassFile* class_file){
	uint16_t i;
	fprintf(stream, "\n*****************\n* CONSTANT POOL *\n*****************\n\n");
    for (i=0; i<class_file->constant_pool_count-1; i++){
			CP_table * p = class_file->constant_pool + i;
    	fprintf(stream, "\n[%u] ", i+1);
    	switch (p->tag){
    		case Const_Utf8:    //tag 1
          fprintf(stream, "UTF-8:\t\t ");
    			printUTF8 (stream, (char *)p->CONSTANT.Utf8_info.bytes);   //imprime o texto UTF-8
          NEWLINE(stream);
    			break;
    		case Const_Int:     //tag3
    			fprintf(stream, "Integer:\t\t #%u\n", p->CONSTANT.Integer_info.bytes);
    			break;
    		case Const_Float:   //tag4
    			fprintf(stream, "Float:\t\t #%f\n", p->CONSTANT.Float_info.bytes);
    			break;
    		case Const_Long:   //tag5
    			fprintf(stream, "Long:\t\t #%u\t#%u\n", p->CONSTANT.Long_info.high_bytes, p->CONSTANT.Long_info.low_bytes);
          break;
        case Const_Double:   //tag5
    			fprintf(stream, "Double:\t\t \n\t- High Bytes:\t #%#010x\n\t- Low Bytes:\t #%#010x\n", p->CONSTANT.Double_info.high_bytes, p->CONSTANT.Double_info.low_bytes);
          break;
        case Const_Class:   //tag7
          fprintf(stream, "Class:\t\t #%u\t // ", p->CONSTANT.Class_info.name_index);
          print_from_index (stream, class_file, p->CONSTANT.Class_info.name_index -1);   //imprime o texto UTF-8 a partir do indice
          NEWLINE(stream);
          break;
        case Const_String:  //tag8
          fprintf(stream, "String:\t\t #%u\n", p->CONSTANT.String_info.string_index);  //index da string
          print_from_index (stream, class_file, p->CONSTANT.String_info.string_index);   //imprime o texto UTF-8 a partir do indice
          NEWLINE(stream);
          break;
        case Const_FRef:    //tag9 - Field Reference
          fprintf(stream, "Field Reference:\n\t- Class Index:\t #%u\t // ", p->CONSTANT.Fieldref_info.class_index); //indice
          print_from_index (stream, class_file, class_file->constant_pool[ p->CONSTANT.Fieldref_info.class_index -1 ].CONSTANT.Class_info.name_index -1);   //imprime (field(classe(UTF-8)))
					fprintf(stream, "\n\t- Name and Type: #%u\t // name: ", p->CONSTANT.Fieldref_info.name_and_type_index); //indice
          print_from_index (stream, class_file, class_file->constant_pool[ p->CONSTANT.Fieldref_info.name_and_type_index -1].CONSTANT.NameAndType_info.name_index -1);   //imprime (field(NameAndType(name(UTF-8))))
          fprintf(stream, "\t descriptor: ");
          print_from_index (stream, class_file, class_file->constant_pool[ p->CONSTANT.Fieldref_info.name_and_type_index -1].CONSTANT.NameAndType_info.descriptor_index -1);   //imprime (field(NameAndType(descriptor(UTF-8))))
          NEWLINE(stream);
          break;
        case Const_MRef:    //tag10 - Method Reference
          fprintf(stream, "Method Reference:\n\t- Class Index:\t #%u\t //\t", p->CONSTANT.Methodref_info.class_index); //indice
          print_from_index (stream, class_file, class_file->constant_pool[ p->CONSTANT.Methodref_info.class_index -1].CONSTANT.Class_info.name_index -1);   //imprime (field(class(name(UTF-8))))
					fprintf(stream, "\n\t- Name and Type: #%u\t //\tname: ", p->CONSTANT.Methodref_info.name_and_type_index); //indice
					print_from_index (stream, class_file, class_file->constant_pool[ p->CONSTANT.Methodref_info.name_and_type_index -1].CONSTANT.NameAndType_info.name_index -1);   //imprime (field(NameAndType(name(UTF-8))))
					fprintf(stream, "\t descriptor: ");
					print_from_index (stream, class_file, class_file->constant_pool[ p->CONSTANT.Methodref_info.name_and_type_index -1].CONSTANT.NameAndType_info.descriptor_index -1);   //imprime (field(NameAndType(descriptor(UTF-8))))
					NEWLINE(stream);
          break;
        case Const_IRef:    //tag11 - Interface Method Reference
          fprintf(stream, "Interface Method Reference:\n\t- Class Index:\t #%u", p->CONSTANT.InterfaceMethodref_info.class_index); //indice
					print_from_index (stream, class_file, class_file->constant_pool[ p->CONSTANT.InterfaceMethodref_info.class_index -1].CONSTANT.Class_info.name_index -1);   //imprime (field(class(name(UTF-8))))
					fprintf(stream, "\n\t- Name and Type: #%u\t //\tname: ", p->CONSTANT.InterfaceMethodref_info.name_and_type_index); //indice
					print_from_index (stream, class_file, class_file->constant_pool[ p->CONSTANT.InterfaceMethodref_info.name_and_type_index -1].CONSTANT.NameAndType_info.name_index -1);   //imprime (field(NameAndType(name(UTF-8))))
					fprintf(stream, "\t descriptor: ");
					print_from_index (stream, class_file, class_file->constant_pool[ p->CONSTANT.InterfaceMethodref_info.name_and_type_index -1].CONSTANT.NameAndType_info.descriptor_index -1);   //imprime (field(NameAndType(descriptor(UTF-8))))
					NEWLINE(stream);
          break;
        case Const_NAT:     //tag12 - Name and Type
          fprintf(stream, "Name and Type:\n\t- Name Index:\t #%u\t // ", p->CONSTANT.NameAndType_info.name_index);    //indice
          print_from_index (stream, class_file, p->CONSTANT.NameAndType_info.name_index -1);   //imprime (Name and Type(name(UTF-8)))
          fprintf(stream, "\n\t- Descriptor:\t #%u\t // ", p->CONSTANT.NameAndType_info.descriptor_index); //indice
          print_from_index (stream, class_file, p->CONSTANT.NameAndType_info.descriptor_index -1);   //imprime (Name and Type(descriptor(UTF-8)))
          NEWLINE(stream);
          break;
        case Const_MHand:   //tag15 - Method Handle
/**/      fprintf(stream, "Method Handle:\n\t- Reference Kind:\t #%u\n\t- Reference Index:\t #%u\n", p->CONSTANT.MethodHandle_info.reference_kind, p->CONSTANT.MethodHandle_info.reference_index);
          break;
        case Const_MType:   //tag16 - Method Type
          fprintf(stream, "Method Type:\n\t- Descriptor:\t #%u\t // ", p->CONSTANT.MethodType_info.descriptor_index);
          print_from_index (stream, class_file, p->CONSTANT.MethodType_info.descriptor_index -1);   //imprime (method type(descriptor(UTF-8)))
          NEWLINE(stream);
          break;
        case Const_InDyn:   //tag18 - Invoke Dynamic
/**/      fprintf(stream, "Invoke Dynamic:\n\t- Bootstrap Method:\t #%u\n\t- Name and Type: #%u\n", p->CONSTANT.InvokeDynamic_info.bootstrap_method_attr_index, class_file->constant_pool[i].CONSTANT.InvokeDynamic_info.name_and_type_index);
          break;
    		default:
    			printf("ERRO DE LEITURA!!! %u\n", p->tag);
          exit(EXIT_FAILURE);
    	}
    }
    fprintf(stream, "\n**********\n* END CP *\n**********\n\n");
}

static void printClassAccessFlags(FILE* stream, uint16_t access_flags) {
    fprintf(stream, "Access flags: %#06x [ ", access_flags);
    if (access_flags & ACC_PUBLIC)
        fprintf(stream, "public ");
    if (access_flags & ACC_FINAL)
        fprintf(stream, "final ");
    if (access_flags & ACC_SUPER)
        fprintf(stream, "super ");
    if (access_flags & ACC_INTERFACE)
        fprintf(stream, "interface ");
    if (access_flags & ACC_ABSTRACT)
        fprintf(stream, "abstract ");
    if (access_flags & ACC_SYNTHETIC)
        fprintf(stream, "synthetic ");
    if (access_flags & ACC_ANNOTATION)
        fprintf(stream, "annotation ");
    if (access_flags & ACC_ENUM)
        fprintf(stream, "enum ");
    fprintf(stream, "]\n");
}

static void printInterfaces(FILE* stream, ClassFile* class_file) {
    fprintf(stream, "Interfaces:\n\n");
    fprintf(stream, "Interface count: %u\n", class_file->interfaces_count);
    if (class_file->interfaces_count > 0) {
        fprintf(stream, "[ ");
        for (uint16_t i = 0; i < class_file->interfaces_count; ++i)
            fprintf(stream, "%#06x ", *(class_file->interfaces + i));
        fprintf(stream, "]\n");
    }
}

static void printFields(FILE* stream, ClassFile* class_file) {
    fprintf(stream, "Fields:\n\n");
    fprintf(stream, "Field count: %u\n", class_file->fields_count);
}

static void printMethods(FILE* stream, ClassFile* class_file) {
    fprintf(stream, "Methods:\n\n");
    fprintf(stream, "Method count: %u\n", class_file->methods_count);
}

static void printAttributes(FILE* stream, ClassFile* class_file) {
    fprintf(stream, "Attributes:\n\n");
    fprintf(stream, "Attribute count: %u\n", class_file->attributes_count);
}
