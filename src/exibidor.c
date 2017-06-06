#include "exibidor.h"

static void printGeneralClassInformation(FILE* stream, ClassFile* class_file);
static void printConstantPool(FILE* stream, ClassFile* class_file);
static void printInterfaces(FILE* stream, ClassFile* class_file);
static void printFields(FILE* stream, ClassFile* class_file);
static void printMethods(FILE* stream, ClassFile* class_file);
static void printAttributes(FILE* stream, ClassFile* class_file);
static void printClassAccessFlags(FILE* stream, uint16_t access_flags);
static void printThisClassAndSuperClass(FILE* stream, ClassFile* class_file);
static void printClassName(FILE* stream, ClassFile* class_file, uint16_t index, char* msg);
static void printUTF8(FILE* stream, char* unicode);

static void printUTF8 (FILE* stream, char * unicode){
	setlocale (LC_ALL, "" );
    fprintf(stream, "%s", unicode);
    setlocale (LC_ALL, NULL );
}

static void print_from_index (FILE* stream, ClassFile* class_file, uint16_t index){
    printUTF8 (stream, (char *)class_file->constant_pool[index].CONSTANT.Utf8_info.bytes);   //imprime o texto UTF-8
}

void showClassFile(FILE* stream, ClassFile* class_file) {
    printGeneralClassInformation(stream, class_file);
    printConstantPool(stream, class_file);
    printInterfaces(stream, class_file);
    printFields(stream, class_file);
    printMethods(stream, class_file);
    printAttributes(stream, class_file);
}

static void printGeneralClassInformation(FILE* stream, ClassFile* class_file) {
    fprintf(stream, "*****************************\n* GENERAL CLASS INFORMATION *\n*****************************\n\n");
    fprintf(stream, "Magic number: %#010x\n", class_file->magic);
    fprintf(stream, "Minor version: %u\n", class_file->minor_version);
    fprintf(stream, "Major version: %u\n", class_file->major_version);
    fprintf(stream, "Constant pool count: %u\n", class_file->constant_pool_count);
    printClassAccessFlags(stream, class_file->access_flags);
    printThisClassAndSuperClass(stream, class_file);
    fprintf(stream, "Interfaces count: %u\n", class_file->interfaces_count);
    fprintf(stream, "Field count: %u\n", class_file->fields_count);
    fprintf(stream, "Method count: %u\n", class_file->methods_count);
    fprintf(stream, "Attribute count: %u\n", class_file->attributes_count);
}

