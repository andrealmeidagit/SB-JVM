#include "leitor.h"

//read 1 byte from file
static uint8_t read1Byte (FILE *fp){
    uint8_t byte = getc(fp);
    if(byte << 8 == EOF){
        puts("ClassFormatError");
        exit(EXIT_FAILURE);
    }
    return byte;
}

//read 2 bytes from file
static uint16_t read2Byte (FILE *fp){
    uint16_t byte = getc(fp);
    if(byte << 16 == EOF){
        puts("ClassFormatError");
        exit(EXIT_FAILURE);
    }
    uint8_t byte_aux = read1Byte(fp);
    
    byte = (byte << 8) | byte_aux;

    return byte;
}

//read 4 bytes from file
static uint32_t read4Byte (FILE *fp){
    uint32_t byte = getc(fp);
    if(byte == EOF){
        puts("ClassFormatError");
        exit(EXIT_FAILURE);
    }
    uint8_t byte_aux = read1Byte(fp);
    byte = (byte << 8) | byte_aux; 
    
    byte_aux = read1Byte(fp);
    byte = (byte << 8) | byte_aux;
    
    byte_aux = read1Byte(fp);
    byte = (byte << 8) | byte_aux;
    return  byte;
}

//read constant pool
static void readCP(ClassFile* class_file, FILE* fp_class_file) {
    uint16_t i, j;
    class_file->constant_pool_count = read2Byte(fp_class_file);  // le o numero de elementos na CONSTANTE pool

    if(class_file->constant_pool_count == 0){   //verifica se CP_count eh valido
        printf("ERRO CONSTANT POOL COUNT!!!\n");
        exit(EXIT_FAILURE);
    }

    class_file->constant_pool = (CP_table *) malloc((class_file->constant_pool_count -1)*sizeof(CP_table));
    CP_table* CP_ptr;
    for(CP_ptr = class_file->constant_pool; CP_ptr < (class_file->constant_pool + class_file->constant_pool_count - 1); CP_ptr++){
        CP_ptr->tag = read1Byte(fp_class_file);
        switch(CP_ptr->tag){
            case Const_Utf8:    //tag 1
                CP_ptr->CONSTANT.Utf8_info.length = read2Byte(fp_class_file);
                if (CP_ptr->CONSTANT.Utf8_info.length>0){
                    CP_ptr->CONSTANT.Utf8_info.bytes = (uint8_t*) malloc((CP_ptr->CONSTANT.Utf8_info.length + 1)*sizeof(uint8_t));
                    for(j=0;j<CP_ptr->CONSTANT.Utf8_info.length;j++)
                        CP_ptr->CONSTANT.Utf8_info.bytes[j] = read1Byte(fp_class_file);
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

            case Const_IRef:    //tag11 - Interface Method Reference
                CP_ptr->CONSTANT.InterfaceMethodref_info.class_index = read2Byte(fp_class_file);
                CP_ptr->CONSTANT.InterfaceMethodref_info.name_and_type_index = read2Byte(fp_class_file);
                break;

            case Const_NAT:     //tag12 - Name and Type
                CP_ptr->CONSTANT.NameAndType_info.name_index = read2Byte(fp_class_file);
                CP_ptr->CONSTANT.NameAndType_info.descriptor_index = read2Byte(fp_class_file);
                break;

            case Const_MHand:   //tag15 - Method Handle
                CP_ptr->CONSTANT.MethodHandle_info.reference_kind = read1Byte(fp_class_file);
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

//read interfaces
static void readInterfaces(ClassFile* class_file, FILE* fp) {
    class_file->interfaces_count = read2Byte(fp);
    if (class_file->interfaces_count > 0) {
        class_file->interfaces = (uint16_t*)malloc(sizeof(uint16_t) * class_file->interfaces_count);
        for(uint16_t* it = class_file->interfaces; it < class_file->interfaces + class_file->interfaces_count; ++it)
            *it = read2Byte(fp);
    }
    else
        class_file->interfaces = NULL;
}

//get attribute type (faltando implementar constant_pool para funcionar)
ATTRIBUTE_TYPE getAttributeType (attribute_info* a_info, ClassFile* class_file){
    uint16_t a_name_index = a_info->attribute_name_index;
    CP_table* constPool = class_file->constant_pool + a_name_index - 1;
    
    // CONSTANTE_Utf8
    uint16_t length = constPool->CONSTANT.Utf8_info.length;
    uint8_t* bytes = constPool->CONSTANT.Utf8_info.bytes;
    
    if(length != 0){
        switch(bytes[0]){
            case    'C':
                if(!strcmp((char *) bytes, "Code")){
                    return  CODE;
                }
                else if(!strcmp((char *) bytes, "CONSTANTEValue")){
                    return  CONSTANTE_VALUE;                    
                }
                break;
            case    'D':
                if(!strcmp((char *) bytes, "Deprecated")){
                    return  DEPRECATED;
                }
                break;
            case    'E':
                if(!strcmp((char *) bytes, "Exceptions")){
                    return  EXCEPTIONS;
                }
                break;
            case    'I':
                if(!strcmp((char *) bytes, "InnerClasses")){
                    return  INNER_CLASSES;
                }
                break;
            case    'L':
                if(!strcmp((char *) bytes, "LineNumberTable")){
                    return  LINE_NUMBER_TABLE;
                }
                else if(!strcmp((char *) bytes, "LocalVariableTable")){
                    return  LOCAL_VARIABLE_TABLE;
                }
                break;
            case    'S':
                if(!strcmp((char *) bytes, "Synthetic")){
                    return  SYNTHETIC;
                }
                else if(!strcmp((char *) bytes, "SourceFile")){
                    return  SOURCE_FILE;
                }
                break;
            default:
                return  UNKNOWN;
        }
    }
    return  UNKNOWN;    
}

//read attributes (faltando implementar o method_info para funcionar)
static void readAttributes (field_info* f_info, MethodInfo* m_info, attribute_info* a_info, ClassFile* class_file, FILE* fp){
    attribute_info* attributes;
    uint16_t attributes_count;
    
    if(f_info != NULL){
        f_info->attributes_count = read2Byte(fp);
        
        if(f_info->attributes_count){
            f_info->attributes = (attribute_info *) malloc(f_info->attributes_count * sizeof(attribute_info)); 
        }
        else{
            f_info->attributes = NULL;
        }
        attributes_count = f_info->attributes_count;
        attributes = f_info->attributes;
    }
    else if(m_info != NULL){
        m_info->attributes_count = read2Byte(fp);
        if(m_info->attributes_count){
            m_info->attributes = (attribute_info *) malloc(m_info->attributes_count * sizeof(attribute_info)); 
        }
        else{
            m_info->attributes = NULL;
        }       
        attributes_count = m_info->attributes_count;
        attributes = m_info->attributes;
    }
    else if(a_info != NULL){
        a_info->u.Code.attributes_count = read2Byte(fp);
        if(a_info->u.Code.attributes_count){
            a_info->u.Code.attributes = (attribute_info *) malloc(a_info->u.Code.attributes_count * sizeof(attribute_info));
        }
        else{
            a_info->u.Code.attributes = NULL;
        }
        attributes_count = a_info->u.Code.attributes_count;
        attributes = a_info->u.Code.attributes;
    }
    else if(class_file != NULL){
        class_file->attributes_count = read2Byte(fp);
        if(class_file->attributes_count){
            class_file->attributes = (attribute_info *) malloc(class_file->attributes_count * sizeof(attribute_info));
        }
        else{
            class_file->attributes = NULL;
        }
        
        attributes_count = class_file->attributes_count;
        attributes = class_file->attributes;
    }
    else{
        puts("Read Attributes Error");
        exit(EXIT_FAILURE);
    }

    attribute_info* a_info_aux = attributes;
    while(a_info_aux < (attributes + attributes_count)){
        a_info_aux->attribute_name_index = read2Byte(fp);
        a_info_aux->attribute_length = read4Byte(fp);
        
        ATTRIBUTE_TYPE attributeType = getAttributeType(a_info_aux, class_file);
        
        if (attributeType == CONSTANTE_VALUE) 
        {
            a_info_aux->u.ConstantValue.constantvalue_index = read2Byte(fp);
        } 
        else if (attributeType == CODE) 
        {
            a_info_aux->u.Code.max_stack = read2Byte(fp);
            a_info_aux->u.Code.max_locals = read2Byte(fp);
            a_info_aux->u.Code.code_length = read4Byte(fp);
            
            if(a_info_aux->u.Code.code_length){
                a_info_aux->u.Code.code = (uint8_t *) malloc(a_info_aux->u.Code.code_length * sizeof(uint8_t));
                
                uint8_t *code_aux = a_info_aux->u.Code.code;
                while(code_aux < (a_info_aux->u.Code.code + a_info_aux->u.Code.code_length)){
                    *code_aux = read1Byte(fp);
                    code_aux++;
                }
            }
                 
            a_info_aux->u.Code.exception_table_length = read2Byte(fp);
            if(a_info_aux->u.Code.exception_table_length){
                a_info_aux->u.Code.exception_table =
                (exception_table_t *) malloc(a_info_aux->u.Code.exception_table_length * sizeof(exception_table_t));
                
                exception_table_t *e_table_aux = a_info_aux->u.Code.exception_table;
                while (e_table_aux < (a_info_aux->u.Code.exception_table + a_info_aux->u.Code.exception_table_length)){
                    e_table_aux->start_pc = read2Byte(fp);
                    e_table_aux->end_pc = read2Byte(fp);
                    e_table_aux->handler_pc = read2Byte(fp);  
                    e_table_aux->catch_type = read2Byte(fp);                  
                    e_table_aux++;
                }
            }    
            readAttributes(NULL, NULL, a_info_aux, class_file, fp);
        } 
        else if (attributeType == EXCEPTIONS)
        {
            a_info_aux->u.Exceptions.number_of_exceptions = read2Byte(fp);
                a_info_aux->u.Exceptions.exception_index_table = (uint16_t *) malloc(a_info_aux->u.Exceptions.number_of_exceptions * sizeof(uint16_t));
                uint16_t * e_index_table_aux = a_info_aux->u.Exceptions.exception_index_table;
                while(e_index_table_aux < (a_info_aux->u.Exceptions.exception_index_table + a_info_aux->u.Exceptions.number_of_exceptions)){ 
                    *e_index_table_aux = read2Byte(fp); 
                }
        } 
        else if (attributeType == INNER_CLASSES)
        {
            a_info_aux->u.InnerClasses.number_of_classes = read2Byte(fp);
            a_info_aux->u.InnerClasses.classes = (inner_classes_t *) malloc (a_info_aux->u.InnerClasses.number_of_classes * sizeof(inner_classes_t));
            
            inner_classes_t *i_classes_aux = a_info_aux->u.InnerClasses.classes;
            while (i_classes_aux < (a_info_aux->u.InnerClasses.classes + a_info_aux->u.InnerClasses.number_of_classes)){
                i_classes_aux->inner_class_info_index = read2Byte(fp);
                i_classes_aux->outer_class_info_index = read2Byte(fp);
                i_classes_aux->inner_name_index = read2Byte(fp);
                i_classes_aux->inner_class_access_flags = read2Byte(fp);
                i_classes_aux++;
            }
        } 
        else if (attributeType == SYNTHETIC) 
        {
        }
        else if (attributeType == SOURCE_FILE) 
        {
            a_info_aux->u.SourceFile.sourcefile_index = read2Byte(fp);
        } 
        else if (attributeType == LINE_NUMBER_TABLE) 
        {
            a_info_aux->u.LineNumberTable.line_number_table_length = read2Byte(fp);
            if(a_info_aux->u.LineNumberTable.line_number_table_length){
                
                a_info_aux->u.LineNumberTable.line_number_table = (line_number_table_t*)
                malloc(a_info_aux->u.LineNumberTable.line_number_table_length * sizeof(line_number_table_t));
                
                line_number_table_t* l_number_aux = a_info_aux->u.LineNumberTable.line_number_table;
                while(l_number_aux < (a_info_aux->u.LineNumberTable.line_number_table + a_info_aux->u.LineNumberTable.line_number_table_length)) 
                {   
                    l_number_aux->start_pc = read2Byte(fp);
                    l_number_aux->line_number = read2Byte(fp);
                    l_number_aux++;
                }           
            }
        } 
        else if (attributeType == LOCAL_VARIABLE_TABLE) 
        {
            a_info_aux->u.LocalVariableTable.local_variable_table_length = read2Byte(fp);
            
            if(a_info_aux->u.LocalVariableTable.local_variable_table_length)
            {
                a_info_aux->u.LocalVariableTable.local_variable_table = (local_variable_table_t *)
                malloc(a_info_aux->u.LocalVariableTable.local_variable_table_length * sizeof(local_variable_table_t));
                
                local_variable_table_t* l_variable_aux = a_info_aux->u.LocalVariableTable.local_variable_table;
                while (l_variable_aux < (a_info_aux->u.LocalVariableTable.local_variable_table + a_info_aux->u.LocalVariableTable.local_variable_table_length))
                {
                    l_variable_aux->start_pc = read2Byte(fp);
                    l_variable_aux->length = read2Byte(fp);
                    l_variable_aux->name_index = read2Byte(fp);
                    l_variable_aux->descriptor_index = read2Byte(fp);
                    l_variable_aux->index = read2Byte(fp);  
                    l_variable_aux++;
                }
            }
        }
        else if (attributeType == DEPRECATED) 
        {
        }  
        else 
        {
        }
        a_info_aux++;
    }
}

//read fields 
static void readFields (ClassFile* class_file, FILE* fp) {

    class_file->fields_count = read2Byte(fp); //get number of fields
    
    if(class_file->fields_count) {
        class_file->fields = (field_info *) malloc((class_file->fields_count)*sizeof(field_info));
        field_info* f_info = class_file->fields;
        while(f_info < (class_file->fields + class_file->fields_count))
        {
            f_info->access_flags = read2Byte(fp);
            f_info->name_index = read2Byte(fp);
            f_info->descriptor_index = read2Byte(fp);
            readAttributes(f_info, NULL, NULL, class_file, fp);
            f_info++;
        }
    }
    else{
        class_file->fields = NULL;
    }
}

//read methods
static void readMethods(ClassFile* class_file, FILE* fp) {
    class_file->methods_count = read2Byte(fp);
    if (class_file->methods_count > 0) {
        class_file->methods = (MethodInfo*)malloc(sizeof(MethodInfo) * class_file->methods_count);
        for(MethodInfo* it = class_file->methods; it < class_file->methods + class_file->methods_count; ++it) {
            it->access_flags = read2Byte(fp);
            it->name_index = read2Byte(fp);
            it->descriptor_index = read2Byte(fp);
            readAttributes(NULL, it, NULL, class_file, fp);
        }
    }
    else
        class_file->methods = NULL;
}

//read classfile
ClassFile readClassFile(char* file_name) {
    FILE *fp;
    ClassFile class_file;
    fp = fopen(file_name, "rb");
    class_file.magic = read4Byte(fp);
    class_file.minor_version = read2Byte(fp);
    class_file.major_version = read2Byte(fp);
    readCP(&class_file, fp);
    class_file.access_flags = read2Byte(fp);
    class_file.this_class = read2Byte(fp);
    class_file.super_class = read2Byte(fp);
    readInterfaces(&class_file, fp);
    readFields(&class_file, fp);
    readMethods(&class_file, fp);
    readAttributes(NULL, NULL, NULL, &class_file, fp);
    fclose(fp);
    return class_file;
}
