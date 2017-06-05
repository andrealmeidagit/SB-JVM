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

//read magic number from file
static void readMagicNumber (ClassFile* class_file, FILE* fp) {
    class_file->magic = read4Byte(fp);
}

//get attribute type (faltando implementar constant_pool para funcionar)
ATTRIBUTE_TYPE getAttributeType (attribute_info* a_info, ClassFile* class_file){
    uint16_t a_name_index = a_info->attribute_name_index;
    constPoolInf* constPool = class_file->constant_pool + a_name_index - 1;
    
    // CONSTANTE_Utf8
    uint16_t length = constPool->u.Utf8.length;
    uint8_t* bytes = constPool->u.Utf8.bytes;
    
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
static void readAttributes (field_info* f_info, method_info* m_info, attribute_info* a_info, ClassFile* class_file, FILE* fp){
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
            readAttributes(NULL, NULL, a_info_aux, fp);
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


//read classfile
ClassFile readClassFile(char* file_name) {
    FILE *fp_class_file;
    ClassFile class_file;
    fp_class_file = fopen(file_name, "rb");
    readMagicNumber(&class_file, fp_class_file);
    return class_file;
}
