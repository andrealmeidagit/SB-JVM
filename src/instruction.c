#include "instruction.h"

void initInstructionArray() {
    INSTRUCTION_ARRAY[0x00] = instruction_nop;
    INSTRUCTION_ARRAY[0x01] = instruction_aconst_null;
    INSTRUCTION_ARRAY[0x02] = instruction_iconst_m1;
    INSTRUCTION_ARRAY[0x03] = instruction_iconst_0;
    INSTRUCTION_ARRAY[0x04] = instruction_iconst_1;
    INSTRUCTION_ARRAY[0x05] = instruction_iconst_2;
    INSTRUCTION_ARRAY[0x06] = instruction_iconst_3;
    INSTRUCTION_ARRAY[0x07] = instruction_iconst_4;
    INSTRUCTION_ARRAY[0x08] = instruction_iconst_5;
    INSTRUCTION_ARRAY[0x09] = instruction_lconst_0;
    INSTRUCTION_ARRAY[0x0a] = instruction_lconst_1;
    INSTRUCTION_ARRAY[0x0b] = instruction_fconst_0;
    INSTRUCTION_ARRAY[0x0c] = instruction_fconst_1;
    INSTRUCTION_ARRAY[0x0d] = instruction_fconst_2;
    INSTRUCTION_ARRAY[0x0e] = instruction_dconst_0;
    INSTRUCTION_ARRAY[0x0f] = instruction_dconst_1;
    INSTRUCTION_ARRAY[0x10] = instruction_bipush;
    INSTRUCTION_ARRAY[0x11] = instruction_sipush;
    INSTRUCTION_ARRAY[0x12] = instruction_ldc;
    INSTRUCTION_ARRAY[0x13] = instruction_ldc_w;
    INSTRUCTION_ARRAY[0x14] = instruction_ldc2_w;
    INSTRUCTION_ARRAY[0x15] = instruction_iload;
    INSTRUCTION_ARRAY[0x16] = instruction_lload;
    INSTRUCTION_ARRAY[0x17] = instruction_fload;
    INSTRUCTION_ARRAY[0x18] = instruction_dload;
    INSTRUCTION_ARRAY[0x19] = instruction_aload;
    INSTRUCTION_ARRAY[0x1a] = instruction_iload_0;
    INSTRUCTION_ARRAY[0x1b] = instruction_iload_1;
    INSTRUCTION_ARRAY[0x1c] = instruction_iload_2;
    INSTRUCTION_ARRAY[0x1d] = instruction_iload_3;
    INSTRUCTION_ARRAY[0x1e] = instruction_lload_0;
    INSTRUCTION_ARRAY[0x1f] = instruction_lload_1;
    INSTRUCTION_ARRAY[0x20] = instruction_lload_2;
    INSTRUCTION_ARRAY[0x21] = instruction_lload_3;
    INSTRUCTION_ARRAY[0x22] = instruction_fload_0;
    INSTRUCTION_ARRAY[0x23] = instruction_fload_1;
    INSTRUCTION_ARRAY[0x24] = instruction_fload_2;
    INSTRUCTION_ARRAY[0x25] = instruction_fload_3;
    INSTRUCTION_ARRAY[0x26] = instruction_dload_0;
    INSTRUCTION_ARRAY[0x27] = instruction_dload_1;
    INSTRUCTION_ARRAY[0x28] = instruction_dload_2;
    INSTRUCTION_ARRAY[0x29] = instruction_dload_3;
    INSTRUCTION_ARRAY[0x2a] = instruction_aload_0;
    INSTRUCTION_ARRAY[0x2b] = instruction_aload_1;
    INSTRUCTION_ARRAY[0x2c] = instruction_aload_2;
    INSTRUCTION_ARRAY[0x2d] = instruction_aload_3;
    INSTRUCTION_ARRAY[0x2e] = instruction_iaload;
    INSTRUCTION_ARRAY[0x2f] = instruction_laload;
    INSTRUCTION_ARRAY[0x30] = instruction_faload;
    INSTRUCTION_ARRAY[0x31] = instruction_daload;
    INSTRUCTION_ARRAY[0x32] = instruction_aaload;
    INSTRUCTION_ARRAY[0x33] = instruction_baload;
    INSTRUCTION_ARRAY[0x34] = instruction_caload;
    INSTRUCTION_ARRAY[0x35] = instruction_saload;
    INSTRUCTION_ARRAY[0x36] = instruction_istore;
    INSTRUCTION_ARRAY[0x37] = instruction_lstore;
    INSTRUCTION_ARRAY[0x38] = instruction_fstore;
    INSTRUCTION_ARRAY[0x39] = instruction_dstore;
    INSTRUCTION_ARRAY[0x3a] = instruction_astore;
    INSTRUCTION_ARRAY[0x3b] = instruction_istore_0;
    INSTRUCTION_ARRAY[0x3c] = instruction_istore_1;
    INSTRUCTION_ARRAY[0x3d] = instruction_istore_2;
    INSTRUCTION_ARRAY[0x3e] = instruction_istore_3;
    INSTRUCTION_ARRAY[0x3f] = instruction_lstore_0;
    INSTRUCTION_ARRAY[0x40] = instruction_lstore_1;
    INSTRUCTION_ARRAY[0x41] = instruction_lstore_2;
    INSTRUCTION_ARRAY[0x42] = instruction_lstore_3;
    INSTRUCTION_ARRAY[0x43] = instruction_fstore_0;
    INSTRUCTION_ARRAY[0x44] = instruction_fstore_1;
    INSTRUCTION_ARRAY[0x45] = instruction_fstore_2;
    INSTRUCTION_ARRAY[0x46] = instruction_fstore_3;
    INSTRUCTION_ARRAY[0x47] = instruction_dstore_0;
    INSTRUCTION_ARRAY[0x48] = instruction_dstore_1;
    INSTRUCTION_ARRAY[0x49] = instruction_dstore_2;
    INSTRUCTION_ARRAY[0x4a] = instruction_dstore_3;
    INSTRUCTION_ARRAY[0x4b] = instruction_astore_0;
    INSTRUCTION_ARRAY[0x4c] = instruction_astore_1;
    INSTRUCTION_ARRAY[0x4d] = instruction_astore_2;
    INSTRUCTION_ARRAY[0x4e] = instruction_astore_3;
    INSTRUCTION_ARRAY[0x4f] = instruction_iastore;
    INSTRUCTION_ARRAY[0x50] = instruction_lastore;
    INSTRUCTION_ARRAY[0x51] = instruction_fastore;
    INSTRUCTION_ARRAY[0x52] = instruction_dastore;
    INSTRUCTION_ARRAY[0x53] = instruction_aastore;
    INSTRUCTION_ARRAY[0x54] = instruction_bastore;
    INSTRUCTION_ARRAY[0x55] = instruction_castore;
    INSTRUCTION_ARRAY[0x56] = instruction_sastore;
    INSTRUCTION_ARRAY[0x57] = instruction_pop;
    INSTRUCTION_ARRAY[0x58] = instruction_pop2;
    INSTRUCTION_ARRAY[0x59] = instruction_dup;
    INSTRUCTION_ARRAY[0x5a] = instruction_dup_x1;
    INSTRUCTION_ARRAY[0x5b] = instruction_dup_x2;
    INSTRUCTION_ARRAY[0x5c] = instruction_dup2;
    INSTRUCTION_ARRAY[0x5d] = instruction_dup2_x1;
    INSTRUCTION_ARRAY[0x5e] = instruction_dup2_x2;
    INSTRUCTION_ARRAY[0x5f] = instruction_swap;
    INSTRUCTION_ARRAY[0x60] = instruction_iadd;
    INSTRUCTION_ARRAY[0x61] = instruction_ladd;
    INSTRUCTION_ARRAY[0x62] = instruction_fadd;
    INSTRUCTION_ARRAY[0x63] = instruction_dadd;
    INSTRUCTION_ARRAY[0x64] = instruction_isub;
    INSTRUCTION_ARRAY[0x65] = instruction_lsub;
    INSTRUCTION_ARRAY[0x66] = instruction_fsub;
    INSTRUCTION_ARRAY[0x67] = instruction_dsub;
    INSTRUCTION_ARRAY[0x68] = instruction_imul;
    INSTRUCTION_ARRAY[0x69] = instruction_lmul;
    INSTRUCTION_ARRAY[0x6a] = instruction_fmul;
    INSTRUCTION_ARRAY[0x6b] = instruction_dmul;
    INSTRUCTION_ARRAY[0x6c] = instruction_idiv;
    INSTRUCTION_ARRAY[0x6d] = instruction_ldiv;
    INSTRUCTION_ARRAY[0x6e] = instruction_fdiv;
    INSTRUCTION_ARRAY[0x6f] = instruction_ddiv;
    INSTRUCTION_ARRAY[0x70] = instruction_irem;
    INSTRUCTION_ARRAY[0x71] = instruction_lrem;
    INSTRUCTION_ARRAY[0x72] = instruction_frem;
    INSTRUCTION_ARRAY[0x73] = instruction_drem;
    INSTRUCTION_ARRAY[0x74] = instruction_ineg;
    INSTRUCTION_ARRAY[0x75] = instruction_lneg;
    INSTRUCTION_ARRAY[0x76] = instruction_fneg;
    INSTRUCTION_ARRAY[0x77] = instruction_dneg;
    INSTRUCTION_ARRAY[0x78] = instruction_ishl;
    INSTRUCTION_ARRAY[0x79] = instruction_lshl;
    INSTRUCTION_ARRAY[0x7a] = instruction_ishr;
    INSTRUCTION_ARRAY[0x7b] = instruction_lshr;
    INSTRUCTION_ARRAY[0x7c] = instruction_iushr;
    INSTRUCTION_ARRAY[0x7d] = instruction_lushr;
    INSTRUCTION_ARRAY[0x7e] = instruction_iand;
    INSTRUCTION_ARRAY[0x7f] = instruction_land;
    INSTRUCTION_ARRAY[0x80] = instruction_ior;
    INSTRUCTION_ARRAY[0x81] = instruction_lor;
    INSTRUCTION_ARRAY[0x82] = instruction_ixor;
    INSTRUCTION_ARRAY[0x83] = instruction_lxor;
    INSTRUCTION_ARRAY[0x84] = instruction_iinc;
    INSTRUCTION_ARRAY[0x85] = instruction_i2l;
    INSTRUCTION_ARRAY[0x86] = instruction_i2f;
    INSTRUCTION_ARRAY[0x87] = instruction_i2d;
    INSTRUCTION_ARRAY[0x88] = instruction_l2i;
    INSTRUCTION_ARRAY[0x89] = instruction_l2f;
    INSTRUCTION_ARRAY[0x8a] = instruction_l2d;
    INSTRUCTION_ARRAY[0x8b] = instruction_f2i;
    INSTRUCTION_ARRAY[0x8c] = instruction_f2l;
    INSTRUCTION_ARRAY[0x8d] = instruction_f2d;
    INSTRUCTION_ARRAY[0x8e] = instruction_d2i;
    INSTRUCTION_ARRAY[0x8f] = instruction_d2l;
    INSTRUCTION_ARRAY[0x90] = instruction_d2f;
    INSTRUCTION_ARRAY[0x91] = instruction_i2b;
    INSTRUCTION_ARRAY[0x92] = instruction_i2c;
    INSTRUCTION_ARRAY[0x93] = instruction_i2s;
    INSTRUCTION_ARRAY[0x94] = instruction_lcmp;
    INSTRUCTION_ARRAY[0x95] = instruction_fcmpl;
    INSTRUCTION_ARRAY[0x96] = instruction_fcmpg;
    INSTRUCTION_ARRAY[0x97] = instruction_dcmpl;
    INSTRUCTION_ARRAY[0x98] = instruction_dcmpg;
    INSTRUCTION_ARRAY[0x99] = instruction_ifeq;
    INSTRUCTION_ARRAY[0x9a] = instruction_ifne;
    INSTRUCTION_ARRAY[0x9b] = instruction_iflt;
    INSTRUCTION_ARRAY[0x9c] = instruction_ifge;
    INSTRUCTION_ARRAY[0x9d] = instruction_ifgt;
    INSTRUCTION_ARRAY[0x9e] = instruction_ifle;
    INSTRUCTION_ARRAY[0x9f] = instruction_if_icmpeq;
    INSTRUCTION_ARRAY[0xa0] = instruction_if_icmpne;
    INSTRUCTION_ARRAY[0xa1] = instruction_if_icmplt;
    INSTRUCTION_ARRAY[0xa2] = instruction_if_icmpge;
    INSTRUCTION_ARRAY[0xa3] = instruction_if_icmpgt;
    INSTRUCTION_ARRAY[0xa4] = instruction_if_icmple;
    INSTRUCTION_ARRAY[0xa5] = instruction_if_acmpeq;
    INSTRUCTION_ARRAY[0xa6] = instruction_if_acmpne;
    INSTRUCTION_ARRAY[0xa7] = instruction_goto;
    INSTRUCTION_ARRAY[0xa8] = instruction_jsr;
    INSTRUCTION_ARRAY[0xa9] = instruction_ret;
    INSTRUCTION_ARRAY[0xaa] = instruction_tableswitch;
    INSTRUCTION_ARRAY[0xab] = instruction_lookupswitch;
    INSTRUCTION_ARRAY[0xac] = instruction_ireturn;
    INSTRUCTION_ARRAY[0xad] = instruction_lreturn;
    INSTRUCTION_ARRAY[0xae] = instruction_freturn;
    INSTRUCTION_ARRAY[0xaf] = instruction_dreturn;
    INSTRUCTION_ARRAY[0xb0] = instruction_areturn;
    INSTRUCTION_ARRAY[0xb1] = instruction_return;
    INSTRUCTION_ARRAY[0xb2] = instruction_getstatic;
    INSTRUCTION_ARRAY[0xb3] = instruction_putstatic;
    INSTRUCTION_ARRAY[0xb4] = instruction_getfield;
    INSTRUCTION_ARRAY[0xb5] = instruction_putfield;
    INSTRUCTION_ARRAY[0xb6] = instruction_invokevirtual;
    INSTRUCTION_ARRAY[0xb7] = instruction_invokespecial;
    INSTRUCTION_ARRAY[0xb8] = instruction_invokestatic;
    INSTRUCTION_ARRAY[0xb9] = instruction_invokeinterface;
    INSTRUCTION_ARRAY[0xba] = instruction_invokedynamic;
    INSTRUCTION_ARRAY[0xbb] = instruction_new;
    INSTRUCTION_ARRAY[0xbc] = instruction_newarray;
    INSTRUCTION_ARRAY[0xbd] = instruction_anewarray;
    INSTRUCTION_ARRAY[0xbe] = instruction_arraylength;
    INSTRUCTION_ARRAY[0xbf] = instruction_athrow;
    INSTRUCTION_ARRAY[0xc0] = instruction_checkcast;
    INSTRUCTION_ARRAY[0xc1] = instruction_instanceof;
    INSTRUCTION_ARRAY[0xc2] = instruction_monitorenter;
    INSTRUCTION_ARRAY[0xc3] = instruction_monitorexit;
    INSTRUCTION_ARRAY[0xc4] = instruction_wide;
    INSTRUCTION_ARRAY[0xc5] = instruction_multianewarray;
    INSTRUCTION_ARRAY[0xc6] = instruction_ifnull;
    INSTRUCTION_ARRAY[0xc7] = instruction_ifnonnull;
    INSTRUCTION_ARRAY[0xc8] = instruction_goto_w;
    INSTRUCTION_ARRAY[0xc9] = instruction_jsr_w;
}

