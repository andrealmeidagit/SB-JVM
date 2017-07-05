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

void instruction_nop(Frame* frame, ClassFile* class_files, int class_files_count) {
    frame->pc += 1;
}

void instruction_aconst_null(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    pushOperand(frame, newOperand(0));
    frame->pc += 1;
}

void instruction_iconst_m1(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(fromInt32(-1)));
    frame->pc+=1;
}

void instruction_iconst_0(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(0));
    frame->pc+=1;
}

void instruction_iconst_1(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(1));
    frame->pc+=1;
}

void instruction_iconst_2(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(2));
    frame->pc+=1;
}

void instruction_iconst_3(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(3));
    frame->pc+=1;
}

void instruction_iconst_4(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(4));
    frame->pc+=1;
}

void instruction_iconst_5(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(5));
    frame->pc+=1;
}

void instruction_lconst_0(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    pushOperand(frame, newOperand(0));
    pushOperand(frame, newOperand(0));
    frame->pc++;
}

void instruction_lconst_1(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    pushOperand(frame, newOperand(0));
    pushOperand(frame, newOperand(1));
    frame->pc++;
}

void instruction_fconst_0(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    pushOperand(frame, newOperand(0));
    frame->pc++;
}

void instruction_fconst_1(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    pushOperand(frame, newOperand(fromFloat(1)));
    frame->pc++;
}

void instruction_fconst_2(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    pushOperand(frame, newOperand(fromFloat(2)));
    frame->pc++;
}

void instruction_dconst_0(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    pushOperand(frame, newOperand(0));
    pushOperand(frame, newOperand(0));
    frame->pc++;
}

void instruction_dconst_1(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    uint64_t num = fromDouble(1);
    pushOperand(frame, newOperand(num >> 32));
    pushOperand(frame, newOperand(num & 0x00000000FFFFFFFF));
    frame->pc++;
}

void instruction_bipush(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint8_t data = getByteAt(frame, frame->pc+1);
    pushOperand(frame, newOperand(data));
    frame->pc += 2;
}

void instruction_sipush(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint16_t data = getByteAt(frame, frame->pc+1);
    uint16_t data2 = getByteAt(frame, frame->pc+2);
    pushOperand(frame, newOperand(fromInt16((toInt16(data)<<8)|toInt16(data2))));
    // printf("%d \n", ((toInt16(data)<<8)|toInt16(data2)));
    frame->pc += 3;
}

void instruction_ldc(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint8_t constant_pool_index = getByteAt(frame, frame->pc + 1);
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

void instruction_ldc_w(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    uint16_t constant_pool_index = getByteAt(frame, frame->pc+1);
    constant_pool_index = constant_pool_index << 8 | getByteAt(frame, frame->pc+2);
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
    frame->pc += 3;
}

void instruction_ldc2_w(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint16_t index = getByteAt(frame, frame->pc+1);
    index = (index << 8) | getByteAt(frame, frame->pc+2);
    ConstantInfo cp_info = frame->constant_pool[index-1];
    pushOperand(frame, newOperand(cp_info.CONSTANT.Long_info.high_bytes));
    pushOperand(frame, newOperand(cp_info.CONSTANT.Long_info.low_bytes));
    frame->pc += 3;
}

void instruction_iload(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    uint8_t index = getByteAt(frame, frame->pc+1);
    pushOperand(frame, newOperand(frame->local_variables[index]));
    frame->pc += 2;
}

void instruction_lload(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    uint8_t index = getByteAt(frame, frame->pc+1);

    printf ("lload: %lld\n", ((uint64_t)frame->local_variables[index] << 32 | frame->local_variables[index+1]) );
    pushOperand(frame, newOperand(frame->local_variables[index]));
    pushOperand(frame, newOperand(frame->local_variables[index+1]));
    frame->pc += 2;
}

void instruction_fload(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    uint8_t index = getByteAt(frame, frame->pc+1);
    pushOperand(frame, newOperand(frame->local_variables[index]));
    frame->pc += 2;
}

void instruction_dload(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    uint8_t index = getByteAt(frame, frame->pc+1);
    pushOperand(frame, newOperand(frame->local_variables[index]));
    pushOperand(frame, newOperand(frame->local_variables[index+1]));
    frame->pc += 2;
}

void instruction_aload(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_iload_0(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[0]));
    frame->pc+=1;
}

