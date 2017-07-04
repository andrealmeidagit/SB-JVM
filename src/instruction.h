#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "interpreter.h"
#include "frame.h"
#include "constant_pool.h"
#include <string.h>

void (*INSTRUCTION_ARRAY[0xff])();

void initInstructionArray();

void instruction_nop(Frame* frame);
void instruction_aconst_null(Frame* frame);
void instruction_iconst_m1(Frame* frame);
void instruction_iconst_0(Frame* frame);
void instruction_iconst_1(Frame* frame);
void instruction_iconst_2(Frame* frame);
void instruction_iconst_3(Frame* frame);
void instruction_iconst_4(Frame* frame);
void instruction_iconst_5(Frame* frame);
void instruction_lconst_0(Frame* frame);
void instruction_lconst_1(Frame* frame);
void instruction_fconst_0(Frame* frame);
void instruction_fconst_1(Frame* frame);
void instruction_fconst_2(Frame* frame);
void instruction_dconst_0(Frame* frame);
void instruction_dconst_1(Frame* frame);
void instruction_bipush(Frame* frame);
void instruction_sipush(Frame* frame);
void instruction_ldc(Frame* frame);
void instruction_ldc_w(Frame* frame);
void instruction_ldc2_w(Frame* frame);
void instruction_iload(Frame* frame);
void instruction_lload(Frame* frame);
void instruction_fload(Frame* frame);
void instruction_dload(Frame* frame);
void instruction_aload(Frame* frame);
void instruction_iload_0(Frame* frame);
void instruction_iload_1(Frame* frame);
void instruction_iload_2(Frame* frame);
void instruction_iload_3(Frame* frame);
void instruction_lload_0(Frame* frame);
void instruction_lload_1(Frame* frame);
void instruction_lload_2(Frame* frame);
void instruction_lload_3(Frame* frame);
void instruction_fload_0(Frame* frame);
void instruction_fload_1(Frame* frame);
void instruction_fload_2(Frame* frame);
void instruction_fload_3(Frame* frame);
void instruction_dload_0(Frame* frame);
void instruction_dload_1(Frame* frame);
void instruction_dload_2(Frame* frame);
void instruction_dload_3(Frame* frame);
void instruction_aload_0(Frame* frame);
void instruction_aload_1(Frame* frame);
void instruction_aload_2(Frame* frame);
void instruction_aload_3(Frame* frame);
void instruction_iaload(Frame* frame);
void instruction_laload(Frame* frame);
void instruction_faload(Frame* frame);
void instruction_daload(Frame* frame);
void instruction_aaload(Frame* frame);
void instruction_baload(Frame* frame);
void instruction_caload(Frame* frame);
void instruction_saload(Frame* frame);
void instruction_istore(Frame* frame);
void instruction_lstore(Frame* frame);
void instruction_fstore(Frame* frame);
void instruction_dstore(Frame* frame);
void instruction_astore(Frame* frame);
void instruction_istore_0(Frame* frame);
void instruction_istore_1(Frame* frame);
void instruction_istore_2(Frame* frame);
void instruction_istore_3(Frame* frame);
void instruction_lstore_0(Frame* frame);
void instruction_lstore_1(Frame* frame);
void instruction_lstore_2(Frame* frame);
void instruction_lstore_3(Frame* frame);
void instruction_fstore_0(Frame* frame);
void instruction_fstore_1(Frame* frame);
void instruction_fstore_2(Frame* frame);
void instruction_fstore_3(Frame* frame);
void instruction_dstore_0(Frame* frame);
void instruction_dstore_1(Frame* frame);
void instruction_dstore_2(Frame* frame);
void instruction_dstore_3(Frame* frame);
void instruction_astore_0(Frame* frame);
void instruction_astore_1(Frame* frame);
void instruction_astore_2(Frame* frame);
void instruction_astore_3(Frame* frame);
void instruction_iastore(Frame* frame);
void instruction_lastore(Frame* frame);
void instruction_fastore(Frame* frame);
void instruction_dastore(Frame* frame);
void instruction_aastore(Frame* frame);
void instruction_bastore(Frame* frame);
void instruction_castore(Frame* frame);
void instruction_sastore(Frame* frame);
void instruction_pop(Frame* frame);
void instruction_pop2(Frame* frame);
void instruction_dup(Frame* frame);
void instruction_dup_x1(Frame* frame);
void instruction_dup_x2(Frame* frame);
void instruction_dup2(Frame* frame);
void instruction_dup2_x1(Frame* frame);
void instruction_dup2_x2(Frame* frame);
void instruction_swap(Frame* frame);
void instruction_iadd(Frame* frame);
void instruction_ladd(Frame* frame);
void instruction_fadd(Frame* frame);
void instruction_dadd(Frame* frame);
void instruction_isub(Frame* frame);
void instruction_lsub(Frame* frame);
void instruction_fsub(Frame* frame);
void instruction_dsub(Frame* frame);
void instruction_imul(Frame* frame);
void instruction_lmul(Frame* frame);
void instruction_fmul(Frame* frame);
void instruction_dmul(Frame* frame);
void instruction_idiv(Frame* frame);
void instruction_ldiv(Frame* frame);
void instruction_fdiv(Frame* frame);
void instruction_ddiv(Frame* frame);
void instruction_irem(Frame* frame);
void instruction_lrem(Frame* frame);
void instruction_frem(Frame* frame);
void instruction_drem(Frame* frame);
void instruction_ineg(Frame* frame);
void instruction_lneg(Frame* frame);
void instruction_fneg(Frame* frame);
void instruction_dneg(Frame* frame);
void instruction_ishl(Frame* frame);
void instruction_lshl(Frame* frame);
void instruction_ishr(Frame* frame);
void instruction_lshr(Frame* frame);
void instruction_iushr(Frame* frame);
void instruction_lushr(Frame* frame);
void instruction_iand(Frame* frame);
void instruction_land(Frame* frame);
void instruction_ior(Frame* frame);
void instruction_lor(Frame* frame);
void instruction_ixor(Frame* frame);
void instruction_lxor(Frame* frame);
void instruction_iinc(Frame* frame);
void instruction_i2l(Frame* frame);
void instruction_i2f(Frame* frame);
void instruction_i2d(Frame* frame);
void instruction_l2i(Frame* frame);
void instruction_l2f(Frame* frame);
void instruction_l2d(Frame* frame);
void instruction_f2i(Frame* frame);
void instruction_f2l(Frame* frame);
void instruction_f2d(Frame* frame);
void instruction_d2i(Frame* frame);
void instruction_d2l(Frame* frame);
void instruction_d2f(Frame* frame);
void instruction_i2b(Frame* frame);
void instruction_i2c(Frame* frame);
void instruction_i2s(Frame* frame);
void instruction_lcmp(Frame* frame);
void instruction_fcmpl(Frame* frame);
void instruction_fcmpg(Frame* frame);
void instruction_dcmpl(Frame* frame);
void instruction_dcmpg(Frame* frame);
void instruction_ifeq(Frame* frame);
void instruction_ifne(Frame* frame);
void instruction_iflt(Frame* frame);
void instruction_ifge(Frame* frame);
void instruction_ifgt(Frame* frame);
void instruction_ifle(Frame* frame);
void instruction_if_icmpeq(Frame* frame);
void instruction_if_icmpne(Frame* frame);
void instruction_if_icmplt(Frame* frame);
void instruction_if_icmpge(Frame* frame);
void instruction_if_icmpgt(Frame* frame);
void instruction_if_icmple(Frame* frame);
void instruction_if_acmpeq(Frame* frame);
void instruction_if_acmpne(Frame* frame);
void instruction_goto(Frame* frame);
void instruction_jsr(Frame* frame);
void instruction_ret(Frame* frame);
void instruction_tableswitch(Frame* frame);
void instruction_lookupswitch(Frame* frame);
void instruction_ireturn(Frame* frame);
void instruction_lreturn(Frame* frame);
void instruction_freturn(Frame* frame);
void instruction_dreturn(Frame* frame);
void instruction_areturn(Frame* frame);
void instruction_return(Frame* frame);
void instruction_getstatic(Frame* frame);
void instruction_putstatic(Frame* frame);
void instruction_getfield(Frame* frame);
void instruction_putfield(Frame* frame);
void instruction_invokevirtual(Frame* frame);
void instruction_invokespecial(Frame* frame);
void instruction_invokestatic(Frame* frame);
void instruction_invokeinterface(Frame* frame);
void instruction_invokedynamic(Frame* frame);
void instruction_new(Frame* frame);
void instruction_newarray(Frame* frame);
void instruction_anewarray(Frame* frame);
void instruction_arraylength(Frame* frame);
void instruction_athrow(Frame* frame);
void instruction_checkcast(Frame* frame);
void instruction_instanceof(Frame* frame);
void instruction_monitorenter(Frame* frame);
void instruction_monitorexit(Frame* frame);
void instruction_wide(Frame* frame);
void instruction_multianewarray(Frame* frame);
void instruction_ifnull(Frame* frame);
void instruction_ifnonnull(Frame* frame);
void instruction_goto_w(Frame* frame);
void instruction_jsr_w(Frame* frame);



typedef union FieldType{
    int8_t    byte_type;
    char      char_type;
    double    double_type;
    float     float_type;
    int       integer_type;
    long int  long_type;
    char*     class_name_ref;
    short int short_type;
    int8_t    bool_type;
    char*     array_ref; /*?*/
}FieldType;

//Funções auxiliares
FieldType* read_field_type (char* str);



#endif /* INSTRUCTION_H_ */
