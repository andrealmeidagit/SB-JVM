#include "constant_pool.h"

void printUTF8 (char * unicode){
    setlocale (LC_ALL, "" );
    printf("%s", unicode);
    setlocale (LC_ALL, NULL );
}

void print_from_index (Frame* frame, uint16_t index){
    printUTF8 ((char *)frame->constant_pool[index].CONSTANT.Utf8_info.bytes);   //imprime o texto UTF-8
}

void printConstantFF(Frame* frame, uint16_t index) {
    ConstantInfo * p = frame->constant_pool + index;
    switch (p->tag) {
    case Const_Utf8:    //tag 1
        printf("UTF-8:\t\t ");
        printUTF8 ((char *)p->CONSTANT.Utf8_info.bytes);   //imprime o texto UTF-8
        printf("\n");
        break;
    case Const_Int:     //tag3
        printf("Integer:\t\t #%u\n", p->CONSTANT.Integer_info.bytes);
        break;
    case Const_Float:   //tag4
        printf("Float:\t\t #%f\n", (float) p->CONSTANT.Float_info.bytes);
        break;
    case Const_Long:   //tag5
        printf("Long:\t\t #%u\t#%u\n", p->CONSTANT.Long_info.high_bytes, p->CONSTANT.Long_info.low_bytes);
      break;
    case Const_Double:   //tag5
        printf("Double:\t\t \n\t- High Bytes:\t #%#010x\n\t- Low Bytes:\t #%#010x\n", p->CONSTANT.Double_info.high_bytes, p->CONSTANT.Double_info.low_bytes);
        break;
    case Const_Class:   //tag7
        printf("Class:\t\t #%u\t // ", p->CONSTANT.Class_info.name_index);
        print_from_index (frame, p->CONSTANT.Class_info.name_index -1);   //imprime o texto UTF-8 a partir do indice
        printf("\n");
        break;
    case Const_String:  //tag8
        printf("String:\t\t #%u\n", p->CONSTANT.String_info.string_index);  //index da string
        print_from_index (frame, p->CONSTANT.String_info.string_index -1);   //imprime o texto UTF-8 a partir do indice
        printf("\n");
        break;
    case Const_FRef:    //tag9 - Field Reference
        printf("Field Reference:\n\t- Class Index:\t #%u\t // ", p->CONSTANT.Fieldref_info.class_index); //indice
        print_from_index (frame, frame->constant_pool[ p->CONSTANT.Fieldref_info.class_index -1 ].CONSTANT.Class_info.name_index -1);   //imprime (field(classe(UTF-8)))
        printf("\n\t- Name and Type: #%u\t // name: ", p->CONSTANT.Fieldref_info.name_and_type_index); //indice
        print_from_index (frame, frame->constant_pool[ p->CONSTANT.Fieldref_info.name_and_type_index -1].CONSTANT.NameAndType_info.name_index -1);   //imprime (field(NameAndType(name(UTF-8))))
        printf("\t descriptor: ");
        print_from_index (frame, frame->constant_pool[ p->CONSTANT.Fieldref_info.name_and_type_index -1].CONSTANT.NameAndType_info.descriptor_index -1);   //imprime (field(NameAndType(descriptor(UTF-8))))
        printf("\n");
        break;
    case Const_MRef:    //tag10 - Method Reference
        printf("Method Reference:\n\t- Class Index:\t #%u\t //\t", p->CONSTANT.Methodref_info.class_index); //indice
        print_from_index (frame, frame->constant_pool[ p->CONSTANT.Methodref_info.class_index -1].CONSTANT.Class_info.name_index -1);   //imprime (field(class(name(UTF-8))))
        printf("\n\t- Name and Type: #%u\t //\tname: ", p->CONSTANT.Methodref_info.name_and_type_index); //indice
        print_from_index (frame, frame->constant_pool[ p->CONSTANT.Methodref_info.name_and_type_index -1].CONSTANT.NameAndType_info.name_index -1);   //imprime (field(NameAndType(name(UTF-8))))
        printf("\t descriptor: ");
        print_from_index (frame, frame->constant_pool[ p->CONSTANT.Methodref_info.name_and_type_index -1].CONSTANT.NameAndType_info.descriptor_index -1);   //imprime (field(NameAndType(descriptor(UTF-8))))
        printf("\n");
        break;
    case Const_IRef:    //tag11 - Interface Method Reference
        printf("Interface Method Reference:\n\t- Class Index:\t #%u", p->CONSTANT.InterfaceMethodref_info.class_index); //indice
        print_from_index (frame, frame->constant_pool[ p->CONSTANT.InterfaceMethodref_info.class_index -1].CONSTANT.Class_info.name_index -1);   //imprime (field(class(name(UTF-8))))
        printf("\n\t- Name and Type: #%u\t //\tname: ", p->CONSTANT.InterfaceMethodref_info.name_and_type_index); //indice
        print_from_index (frame, frame->constant_pool[ p->CONSTANT.InterfaceMethodref_info.name_and_type_index -1].CONSTANT.NameAndType_info.name_index -1);   //imprime (field(NameAndType(name(UTF-8))))
        printf("\t descriptor: ");
        print_from_index (frame, frame->constant_pool[ p->CONSTANT.InterfaceMethodref_info.name_and_type_index -1].CONSTANT.NameAndType_info.descriptor_index -1);   //imprime (field(NameAndType(descriptor(UTF-8))))
        printf("\n");
        break;
    case Const_NAT:     //tag12 - Name and Type
        printf("Name and Type:\n\t- Name Index:\t #%u\t // ", p->CONSTANT.NameAndType_info.name_index);    //indice
        print_from_index (frame, p->CONSTANT.NameAndType_info.name_index -1);   //imprime (Name and Type(name(UTF-8)))
        printf("\n\t- Descriptor:\t #%u\t // ", p->CONSTANT.NameAndType_info.descriptor_index); //indice
        print_from_index (frame, p->CONSTANT.NameAndType_info.descriptor_index -1);   //imprime (Name and Type(descriptor(UTF-8)))
        printf("\n");
        break;
    case Const_MHand:   //tag15 - Method Handle
        printf("Method Handle:\n\t- Reference Kind:\t #%u\n\t- Reference Index:\t #%u\n", p->CONSTANT.MethodHandle_info.reference_kind, p->CONSTANT.MethodHandle_info.reference_index);
        break;
    case Const_MType:   //tag16 - Method Type
        printf("Method Type:\n\t- Descriptor:\t #%u\t // ", p->CONSTANT.MethodType_info.descriptor_index);
        print_from_index (frame, p->CONSTANT.MethodType_info.descriptor_index -1);   //imprime (method type(descriptor(UTF-8)))
        printf("\n");
        break;
    case Const_InDyn:   //tag18 - Invoke Dynamic
        printf("Invoke Dynamic:\n\t- Bootstrap Method:\t #%u\n\t- Name and Type: #%u\n", p->CONSTANT.InvokeDynamic_info.bootstrap_method_attr_index, frame->constant_pool[index].CONSTANT.InvokeDynamic_info.name_and_type_index);
        break;
    default:
        printf("INVALID TAG ERROR IN 'printConstantFF'!!! Tag: %u\n", p->tag);
        exit(EXIT_FAILURE);
    }
}