void instruction_nop(Frame* frame) {
    frame->pc += 1;
}

void instruction_aconst_null(Frame* frame) {

}

void instruction_iconst_m1(Frame* frame) {
    pushOperand(frame, newOperand(fromInt32(-1)));
    frame->pc+=1;
}

void instruction_iconst_0(Frame* frame) {
    pushOperand(frame, newOperand(0));
    frame->pc+=1;
}

void instruction_iconst_1(Frame* frame) {
    pushOperand(frame, newOperand(1));
    frame->pc+=1;
}

void instruction_iconst_2(Frame* frame) {
    pushOperand(frame, newOperand(2));
    frame->pc+=1;
}

void instruction_iconst_3(Frame* frame) {
    pushOperand(frame, newOperand(3));
    frame->pc+=1;
}

void instruction_iconst_4(Frame* frame) {
    pushOperand(frame, newOperand(4));
    frame->pc+=1;
}

void instruction_iconst_5(Frame* frame) {
    pushOperand(frame, newOperand(5));
    frame->pc+=1;
}

void instruction_lconst_0(Frame* frame) {

}

void instruction_lconst_1(Frame* frame) {

}

void instruction_fconst_0(Frame* frame) {

}

void instruction_fconst_1(Frame* frame) {

}

void instruction_fconst_2(Frame* frame) {

}

