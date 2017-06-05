#include "leitor.h"

static uint8_t readByte(FILE* fp) {
    uint8_t byte;
    fread(&byte, 1, 1, fp);
    return byte;
}

static uint16_t read2Byte(FILE* fp) {
    uint16_t byte2;
    byte2 = readByte(fp);
    byte2 = (byte2 << 8) | readByte(fp);
    return byte2;
}

static uint32_t read4Byte(FILE* fp) {
    uint32_t byte4;
    byte4 = read2Byte(fp);
    byte4 = (byte4 << 16) | read2Byte(fp);
    return byte4;
}

static void readCP(ClassFile* class_file, FILE* fp_class_file) {
    uint16_t i, j;
    CP_table* CP_ptr = class_file->cp_info;

    if(class_file->constant_pool_count == 0){   //verifica se CP_count eh valido
        printf("ERRO CONSTANT POOL COUNT!!!\n");
        exit(EXIT_FAILURE);
    }

    class_file->cp_info = (CP_table *) malloc((class_file->constant_pool_count -1)*sizeof(CP_table));

    for(i=0; i<class_file->constant_pool_count; i++){
        CP_ptr->tag = readByte(fp_class_file);

        switch(CP_ptr->tag){
            case Const_Utf8:    //tag 1
                CP_ptr->CONSTANT.Utf8_info.length = read2Byte(fp_class_file);
                if (CP_ptr->CONSTANT.Utf8_info.length>0){
                    CP_ptr->CONSTANT.Utf8_info.bytes = (uint8_t*) malloc((CP_ptr->CONSTANT.Utf8_info.length + 1)*sizeof(uint8_t));
                    for(j=0;j<CP_ptr->CONSTANT.Utf8_info.length;j++){
                        CP_ptr->CONSTANT.Utf8_info.bytes[j] = readByte(fp_class_file);
                    }
                    CP_ptr->CONSTANT.Utf8_info.bytes[CP_ptr->CONSTANT.Utf8_info.length] = '\0';
                }else{
                    CP_ptr->CONSTANT.Utf8_info.bytes = NULL;
                }
                break;

            case Const_Int:     //tag3
                CP_ptr->CONSTANT.Integer_info.bytes = read4Byte(fp_class_file);
                break;

            case Const_Float:   //tag4
                CP_ptr->CONSTANT.Float_info.bytes = read4Byte(fp_class_file);
                break;

            case Const_Long:   //tag5
                CP_ptr->CONSTANT.Long_info.high_bytes = read4Byte(fp_class_file);
                CP_ptr->CONSTANT.Long_info.low_bytes = read4Byte(fp_class_file);
                break;

            case Const_Double:  //tag6
                CP_ptr->CONSTANT.Double_info.high_bytes = read4Byte(fp_class_file);
                CP_ptr->CONSTANT.Double_info.low_bytes = read4Byte(fp_class_file);
                break;

            case Const_Class:   //tag7
                CP_ptr->CONSTANT.Class_info.name_index = read2Byte(fp_class_file);
                break;

            case Const_String:  //tag8
                CP_ptr->CONSTANT.String_info.string_index = read2Byte(fp_class_file);
                break;

            case Const_FRef:    //tag9 - Field Reference
                CP_ptr->CONSTANT.Fieldref_info.class_index = read2Byte(fp_class_file);
                CP_ptr->CONSTANT.Fieldref_info.name_and_type_index = read2Byte(fp_class_file);
                break;

            case Const_MRef:    //tag10 - Method Reference
                CP_ptr->CONSTANT.Methodref_info.class_index = read2Byte(fp_class_file);
                CP_ptr->CONSTANT.Methodref_info.name_and_type_index = read2Byte(fp_class_file);
                break;

            case Const_IRef:    //tag11 - Interface Reference
                CP_ptr->CONSTANT.InterfaceMethodref_info.class_index = read2Byte(fp_class_file);
                CP_ptr->CONSTANT.InterfaceMethodref_info.name_and_type_index = read2Byte(fp_class_file);
                break;

            case Const_NAT:     //tag12 - Name and Type
                CP_ptr->CONSTANT.NameAndType_info.name_index = read2Byte(fp_class_file);
                CP_ptr->CONSTANT.NameAndType_info.descriptor_index = read2Byte(fp_class_file);
                break;

            case Const_MHand:   //tag15 - Method Handle
                CP_ptr->CONSTANT.MethodHandle_info.reference_kind = readByte(fp_class_file);
                CP_ptr->CONSTANT.MethodHandle_info.reference_index = read2Byte(fp_class_file);
                break;

            case Const_MType:   //tag16 - Method Type
                CP_ptr->CONSTANT.MethodType_info.descriptor_index = read2Byte(fp_class_file);
                break;

            case Const_InDyn:   //tag18 - Invoke Dynamic
                CP_ptr->CONSTANT.InvokeDynamic_info.bootstrap_method_attr_index = read2Byte(fp_class_file);
                CP_ptr->CONSTANT.InvokeDynamic_info.name_and_type_index = read2Byte(fp_class_file);
                break;

            default:
                printf("ERRO CONSTANT POOL TAG!!!\n");
                exit(EXIT_FAILURE);
        }   
    }

}

ClassFile readClassFile(char* file_name) {
    FILE *fp_class_file;
    ClassFile class_file;
    fp_class_file = fopen(file_name, "rb");

    class_file.magic = read4Byte(fp_class_file);
    class_file.minor_version = read2Byte(fp_class_file);
    class_file.major_version = read2Byte(fp_class_file);
    class_file.constant_pool_count = read2Byte(fp_class_file);
    /* Read constant pool */
    return class_file;
    readCP(&class_file, fp_class_file);
    class_file.access_flags = read2Byte(fp_class_file);
    class_file.this_class = read2Byte(fp_class_file);
    class_file.super_class = read2Byte(fp_class_file);
    class_file.interfaces_count = read2Byte(fp_class_file);
    /* Read interfaces */
    class_file.fields_count = read2Byte(fp_class_file);
    /* Read fields */
    class_file.methods_count = read2Byte(fp_class_file);
    /* Read methods */
    class_file.attributes_count = read2Byte(fp_class_file);
    /* Read attributes */
}
