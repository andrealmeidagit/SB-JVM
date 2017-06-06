#include "exibidor.h"

void printUTF8 (FILE* stream, char * unicode){
	setlocale (LC_ALL, "" );
    fprintf(stream, "Constant UTF-8:\t %s\n", unicode);
    setlocale (LC_ALL, NULL );
}

static void printCP(FILE* stream, ClassFile* class_file){
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



void showClassFile(FILE* stream, ClassFile class_file) {
	fprintf(stream, "\t\t CLASS FILE:");
    fprintf(stream, "Magic Number:\t 0x%"PRIx32"\n", class_file.magic);
    fprintf(stream, "Minor Version:\t %"PRIu16"\n", class_file.minor_version);
    fprintf(stream, "Major Version:\t %"PRIu16"\n", class_file.major_version);
    fprintf(stream, "CPcount:\t %"PRIu16"\n", class_file.constant_pool_count);
    printCP(stream, &class_file);
    fprintf(stream, "Access Flags:\t 0x%"PRIx16"\n", class_file.access_flags);
	fprintf(stream, "This Class:\t 0x%"PRIx16"\n", class_file.this_class);
	fprintf(stream, "Super Class:\t 0x%"PRIx16"\n", class_file.super_class);

}