void instruction_dconst_0(Frame* frame) {

}

void instruction_dconst_1(Frame* frame) {

}

void instruction_bipush(Frame* frame) {
    uint8_t data = getByte(frame, 1);
    pushOperand(frame, newOperand(data));
    frame->pc += 2;
}

void instruction_sipush(Frame* frame) {

}

void instruction_ldc(Frame* frame) {
    printf("Executando ldc\n");
    uint8_t constant_pool_index = findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[frame->pc + 1];
    printConstantFF(frame, constant_pool_index-1);
    ConstantInfo constant = frame->constant_pool[constant_pool_index - 1];
    OperandInfo* op = (OperandInfo*)malloc(sizeof(OperandInfo));
    switch (constant.tag) {
        case Const_Int:
        op->data = constant.CONSTANT.Integer_info.bytes;
        break;
        case Const_Float:
        op->data = constant.CONSTANT.Float_info.bytes;
        break;
        case Const_String:
        op->data = constant.CONSTANT.String_info.string_index;
        break;
        default:
        fprintf(stderr, "[ERROR]: LDC requested unsupported constant\n");
    }
    pushOperand(frame, op);
    frame->pc += 2;
}

void instruction_ldc_w(Frame* frame) {

}

void instruction_ldc2_w(Frame* frame) {

}

