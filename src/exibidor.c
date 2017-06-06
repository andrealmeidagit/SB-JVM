#include "exibidor.h"

static void printDivisoryLine(FILE* stream);
static void printGeneralClassInformation(FILE* stream, ClassFile* class_file);
static void printConstantPool(FILE* stream, ClassFile* class_file);
static void printInterfaces(FILE* stream, ClassFile* class_file);
static void printFields(FILE* stream, ClassFile* class_file);
static void printMethods(FILE* stream, ClassFile* class_file);
static void printAttributes(FILE* stream, ClassFile* class_file);
static void printClassAccessFlags(FILE* stream, uint16_t access_flags);

void printUTF8 (FILE* stream, char * unicode){
	setlocale (LC_ALL, "" );
    fprintf(stream, "Constant UTF-8:\t %s\n", unicode);
    setlocale (LC_ALL, NULL );
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
    	fprintf(stream, "[%d]	", i+1);
    	switch (class_file->constant_pool[i].tag){
    		case Const_Utf8:    //tag 1
    				printUTF8 (stream, (char *)class_file->constant_pool[i].CONSTANT.Utf8_info.bytes);
    			break;
    		case Const_Int:     //tag3
    			fprintf(stream, "Constant Integer:\t %"PRIu32"\n", class_file->constant_pool[i].CONSTANT.Integer_info.bytes);
    			break;
    		case Const_Float:   //tag4
    			fprintf(stream, "Constant Float:\t %"PRIu32"\n", class_file->constant_pool[i].CONSTANT.Float_info.bytes);
    			break;
    		case Const_Long:   //tag5
    			fprintf(stream, "Constant Long:\t 0x%"PRIx32"%"PRIx32"\n", class_file->constant_pool[i].CONSTANT.Long_info.high_bytes, class_file->constant_pool[i].CONSTANT.Long_info.low_bytes);
                break;
            case Const_Double:   //tag5
    			fprintf(stream, "Constant Double:\t 0x%"PRIx32"%"PRIx32"\n", class_file->constant_pool[i].CONSTANT.Double_info.high_bytes, class_file->constant_pool[i].CONSTANT.Double_info.low_bytes);
                break;
            case Const_Class:   //tag7
                fprintf(stream, "Constant Class Pointer:\t 0x%"PRIx16"\n", class_file->constant_pool[i].CONSTANT.Class_info.name_index);
                break;
            case Const_String:  //tag8
            	fprintf(stream, "Constant String:\t 0x%"PRIx16"\n", class_file->constant_pool[i].CONSTANT.String_info.string_index);
                break;
            case Const_FRef:    //tag9 - Field Reference
            	fprintf(stream, "Constant Field Reference:\n\t- Class Index:\t 0x%"PRIx16"\n\t- Name and Type:\t 0x%"PRIx16"\n", class_file->constant_pool[i].CONSTANT.Fieldref_info.class_index, class_file->constant_pool[i].CONSTANT.Fieldref_info.name_and_type_index);
                break;
            case Const_MRef:    //tag10 - Method Reference
                fprintf(stream, "Constant Method Reference:\n\t- Class Index:\t 0x%"PRIx16"\n\t- Name and Type:\t 0x%"PRIx16"\n", class_file->constant_pool[i].CONSTANT.Methodref_info.class_index, class_file->constant_pool[i].CONSTANT.Methodref_info.name_and_type_index);
                break;
            case Const_IRef:    //tag11 - Interface Method Reference
                fprintf(stream, "Constant Interface Method Reference:\n\t- Class Index:\t 0x%"PRIx16"\n\t- Name and Type:\t 0x%"PRIx16"\n", class_file->constant_pool[i].CONSTANT.InterfaceMethodref_info.class_index, class_file->constant_pool[i].CONSTANT.InterfaceMethodref_info.name_and_type_index);
                break;

            case Const_NAT:     //tag12 - Name and Type
                fprintf(stream, "Constant Name and Type:\n\t- Name Index:\t 0x%"PRIx16"\n\t- Descriptor:\t 0x%"PRIx16"\n", class_file->constant_pool[i].CONSTANT.NameAndType_info.name_index, class_file->constant_pool[i].CONSTANT.NameAndType_info.descriptor_index);
                break;

            case Const_MHand:   //tag15 - Method Handle
                fprintf(stream, "Constant Method Handle:\n\t- Reference Kind:\t %"PRIu8"\n\t- Reference Index:\t 0x%"PRIx16"\n", class_file->constant_pool[i].CONSTANT.MethodHandle_info.reference_kind, class_file->constant_pool[i].CONSTANT.MethodHandle_info.reference_index);
                break;

            case Const_MType:   //tag16 - Method Type
                fprintf(stream, "Constant Method Type:\n\t- Descriptor:\t 0x%"PRIx16"\n", class_file->constant_pool[i].CONSTANT.MethodType_info.descriptor_index);
                break;

            case Const_InDyn:   //tag18 - Invoke Dynamic
                fprintf(stream, "Constant Invoke Dynamic:\n\t- Bootstrap Method:\t 0x%"PRIx16"\n\t- Name and Type:\t 0x%"PRIx16"\n", class_file->constant_pool[i].CONSTANT.InvokeDynamic_info.bootstrap_method_attr_index, class_file->constant_pool[i].CONSTANT.InvokeDynamic_info.name_and_type_index);
                break;
    		default:
    			printf("ERRO DE LEITURA!!! %d\n", class_file->constant_pool[i].tag);
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
