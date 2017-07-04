#include "linker.h"


FieldType* read_field_type (char* str){
    FieldType *FT = malloc (sizeof(FieldType));
    char *aux;
    int j=1;
    int i=0;
    if (str[0]=='B')
        i = 1;
    else if (str[0]=='C')
        i = 2;
    else if (str[0]=='D')
        i = 3;
    else if (str[0]=='F')
        i = 4;
    else if (str[0]=='I')
        i = 5;
    else if (str[0]=='J')
        i = 6;
    else if (str[0]=='L')
        i = 7;
    else if (str[0]=='S')
        i = 8;
    else if (str[0]=='Z')
        i = 9;
    else if (str[0]=='[')
        i = 10;

    switch (i) {
        case 0:
            printf("FIELD TYPE DOES NOT EXIST!!! Base Type Character:%c\n", str[0]);
            exit(EXIT_FAILURE);
            break;
        case 1:
            printf("implementar field_type->byte\n" );
            break;
        case 2:
            printf("implementar field_type->char\n" );
            break;
        case 3:
            printf("implementar field_type->double\n" );
            break;
        case 4:
            printf("implementar field_type->float\n" );
            break;
        case 5:
            printf("implementar field_type->int\n" );
            break;
        case 6:
            printf("implementar field_type->long\n" );
            break;
        case 7:
            aux = (char*) malloc (strlen(str)-2);
            for (i = 0, j = 1; i<strlen(str)-2; i++, j++)
            {
              aux[i]=str[j];
            }
            aux[i]='\0';
            FT->class_name_ref = aux;
            // printf ("YO! %s", FT->class_name_ref);
            // getchar();
            break;
        case 8:
            printf("implementar field_type->short\n" );
            break;
        case 9:
            printf("implementar field_type->bool\n" );
            break;
        case 10:
            printf("implementar field_type->array\n" );
            break;
        default:
            return FT;
    }
    return FT;
}





/*
struct MethodDescriptor{
    char* parameter_descriptor;
    char* return_descriptor;
}Meth_Desc;
typedef struct MethodDescriptor MethodDescriptor;

MethodDescriptor * read_method_descriptor (Frame* frame, uint16_t index){
MethodDescriptor Meth_Desc;


  return Meth_Desc;
}

*/
