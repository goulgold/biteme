#include "util.h"
#include "instr.h"

int notFinishROB(struct ROB_line *this_ROB) {
    if (this_ROB->busy == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int isFloatInstr(int op) {
    return (op == ADD_D ||
            op == SUB_D ||
            op == MULT_D ||
            op == LD ||
            op == SD
            );
}

int isSubInstr(int op) {
    return (op == SUB ||
            op == SUB_D ||
            op == SUBI);
}


int instr2ALUtype(struct input_instr this_instr) {
    int result;
    int op = this_instr.op;
    switch(op) {
        case ADD:
            result = ALU_ADDI;
            break;
        case ADD_D:
            result = ALU_ADDD;
            break;
        case ADDI:
            result = ALU_ADDI;
            break;
        case SUB:
            result = ALU_ADDI;
            break;
        case SUB_D:
            result = ALU_ADDD;
            break;
        case SUBI:
            result = ALU_ADDD;
            break;
        case MULT:
            result = ALU_MULI;
            break;
        case MULT_D:
            result = ALU_MULD;
            break;
        case DIV:
            result = ALU_DIVI;
            break;
        case DIV_D:
            result = ALU_DIVD;
            break;
        default:
            result = -1;
            break;
    }
    return result;
}

int resetLSQ_line (struct LsQueue_line *this_LSQ) {
    this_LSQ->busy = FALSE;
    this_LSQ->finished = FALSE;
    this_LSQ->instr_type = 0;
    this_LSQ->alu_type = 0;
    this_LSQ->mem_addr = 0;
    this_LSQ->mem_val = 0;
    this_LSQ->data_ready = FALSE;
    this_LSQ->buffer = NULL;
    this_LSQ->dst = NULL;
    this_LSQ->tag_1 = NULL;
    this_LSQ->val_1 = 0;
    this_LSQ->offset = 0;
    this_LSQ->stage = 0;
    this_LSQ->cycle = 0;
    this_LSQ->ttable_index = 0;
    return TRUE;
}