void instruction_iload(Frame* frame) {

}

void instruction_lload(Frame* frame) {

}

void instruction_fload(Frame* frame) {

}

void instruction_dload(Frame* frame) {

}

void instruction_aload(Frame* frame) {

}

void instruction_iload_0(Frame* frame) {
    pushOperand(frame, newOperand(frame->local_variables[0]));
    frame->pc+=1;
}

void instruction_iload_1(Frame* frame) {
    pushOperand(frame, newOperand(frame->local_variables[1]));
    frame->pc+=1;
}

void instruction_iload_2(Frame* frame) {
    pushOperand(frame, newOperand(frame->local_variables[2]));
    frame->pc+=1;
}

void instruction_iload_3(Frame* frame) {
    pushOperand(frame, newOperand(frame->local_variables[3]));
    frame->pc+=1;
}

void instruction_lload_0(Frame* frame) {

}

void instruction_lload_1(Frame* frame) {

}

void instruction_lload_2(Frame* frame) {

}

void instruction_lload_3(Frame* frame) {

}

void instruction_fload_0(Frame* frame) {

}

void instruction_fload_1(Frame* frame) {

}

void instruction_fload_2(Frame* frame) {

}

void instruction_fload_3(Frame* frame) {

}

void instruction_dload_0(Frame* frame) {

}