void instruction_iload_1(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[1]));
    printf("ILOAD1: %d\n", toInt32(frame->local_variables[1]));
    frame->pc+=1;
}

void instruction_iload_2(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[2]));
    frame->pc+=1;
}

void instruction_iload_3(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[3]));
    frame->pc+=1;
}

void instruction_lload_0(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[0]));
    pushOperand(frame, newOperand(frame->local_variables[1]));
    frame->pc += 1;
}

void instruction_lload_1(Frame* frame, ClassFile* class_files, int class_files_count) {
    UNTESTED_INSTRUCTION_WARNING;
    pushOperand(frame, newOperand(frame->local_variables[1]));
    pushOperand(frame, newOperand(frame->local_variables[2]));
    frame->pc += 1;
}

void instruction_lload_2(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[2]));
    pushOperand(frame, newOperand(frame->local_variables[3]));
    frame->pc += 1;
}

void instruction_lload_3(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[3]));
    pushOperand(frame, newOperand(frame->local_variables[4]));
    frame->pc += 1;
}

void instruction_fload_0(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[0]));
    frame->pc += 1;
}

void instruction_fload_1(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[1]));
    frame->pc += 1;
}

void instruction_fload_2(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[2]));
    frame->pc += 1;
}

void instruction_fload_3(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[3]));
    frame->pc += 1;
}

void instruction_dload_0(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[0]));
    pushOperand(frame, newOperand(frame->local_variables[1]));
    frame->pc += 1;
}

void instruction_dload_1(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[1]));
    pushOperand(frame, newOperand(frame->local_variables[2]));
    frame->pc += 1;
}

void instruction_dload_2(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[2]));
    pushOperand(frame, newOperand(frame->local_variables[3]));
    frame->pc += 1;
}

void instruction_dload_3(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame, newOperand(frame->local_variables[3]));
    pushOperand(frame, newOperand(frame->local_variables[4]));
    frame->pc += 1;
}