static void printConstantPool(FILE* stream, ClassFile* class_file){
	uint16_t i;

	fprintf(stream, "\n*****************\n* CONSTANT POOL *\n*****************\n\n");

    for (i=0; i<class_file->constant_pool_count-1; i++){
    	fprintf(stream, "\n[%u] ", i+1);
    	switch (class_file->constant_pool[i].tag){
    		case Const_Utf8:    //tag 1
                fprintf(stream, "UTF-8:\t\t ");
    			printUTF8 (stream, (char *)class_file->constant_pool[i].CONSTANT.Utf8_info.bytes);   //imprime o texto UTF-8
                NEWLINE(stream);
    			break;
    		case Const_Int:     //tag3
    			fprintf(stream, "Integer:\t\t #%u\n", class_file->constant_pool[i].CONSTANT.Integer_info.bytes);
    			break;
    		case Const_Float:   //tag4
    			fprintf(stream, "Float:\t\t #%f\n", class_file->constant_pool[i].CONSTANT.Float_info.bytes);
    			break;
    		case Const_Long:   //tag5
    			fprintf(stream, "Long:\t\t #%u\t#%u\n", class_file->constant_pool[i].CONSTANT.Long_info.high_bytes, class_file->constant_pool[i].CONSTANT.Long_info.low_bytes);
                break;
            case Const_Double:   //tag5
    			fprintf(stream, "Double:\t\t \n\t- High Bytes:\t #%#010x\n\t- Low Bytes:\t #%#010x\n", class_file->constant_pool[i].CONSTANT.Double_info.high_bytes, class_file->constant_pool[i].CONSTANT.Double_info.low_bytes);
                break;
            case Const_Class:   //tag7
                fprintf(stream, "Class:\t\t #%u\t // ", class_file->constant_pool[i].CONSTANT.Class_info.name_index);
                print_from_index (stream, class_file, class_file->constant_pool[i].CONSTANT.Class_info.name_index);   //imprime o texto UTF-8 a partir do indice
                NEWLINE(stream);
                break;
            case Const_String:  //tag8
            	fprintf(stream, "String:\t\t #%u\n", class_file->constant_pool[i].CONSTANT.String_info.string_index);  //index da string
                print_from_index (stream, class_file, class_file->constant_pool[i].CONSTANT.String_info.string_index);   //imprime o texto UTF-8 a partir do indice
                NEWLINE(stream);
                break;
            case Const_FRef:    //tag9 - Field Reference
            	fprintf(stream, "Field Reference:\n\t- Class Index:\t #%u\t // ", class_file->constant_pool[i].CONSTANT.Fieldref_info.class_index); //indice
                print_from_index (stream, class_file, class_file->constant_pool[ class_file->constant_pool[i].CONSTANT.Fieldref_info.class_index ].CONSTANT.Class_info.name_index);   //imprime (field(classe(UTF-8)))
                fprintf(stream, "\n\t- Name and Type: #%u\t // name: ", class_file->constant_pool[i].CONSTANT.Fieldref_info.name_and_type_index); //indice
                print_from_index (stream, class_file, class_file->constant_pool[ class_file->constant_pool[i].CONSTANT.Fieldref_info.name_and_type_index ].CONSTANT.NameAndType_info.name_index);   //imprime (field(NameAndType(name(UTF-8))))
                fprintf(stream, "\t descriptor: ");
                print_from_index (stream, class_file, class_file->constant_pool[ class_file->constant_pool[i].CONSTANT.Fieldref_info.name_and_type_index ].CONSTANT.NameAndType_info.descriptor_index);   //imprime (field(NameAndType(descriptor(UTF-8))))
                NEWLINE(stream);
                break;
            case Const_MRef:    //tag10 - Method Reference
                fprintf(stream, "Method Reference:\n\t- Class Index:\t #%u", class_file->constant_pool[i].CONSTANT.Methodref_info.class_index); //indice
                print_from_index (stream, class_file, class_file->constant_pool[i].CONSTANT.Methodref_info.class_index);   //imprime o texto UTF-8 a partir do indice
                fprintf(stream, "\n\t- Name and Type: #%u\t // ", class_file->constant_pool[i].CONSTANT.Methodref_info.name_and_type_index); //indice
                print_from_index (stream, class_file, class_file->constant_pool[i].CONSTANT.Methodref_info.name_and_type_index);   //imprime o texto UTF-8 a partir do indice
                NEWLINE(stream);
                break;
            case Const_IRef:    //tag11 - Interface Method Reference
                fprintf(stream, "Interface Method Reference:\n\t- Class Index:\t #%u", class_file->constant_pool[i].CONSTANT.InterfaceMethodref_info.class_index); //indice
                print_from_index (stream, class_file, class_file->constant_pool[i].CONSTANT.InterfaceMethodref_info.class_index);   //imprime o texto UTF-8 a partir do indice
                fprintf(stream, "\n\t- Name and Type: #%u\t // ", class_file->constant_pool[i].CONSTANT.InterfaceMethodref_info.name_and_type_index); //indice
                print_from_index (stream, class_file, class_file->constant_pool[i].CONSTANT.InterfaceMethodref_info.name_and_type_index);   //imprime o texto UTF-8 a partir do indice
                NEWLINE(stream);
                break;
            case Const_NAT:     //tag12 - Name and Type
                fprintf(stream, "Name and Type:\n\t- Name Index:\t #%u", class_file->constant_pool[i].CONSTANT.NameAndType_info.name_index);    //indice
                //print_from_index (stream, class_file, class_file->constant_pool[i].CONSTANT.NameAndType_info.name_index);   //imprime o texto UTF-8 a partir do indice
                fprintf(stream, "\n\t- Descriptor:\t #%u\t // ", class_file->constant_pool[i].CONSTANT.NameAndType_info.descriptor_index); //indice
                //print_from_index (stream, class_file, class_file->constant_pool[i].CONSTANT.NameAndType_info.descriptor_index);   //imprime o texto UTF-8 a partir do indice
                NEWLINE(stream);
                break;
            case Const_MHand:   //tag15 - Method Handle
                fprintf(stream, "Method Handle:\n\t- Reference Kind:\t #%u\n\t- Reference Index:\t #%u\n", class_file->constant_pool[i].CONSTANT.MethodHandle_info.reference_kind, class_file->constant_pool[i].CONSTANT.MethodHandle_info.reference_index);
                break;
            case Const_MType:   //tag16 - Method Type
                fprintf(stream, "Method Type:\n\t- Descriptor:\t #%u\n", class_file->constant_pool[i].CONSTANT.MethodType_info.descriptor_index);
                break;
            case Const_InDyn:   //tag18 - Invoke Dynamic
                fprintf(stream, "Invoke Dynamic:\n\t- Bootstrap Method:\t #%u\n\t- Name and Type: #%u\n", class_file->constant_pool[i].CONSTANT.InvokeDynamic_info.bootstrap_method_attr_index, class_file->constant_pool[i].CONSTANT.InvokeDynamic_info.name_and_type_index);
                break;
    		default:
    			printf("ERRO DE LEITURA!!! %u\n", class_file->constant_pool[i].tag);
                exit(EXIT_FAILURE);
    	}
    }
	fprintf(stream, "\n");
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

static void printThisClassAndSuperClass(FILE* stream, ClassFile* class_file) {
	printClassName(stream, class_file, class_file->this_class, "This");
	printClassName(stream, class_file, class_file->super_class, "Super");
}

static void printClassName(FILE* stream, ClassFile* class_file, uint16_t index, char* msg) {
	CP_table* class_cp = class_file->constant_pool + index - 1;
	fprintf(stream, "%s class: #%u ", msg, index);
	char* this_class = (char*)class_file->constant_pool[class_cp->CONSTANT.Class_info.name_index - 1].CONSTANT.Utf8_info.bytes;
	printUTF8(stream, this_class);
	fprintf(stream, "\n");
}

static void printInterfaces(FILE* stream, ClassFile* class_file) {
    fprintf(stream, "**************\n* Interfaces *\n**************\n\n");
    fprintf(stream, "Interface count: %u\n", class_file->interfaces_count);
    if (class_file->interfaces_count > 0) {
        fprintf(stream, "[ ");
        for (uint16_t i = 0; i < class_file->interfaces_count; ++i)
            fprintf(stream, "%#06x ", *(class_file->interfaces + i));
        fprintf(stream, "]\n");
    }
	fprintf(stream, "\n");
}

static void printFields(FILE* stream, ClassFile* class_file) {
	fprintf(stream, "**********\n* Fields *\n**********\n");
    fprintf(stream, "Field count: %u\n", class_file->fields_count);
	fprintf(stream, "\n");
}

static void printMethods(FILE* stream, ClassFile* class_file) {
	fprintf(stream, "***********\n* Methods *\n***********\n");
	fprintf(stream, "Method count: %u\n", class_file->methods_count);
	// uint16_t i = 0;
	// for(MethodInfo* it = class_file->methods; it < class_file->methods + class_file->methods_count; ++it) {
	// 	fprintf(stream, "[%u] %u", i++, it->name_index);
	// }
	// fprintf(stream, "\n");
}

static void printAttributes(FILE* stream, ClassFile* class_file) {
	fprintf(stream, "**************\n* Attributes *\n**************\n");
    fprintf(stream, "Attributes:\n\n");
    fprintf(stream, "Attribute count: %u\n", class_file->attributes_count);
}