void instruction_dload_1(Frame* frame) {

}

void instruction_dload_2(Frame* frame) {

}

void instruction_dload_3(Frame* frame) {

}

void instruction_aload_0(Frame* frame) {

}

void instruction_aload_1(Frame* frame) {

}

void instruction_aload_2(Frame* frame) {

}

void instruction_aload_3(Frame* frame) {

}

void instruction_iaload(Frame* frame) {

}

void instruction_laload(Frame* frame) {

}

void instruction_faload(Frame* frame) {

}

void instruction_daload(Frame* frame) {

}

void instruction_aaload(Frame* frame) {

}

void instruction_baload(Frame* frame) {

}

void instruction_caload(Frame* frame) {

}

void instruction_saload(Frame* frame) {

}

void instruction_istore(Frame* frame) {

}

void instruction_lstore(Frame* frame) {

}

void instruction_fstore(Frame* frame) {

}

void instruction_dstore(Frame* frame) {

}

void instruction_astore(Frame* frame) {

}

void instruction_istore_0(Frame* frame) {
    OperandInfo *op = popOperand(frame);
    frame->local_variables[0]=op->data;
    free (op);
    frame->pc+=1;
}

void instruction_istore_1(Frame* frame) {
    OperandInfo *op = popOperand(frame);
    frame->local_variables[1]=op->data;
    free (op);
    frame->pc+=1;
}