void instruction_aload_0(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_aload_1(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_aload_2(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_aload_3(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_iaload(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_laload(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_faload(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_daload(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_aaload(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_baload(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_caload(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_saload(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_istore(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    uint8_t index = getByteAt(frame, frame->pc+1);
    frame->local_variables[index]=op->data;
    free (op);
    frame->pc+=2;
}

void instruction_lstore(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame); //lo
    OperandInfo *op = popOperand(frame); //hi
    uint8_t index = getByteAt(frame, frame->pc+1);
    frame->local_variables[index]=op->data;
    frame->local_variables[index+1]=op2->data;
    free (op2);
    free (op);
    frame->pc+=2;
}

void instruction_fstore(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    uint8_t index = getByteAt(frame, frame->pc+1);
    frame->local_variables[index]=op->data;
    free (op);
    frame->pc+=2;
}

void instruction_dstore(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame); //lo
    OperandInfo *op = popOperand(frame); //hi
    uint8_t index = getByteAt(frame, frame->pc+1);
    frame->local_variables[index]=op->data;
    frame->local_variables[index+1]=op2->data;
    free (op2);
    free (op);
    frame->pc+=2;
}

void instruction_astore(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_istore_0(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    frame->local_variables[0]=op->data;
    free (op);
    frame->pc+=1;
}

void instruction_istore_1(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    frame->local_variables[1]=op->data;
    free (op);
    frame->pc+=1;
}

void instruction_istore_2(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    frame->local_variables[2]=op->data;
    free (op);
    frame->pc+=1;
}

void instruction_istore_3(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    frame->local_variables[3]=op->data;
    free (op);
    frame->pc+=1;
}

void instruction_lstore_0(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame); //lo
    OperandInfo *op = popOperand(frame); //hi
    frame->local_variables[0]=op->data;
    frame->local_variables[1]=op2->data;
    free (op2);
    free (op);
    frame->pc+=1;
}

void instruction_lstore_1(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame); //lo
    OperandInfo *op = popOperand(frame); //hi
    frame->local_variables[1]=op->data;
    frame->local_variables[2]=op2->data;
    free (op2);
    free (op);
    frame->pc+=1;
}

void instruction_lstore_2(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame); //lo
    OperandInfo *op = popOperand(frame); //hi
    frame->local_variables[2]=op->data;
    frame->local_variables[3]=op2->data;
    free (op2);
    free (op);
    frame->pc+=1;
}

void instruction_lstore_3(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame); //lo
    OperandInfo *op = popOperand(frame); //hi
    frame->local_variables[3]=op->data;
    frame->local_variables[4]=op2->data;
    free (op2);
    free (op);
    frame->pc+=1;
}

void instruction_fstore_0(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    frame->local_variables[0]=op->data;
    free (op);
    frame->pc+=1;
}

void instruction_fstore_1(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    frame->local_variables[1]=op->data;
    free (op);
    frame->pc+=1;
}

void instruction_fstore_2(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    frame->local_variables[2]=op->data;
    free (op);
    frame->pc+=1;
}

void instruction_fstore_3(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    frame->local_variables[3]=op->data;
    free (op);
    frame->pc+=1;
}

void instruction_dstore_0(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame); //lo
    OperandInfo *op = popOperand(frame); //hi
    frame->local_variables[0]=op->data;
    frame->local_variables[1]=op2->data;
    free (op2);
    free (op);
    frame->pc+=1;
}

void instruction_dstore_1(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame); //lo
    OperandInfo *op = popOperand(frame); //hi
    frame->local_variables[1]=op->data;
    frame->local_variables[2]=op2->data;
    free (op2);
    free (op);
    frame->pc+=1;
}

void instruction_dstore_2(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame); //lo
    OperandInfo *op = popOperand(frame); //hi
    frame->local_variables[2]=op->data;
    frame->local_variables[3]=op2->data;
    free (op2);
    free (op);
    frame->pc+=1;
}

void instruction_dstore_3(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame); //lo
    OperandInfo *op = popOperand(frame); //hi
    frame->local_variables[3]=op->data;
    frame->local_variables[4]=op2->data;
    free (op2);
    free (op);
    frame->pc+=1;
}

void instruction_astore_0(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_astore_1(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_astore_2(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_astore_3(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_iastore(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op_value = popOperand(frame);
    OperandInfo *op_index = popOperand(frame);
    OperandInfo *op_array = popOperand(frame);
    int32_t * apointer = (int32_t *) toPointer(op_array->data);
    if (apointer == NULL){
        fprintf(stderr, "INSTRUCTION IASTORE: NullPointerException\n");
        exit(EXIT_FAILURE);
    }
    apointer[op_index->data] = toInt32 (op_value->data);
    frame->pc+=1;
}

void instruction_lastore(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_fastore(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_dastore(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_aastore(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_bastore(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_castore(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_sastore(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_pop(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_pop2(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_dup(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo * op = popOperand(frame);
    OperandInfo * op2 = newOperand(op->data);
    op2->ispointer = op->ispointer;
    pushOperand(frame, op);
    pushOperand(frame, op2);
    frame->pc+=1;
}

void instruction_dup_x1(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_dup_x2(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_dup2(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_dup2_x1(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_dup2_x2(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_swap(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_iadd(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) + toInt32(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_ladd(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    int64_t num1 = toInt64((high1 << 32) | low1);
    int64_t num2 = toInt64((high2 << 32) | low2);
    uint64_t result = fromInt64(num1 + num2);
    printf("ladd result: %lld\n", toInt64(result));
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_fadd(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromFloat(toFloat(op->data) + toFloat(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_dadd(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    double num1 = toDouble((high1 << 32) | low1);
    double num2 = toDouble((high2 << 32) | low2);
    uint64_t result = fromDouble(num1 + num2);
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_isub(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) - toInt32(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_lsub(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    int64_t num1 = toInt64((high1 << 32) | low1);
    int64_t num2 = toInt64((high2 << 32) | low2);
    uint64_t result = fromInt64(num1 - num2);
    printf("lsub result: %lld\n", toInt64(result));
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_fsub(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromFloat(toFloat(op->data) - toFloat(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_dsub(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    double num1 = toDouble((high1 << 32) | low1);
    double num2 = toDouble((high2 << 32) | low2);
    uint64_t result = fromDouble(num1 - num2);
    printf("dsub result: %lf\n", toDouble(result));
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_imul(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) * toInt32(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_lmul(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    int64_t num1 = toInt64((high1 << 32) | low1);
    int64_t num2 = toInt64((high2 << 32) | low2);
    uint64_t result = fromInt64(num1 * num2);
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_fmul(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromFloat(toFloat(op->data) * toFloat(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_dmul(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    double num1 = toDouble((high1 << 32) | low1);
    double num2 = toDouble((high2 << 32) | low2);
    uint64_t result = fromDouble(num1 * num2);
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_idiv(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) / toInt32(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_ldiv(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    int64_t num1 = toInt64((high1 << 32) | low1);
    int64_t num2 = toInt64((high2 << 32) | low2);
    uint64_t result = fromInt64(num1 / num2);
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_fdiv(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromFloat(toFloat(op->data) / toFloat(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_ddiv(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    double num1 = toDouble((high1 << 32) | low1);
    double num2 = toDouble((high2 << 32) | low2);
    uint64_t result = fromDouble(num1 / num2);
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_irem(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) -
    (toInt32(op->data)/toInt32(op2->data)) *
    toInt32(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_lrem(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    int64_t num1 = toInt64((high1 << 32) | low1);
    int64_t num2 = toInt64((high2 << 32) | low2);
    uint64_t result = fromInt64(num1 - (num1/num2) * num2);
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_frem(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) -
    (toInt32(op->data)/toInt32(op2->data)) *
    toInt32(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_drem(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    double num1 = toDouble((high1 << 32) | low1);
    double num2 = toDouble((high2 << 32) | low2);
    uint64_t result = fromDouble(num1 - (num1/num2) * num2);
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_ineg(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    op->data = fromInt32(0 - toInt32(op->data));
    pushOperand(frame, op);
    frame->pc++;
}

void instruction_lneg(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1;
    OperandInfo *op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    int64_t num1 = toInt64((high1 << 32) | low1);
    uint64_t result = fromInt64(0 - num1);
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_fneg(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    op->data = fromInt32(0 - toInt32(op->data));
    pushOperand(frame, op);
    frame->pc++;
}

void instruction_dneg(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1;
    OperandInfo *op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    double num1 = toDouble((high1 << 32) | low1);
    uint64_t result = fromDouble(0 - num1);
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_ishl(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) << (toInt32(op2->data) & 0x1F));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_lshl(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    int64_t num1 = toInt64((high1 << 32) | low1);
    int64_t num2 = toInt64((high2 << 32) | low2);
    uint64_t result = fromInt64(num1 << (num2 & 0x3F));
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_ishr(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    // printf("***********************************************************\n");
    // printf ("OP1: %d\tOP2: %d",toInt32(op->data),toInt32(op2->data));
    op->data = fromInt32(toInt32(op->data) >> (toInt32(op2->data) & 0x1F));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_lshr(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    int64_t num1 = toInt64((high1 << 32) | low1);
    int64_t num2 = toInt64((high2 << 32) | low2);
    uint64_t result = fromInt64(num1 >> (num2 & 0x3F));
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_iushr(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_lushr(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_iand(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) & toInt32(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_land(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    int64_t num1 = toInt64((high1 << 32) | low1);
    int64_t num2 = toInt64((high2 << 32) | low2);
    uint64_t result = fromInt64(num1 & num2);
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_ior(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) | toInt32(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_lor(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    int64_t num1 = toInt64((high1 << 32) | low1);
    int64_t num2 = toInt64((high2 << 32) | low2);
    uint64_t result = fromInt64(num1 | num2);
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_ixor(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);

    op->data = fromInt32(toInt32(op->data) ^ toInt32(op2->data));

    pushOperand(frame, op);
    free(op2);

    frame->pc+=1;
}

void instruction_lxor(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint64_t high1, low1, high2, low2;
    OperandInfo *op = popOperand(frame); low2 = op->data; free(op);
    op = popOperand(frame); high2 = op->data; free(op);
    op = popOperand(frame); low1 = op->data; free(op);
    op = popOperand(frame); high1 = op->data; free(op);
    int64_t num1 = toInt64((high1 << 32) | low1);
    int64_t num2 = toInt64((high2 << 32) | low2);
    uint64_t result = fromInt64(num1 ^ num2);
    uint64_t high_res = result >> 32;
    uint64_t low_res = result & 0x00000000FFFFFFFF;
    pushOperand(frame, newOperand(high_res));
    pushOperand(frame, newOperand(low_res));
    frame->pc++;
}

void instruction_iinc(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint32_t index = getByteAt(frame, frame->pc+1);
    int32_t value = toInt8(getByteAt(frame, frame->pc+2));
    frame->local_variables[index] = fromInt32(toInt32(frame->local_variables[index]) + value);
    frame->pc+=3;
}

void instruction_i2l(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    uint64_t aux = fromInt64((uint64_t)toInt32(op->data));
    OperandInfo *op2 = newOperand((uint32_t)aux);
    op->data = (uint32_t)(aux >> 32); //hi
    pushOperand (frame, op2);
    pushOperand (frame, op);
    frame->pc+=1;
}

void instruction_i2f(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    op->data = fromFloat((float)(toInt32(op->data)));
    pushOperand (frame, op);
    frame->pc+=1;
}

void instruction_i2d(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    uint64_t aux = fromDouble((double)toInt32(op->data));
    OperandInfo *op2 = newOperand((uint32_t)aux);

    op->data = (uint32_t)(aux >> 32); //hi

    // printf("->i2d: %d\n", toInt32(op->data));
    pushOperand (frame, op2);
    pushOperand (frame, op);
    frame->pc+=1;
}

void instruction_l2i(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_l2f(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_l2d(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_f2i(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_f2l(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_f2d(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_d2i(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_d2l(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_d2f(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_i2b(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_i2c(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op = popOperand(frame);
    printf("eh noix %d/n", toInt32(op->data));
    op->data = op->data & 0x0000FFFF;
    pushOperand(frame, op);
    frame->pc+=1;
}

void instruction_i2s(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_lcmp(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_fcmpl(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_fcmpg(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_dcmpl(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_dcmpg(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_ifeq(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_ifne(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_iflt(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_ifge(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_ifgt(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_ifle(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_if_icmpeq(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);
    uint16_t branch;

    if(toInt32(op->data) == toInt32(op2->data))
    {
        branch = getByteAt(frame, frame->pc+1);
        branch = (branch << 8) | getByteAt(frame, frame->pc+2);
        frame->pc += toInt16(branch);
    }
    else {
        frame->pc += 3;
    }
    free(op);
    free(op2);
}

void instruction_if_icmpne(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);
    uint16_t branch;

    if(toInt32(op->data) != toInt32(op2->data))
    {
        branch = getByteAt(frame, frame->pc+1);
        branch = (branch << 8) | getByteAt(frame, frame->pc+2);
        frame->pc += toInt16(branch);
    }
    else {
        frame->pc += 3;
    }

    free(op);
    free(op2);
}

void instruction_if_icmplt(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);
    uint16_t branch;

    if(toInt32(op->data) < toInt32(op2->data))
    {
        branch = getByteAt(frame, frame->pc+1);
        branch = (branch << 8) | getByteAt(frame, frame->pc+2);
        frame->pc += toInt16(branch);
    }
    else {
        frame->pc += 3;
    }

    free(op);
    free(op2);
}

void instruction_if_icmpge(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);
    uint16_t branch;

    if(toInt32(op->data) >= toInt32(op2->data))
    {
        branch = getByteAt(frame, frame->pc+1);
        branch = (branch << 8) | getByteAt(frame, frame->pc+2);
        frame->pc += toInt16(branch);
    }
    else {
        frame->pc += 3;
    }

    free(op);
    free(op2);
}

void instruction_if_icmpgt(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);
    uint16_t branch;

    if(toInt32(op->data) > toInt32(op2->data))
    {
        branch = getByteAt(frame, frame->pc+1);
        branch = (branch << 8) | getByteAt(frame, frame->pc+2);
        frame->pc += toInt16(branch);
    }
    else {
        frame->pc += 3;
    }

    free(op);
    free(op2);
}

void instruction_if_icmple(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo *op2 = popOperand(frame);
    OperandInfo *op = popOperand(frame);
    uint16_t branch;

    if(toInt32(op->data) <= toInt32(op2->data))
    {
        branch = getByteAt(frame, frame->pc+1);
        branch = (branch << 8) | getByteAt(frame, frame->pc+2);
        frame->pc += toInt16(branch);
    }
    else {
        frame->pc += 3;
    }

    free(op);
    free(op2);
}

void instruction_if_acmpeq(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_if_acmpne(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_goto(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint16_t branch;
    branch = getByteAt(frame, frame->pc+1);
    branch = (branch << 8) | getByteAt(frame, frame->pc+2);
    frame->pc += toInt16(branch);
}

void instruction_jsr(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_ret(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_tableswitch(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_lookupswitch(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_ireturn(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame->previous, popOperand(frame));
}

void instruction_lreturn(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo* op2 = popOperand(frame);
    OperandInfo* op1 = popOperand(frame);
    pushOperand(frame->previous, op1);
    pushOperand(frame->previous, op2);
}

void instruction_freturn(Frame* frame, ClassFile* class_files, int class_files_count) {
    pushOperand(frame->previous, popOperand(frame));
}

void instruction_dreturn(Frame* frame, ClassFile* class_files, int class_files_count) {
    OperandInfo* op2 = popOperand(frame);
    OperandInfo* op1 = popOperand(frame);
    pushOperand(frame->previous, op1);
    pushOperand(frame->previous, op2);
}

void instruction_areturn(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_return(Frame* frame, ClassFile* class_files, int class_files_count) {}

void instruction_getstatic(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint16_t index = findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[frame->pc+1];
    index = (index << 8) | findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[frame->pc+2];
    printf("index: %u\n", index);
    printConstantFF(frame, index-1);
    frame->pc += 3;
}

void instruction_putstatic(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_getfield(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_putfield(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_invokevirtual(Frame* frame, ClassFile* class_files, int class_files_count) {
    int verbose = 1;

    uint16_t i=1;
    uint16_t j, k, y;
    uint64_t aux_double, aux_long;
    char * method_descriptor;
    char * parameter_descriptor;
    char * return_descriptor;
    char * aux;
    OperandInfo *op = (OperandInfo*) malloc(sizeof(OperandInfo));
    OperandInfo *op2 = (OperandInfo*) malloc(sizeof(OperandInfo));


    uint16_t index = findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[frame->pc+1];
    index = (index << 8) | findCodeAttribute(frame->method_info, frame->constant_pool)->u.Code.code[frame->pc+2];

    printf("Constant Pool index: %u\n", index);

    if (verbose)
        printConstantFF(frame, index-1);

    //******** method_descriptor **********//
    k = frame->constant_pool[index-1].CONSTANT.Methodref_info.name_and_type_index - 1;
    y = frame->constant_pool[k].CONSTANT.NameAndType_info.descriptor_index - 1;
    method_descriptor = (char*) frame->constant_pool[y].CONSTANT.Utf8_info.bytes;

    //******** parameter_descriptor **********//
    parameter_descriptor = (char*) malloc (strlen (method_descriptor));
    if (parameter_descriptor == NULL) exit (1);
    while (method_descriptor[i]!=')'){   //get parameter_descriptor
        parameter_descriptor[i-1] = method_descriptor[i];
        i++;
    }
    i++;
    parameter_descriptor[i]='\0';

    //******** return_descriptor **********//
    return_descriptor = (char*) malloc (strlen (method_descriptor));
    if (return_descriptor==NULL) exit (1);
    j=i;
    while (method_descriptor[i]!='V'){   //get return_descriptor
        return_descriptor[i-j] = method_descriptor[i];
        i++;
    }
    return_descriptor[i-j]='\0';
    if (i==j) return_descriptor=NULL;

    //*********************************//

    if (verbose)
        printf("method_descriptor: %s\n", method_descriptor);
    if (verbose)
        printf("parameter_descriptor: %s\n", parameter_descriptor);
    if (verbose)
        printf("return_descriptor: %s\n", return_descriptor);

    //********************************//

    switch (parameter_descriptor[0])
    {
        case 'B':
            printf("implementar field_type->byte\n" );
            break;
        case 'C':
            printf("implementar field_type->char\n" );
            op = popOperand(frame);
            // printUTF8
            printf ("CHAR: %c\n", ((char)(op->data))+1);
            break;
        case 'D':
            op = popOperand(frame);
            op2 = popOperand(frame);
            aux_double = ((uint64_t)op2->data) << 32;
            aux_double = aux_double | (uint64_t)op->data;
            printf("%lf\n", toDouble(aux_double));
            break;
        case 'F':
            op = popOperand(frame);
            printf("%f\n", toFloat(op->data));
            break;
        case 'I':
            op = popOperand(frame);
            printf("%d\n", toInt32(op->data));
            break;
        case 'J':
            op = popOperand(frame);
            op2 = popOperand(frame);
            aux_long = ((uint64_t)op2->data) << 32;
            aux_long = aux_long | (uint64_t)op->data;
            printf("%lld\n", toInt64(aux_long));
            break;
        case 'L':
            aux = (char*) malloc (strlen(parameter_descriptor)-2);
            for (i = 0, j = 1; i<strlen(parameter_descriptor)-2; i++, j++)
            {
                aux[i]=parameter_descriptor[j];
            }
            aux[i]='\0';
            // puts (aux);
            op = popOperand(frame);
            if (strcmp (aux, "java/lang/String")==0)
            {
                print_from_index(frame, op->data-1);
                printf("\n");

            }else
            {
                printf("Case 'java/io/PrintStream'. Do nothing.\n");
            }

            break;
        case 'S':
            printf("implementar field_type->short\n" );
            break;
        case 'Z':
            printf("implementar field_type->bool\n" );
            break;
        case '[':
            printf("implementar field_type->array\n" );
            break;
        default:
            printf("FIELD TYPE DOES NOT EXIST!!! Base Type Character:%c\n", parameter_descriptor[0]);
            exit(EXIT_FAILURE);
    }

    /*********************************************/
    // free(method_descriptor);
    // free(parameter_descriptor);
    // free(return_descriptor);
    // free(op);
    frame->pc += 3;
}

void instruction_invokespecial(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_invokestatic(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint16_t index = getByteAt(frame, frame->pc+1);
    index = (index << 8) | getByteAt(frame, frame->pc+2);
    /**** Constant pool reference search ****/
    ConstantInfo method_ref = frame->constant_pool[index-1];
    ConstantInfo class = frame->constant_pool[method_ref.CONSTANT.Methodref_info.class_index - 1];
    ConstantInfo name_and_type = frame->constant_pool[method_ref.CONSTANT.Methodref_info.name_and_type_index - 1];
    char* class_name = (char*)frame->constant_pool[class.CONSTANT.Class_info.name_index-1].CONSTANT.Utf8_info.bytes;
    char* method_name = (char*)frame->constant_pool[name_and_type.CONSTANT.NameAndType_info.name_index -1].CONSTANT.Utf8_info.bytes;
    char* method_descriptor = (char*)frame->constant_pool[name_and_type.CONSTANT.NameAndType_info.descriptor_index-1].CONSTANT.Utf8_info.bytes;
    /**** Find the target class file and method info ****/
    ClassFile* target_class_file = findClassFile(class_name, class_files, class_files_count);
    MethodInfo* target_method_info = findMethodWithDesc(method_name, method_descriptor, target_class_file);
    Frame* new_frame = newFrame(target_class_file, target_method_info, frame);
    /**** Calculate argument amount and transfer them to new frame's local variable array ****/
    uint32_t argument_amount = argumentAmountFromDescriptor(method_descriptor);
    for (int i = argument_amount - 1; i >= 0; --i) {
        OperandInfo* op = popOperand(frame);
        new_frame->local_variables[i] = op->data;
        free(op);
    }
    runFrame(new_frame, class_files, class_files_count);
    freeFrame(new_frame);
    frame->pc += 3;
}

void instruction_invokeinterface(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_invokedynamic(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_new(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_newarray(Frame* frame, ClassFile* class_files, int class_files_count) {
    uint16_t count, atype;

    void* pointer  = NULL;

    OperandInfo * op = popOperand(frame);
    count = op->data;
    free(op);

    if (count < 0) {
      fprintf(stderr, "INSTRUCTION NEWARRAY: NegativeArraySizeException\n");
      exit(EXIT_FAILURE);
    }
    atype = getByteAt(frame, frame->pc+1);

    const int T_BOOLEAN =  4;
    const int T_CHAR    =  5;
    const int T_FLOAT   =  6;
    const int T_DOUBLE  =  7;
    const int T_BYTE    =  8;
    const int T_SHORT   =  9;
    const int T_INT     =  10;
    const int T_LONG    =  11;

    if(atype == T_BOOLEAN || atype == T_BYTE)
        pointer = calloc(count, sizeof(uint8_t));
    else if(atype == T_CHAR || atype == T_SHORT)
        pointer = calloc (count, sizeof(uint16_t));
    else if(atype == T_FLOAT || atype == T_INT)
        pointer = calloc (count, sizeof(uint32_t));
    else if(atype == T_DOUBLE || atype == T_LONG)
        pointer = calloc (count, sizeof(uint64_t));
    else{
      fprintf(stderr, "INSTRUCTION NEWARRAY: Invalid ATYPE\n");
      exit(EXIT_FAILURE);
    }

    op = newOperand(fromPointer(pointer));
    op->ispointer = 1;
    pushOperand(frame, op);
    frame->pc += 2;
}

void instruction_anewarray(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_arraylength(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_athrow(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_checkcast(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_instanceof(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_monitorenter(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_monitorexit(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_wide(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_multianewarray(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_ifnull(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_ifnonnull(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_goto_w(Frame* frame, ClassFile* class_files, int class_files_count) {

}

void instruction_jsr_w(Frame* frame, ClassFile* class_files, int class_files_count) {

}