void instruction_istore_2(Frame* frame) {
    OperandInfo *op = popOperand(frame);
    frame->local_variables[2]=op->data;
    free (op);
    frame->pc+=1;
}

void instruction_istore_3(Frame* frame) {
    OperandInfo *op = popOperand(frame);
    frame->local_variables[3]=op->data;
    free (op);
    frame->pc+=1;
}

void instruction_lstore_0(Frame* frame) {

}

void instruction_lstore_1(Frame* frame) {

}

void instruction_lstore_2(Frame* frame) {

}

void instruction_lstore_3(Frame* frame) {

}

void instruction_fstore_0(Frame* frame) {

}

void instruction_fstore_1(Frame* frame) {

}

void instruction_fstore_2(Frame* frame) {

}

void instruction_fstore_3(Frame* frame) {

}

void instruction_dstore_0(Frame* frame) {

}

void instruction_dstore_1(Frame* frame) {

}

void instruction_dstore_2(Frame* frame) {

}

void instruction_dstore_3(Frame* frame) {

}

void instruction_astore_0(Frame* frame) {

}

void instruction_astore_1(Frame* frame) {

}

void instruction_astore_2(Frame* frame) {

}

void instruction_astore_3(Frame* frame) {

}

void instruction_iastore(Frame* frame) {

}

void instruction_lastore(Frame* frame) {

}

void instruction_fastore(Frame* frame) {

}

void instruction_dastore(Frame* frame) {

}

void instruction_aastore(Frame* frame) {

}

void instruction_bastore(Frame* frame) {

}

void instruction_castore(Frame* frame) {

}

void instruction_sastore(Frame* frame) {

}

void instruction_pop(Frame* frame) {

}

void instruction_pop2(Frame* frame) {

}

void instruction_dup(Frame* frame) {

}

void instruction_dup_x1(Frame* frame) {

}

void instruction_dup_x2(Frame* frame) {

}

void instruction_dup2(Frame* frame) {

}

void instruction_dup2_x1(Frame* frame) {

}

void instruction_dup2_x2(Frame* frame) {

}

void instruction_swap(Frame* frame) {

}

void instruction_iadd(Frame* frame) {
    OperandInfo *op = popOperand(frame);
    OperandInfo *op2 = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) + toInt32(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_ladd(Frame* frame) {

}

void instruction_fadd(Frame* frame) {

}

void instruction_dadd(Frame* frame) {

}

void instruction_isub(Frame* frame) {
    OperandInfo *op = popOperand(frame);
    OperandInfo *op2 = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) - toInt32(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_lsub(Frame* frame) {

}

void instruction_fsub(Frame* frame) {

}

void instruction_dsub(Frame* frame) {

}

void instruction_imul(Frame* frame) {
    OperandInfo *op = popOperand(frame);
    OperandInfo *op2 = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) * toInt32(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_lmul(Frame* frame) {

}

void instruction_fmul(Frame* frame) {

}

void instruction_dmul(Frame* frame) {

}

void instruction_idiv(Frame* frame) {
    OperandInfo *op = popOperand(frame);
    OperandInfo *op2 = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) / toInt32(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_ldiv(Frame* frame) {

}

void instruction_fdiv(Frame* frame) {

}

void instruction_ddiv(Frame* frame) {

}

void instruction_irem(Frame* frame) {

}

void instruction_lrem(Frame* frame) {

}

void instruction_frem(Frame* frame) {

}

void instruction_drem(Frame* frame) {

}

void instruction_ineg(Frame* frame) {

}

void instruction_lneg(Frame* frame) {

}

void instruction_fneg(Frame* frame) {

}

void instruction_dneg(Frame* frame) {

}

void instruction_ishl(Frame* frame) {

}

void instruction_lshl(Frame* frame) {

}

void instruction_ishr(Frame* frame) {

}

void instruction_lshr(Frame* frame) {

}

void instruction_iushr(Frame* frame) {

}

void instruction_lushr(Frame* frame) {

}

void instruction_iand(Frame* frame) {

}

void instruction_land(Frame* frame) {

}

void instruction_ior(Frame* frame) {

}

void instruction_lor(Frame* frame) {

}

void instruction_ixor(Frame* frame) {

}

void instruction_lxor(Frame* frame) {

}

void instruction_iinc(Frame* frame) {

}

void instruction_i2l(Frame* frame) {

}

void instruction_i2f(Frame* frame) {

}

void instruction_i2d(Frame* frame) {

}

void instruction_l2i(Frame* frame) {

}

void instruction_l2f(Frame* frame) {

}

void instruction_l2d(Frame* frame) {

}

void instruction_f2i(Frame* frame) {

}

void instruction_f2l(Frame* frame) {

}

void instruction_f2d(Frame* frame) {

}

void instruction_d2i(Frame* frame) {

}

void instruction_d2l(Frame* frame) {

}

void instruction_d2f(Frame* frame) {

}

void instruction_i2b(Frame* frame) {

}

void instruction_i2c(Frame* frame) {

}

void instruction_i2s(Frame* frame) {

}

void instruction_lcmp(Frame* frame) {

}

void instruction_fcmpl(Frame* frame) {

}

void instruction_fcmpg(Frame* frame) {

}

void instruction_dcmpl(Frame* frame) {

}

void instruction_dcmpg(Frame* frame) {

}

void instruction_ifeq(Frame* frame) {

}

void instruction_ifne(Frame* frame) {

}

void instruction_iflt(Frame* frame) {

}

void instruction_ifge(Frame* frame) {

}

void instruction_ifgt(Frame* frame) {

}

void instruction_ifle(Frame* frame) {

}

void instruction_if_icmpeq(Frame* frame) {

}

void instruction_if_icmpne(Frame* frame) {

}

void instruction_if_icmplt(Frame* frame) {

}

void instruction_if_icmpge(Frame* frame) {

}

void instruction_if_icmpgt(Frame* frame) {

}

void instruction_if_icmple(Frame* frame) {

}

void instruction_if_acmpeq(Frame* frame) {

}

void instruction_if_acmpne(Frame* frame) {

}

void instruction_goto(Frame* frame) {

}

void instruction_jsr(Frame* frame) {

}

void instruction_ret(Frame* frame) {

}

void instruction_tableswitch(Frame* frame) {

}

void instruction_lookupswitch(Frame* frame) {

}

void instruction_ireturn(Frame* frame) {

}

void instruction_lreturn(Frame* frame) {

}

void instruction_freturn(Frame* frame) {

}

void instruction_dreturn(Frame* frame) {

}

void instruction_areturn(Frame* frame) {

}

void instruction_return(Frame* frame) {
    printf("Executando return\n");

}

void instruction_getstatic(Frame* frame) {
    printf("Executando getstatic\n");
    uint16_t index = findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[frame->pc+1];
    index = (index << 8) | findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[frame->pc+2];
    printf("index: %u\n", index);
    printConstantFF(frame, index-1);

    /*Interpretar o Field Descryptor
    Aqui é definida a saída de 'hello world'
    no caso: stdout*/

    frame->pc += 3;
}

void instruction_putstatic(Frame* frame) {

}

void instruction_getfield(Frame* frame) {

}

void instruction_putfield(Frame* frame) {

}

void instruction_invokevirtual(Frame* frame) {

    printf("Executando invokevirtual\n");
    uint16_t index = findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[frame->pc+1];
    index = (index << 8) | findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[frame->pc+2];
    printf("index: %u\n", index);

    printConstantFF(frame, index-1);

    char* method_descriptor;
    char* parameter_descriptor;
    char* return_descriptor;
    unsigned int i=1;
    unsigned int j;

    method_descriptor = (char*) frame->constant_pool[frame->constant_pool[frame->constant_pool[index-1].CONSTANT.Methodref_info.name_and_type_index -1].CONSTANT.NameAndType_info.descriptor_index -1].CONSTANT.Utf8_info.bytes;

    parameter_descriptor = (char*) malloc (strlen (method_descriptor));
    if (parameter_descriptor==NULL) exit (1);
    return_descriptor = (char*) malloc (strlen (method_descriptor));
    if (return_descriptor==NULL) exit (1);

    while (method_descriptor[i]!=')'){   //get parameter_descriptor
        parameter_descriptor[i-1] = method_descriptor[i];
        i++;
    }
    i++;
    parameter_descriptor[i]='\0';
    j=i;
    while (method_descriptor[i]!='V'){   //get return_descriptor
        return_descriptor[i-j] = method_descriptor[i];
        i++;
    }
    return_descriptor[i-j]='\0';

    if (i==j)
    return_descriptor=NULL;
    printf("method_descriptor: %s\n", method_descriptor);
    printf("parameter_descriptor: %s\n", parameter_descriptor);
    printf("return_descriptor: %s\n", return_descriptor);

    FieldType *FT = NULL;
    FT = read_field_type (parameter_descriptor);
    printf("read field type: %s\n", FT->class_name_ref);
    /*********************************************/

    free(parameter_descriptor);
    free(return_descriptor);
    frame->pc += 3;
}


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




void instruction_invokespecial(Frame* frame) {

}

void instruction_invokestatic(Frame* frame) {

}

void instruction_invokeinterface(Frame* frame) {

}

void instruction_invokedynamic(Frame* frame) {

}

void instruction_new(Frame* frame) {

}

void instruction_newarray(Frame* frame) {

}

void instruction_anewarray(Frame* frame) {

}

void instruction_arraylength(Frame* frame) {

}

void instruction_athrow(Frame* frame) {

}

void instruction_checkcast(Frame* frame) {

}

void instruction_instanceof(Frame* frame) {

}

void instruction_monitorenter(Frame* frame) {

}

void instruction_monitorexit(Frame* frame) {

}

void instruction_wide(Frame* frame) {

}

void instruction_multianewarray(Frame* frame) {

}

void instruction_ifnull(Frame* frame) {

}

void instruction_ifnonnull(Frame* frame) {

}

void instruction_goto_w(Frame* frame) {

}

void instruction_jsr_w(Frame* frame) {

}
