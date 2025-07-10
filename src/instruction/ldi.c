/*
** EPITECH PROJECT, 2025
** ldi
** File description:
** ldi
*/
#include "corewar.h"

static int handle_error(int *params)
{
    if (params[2] != REG_KEY) {
        my_dprintf(2, "ldi: third parameters should be a register.\n");
        return 1;
    }
    if (params[0] == NO_PARAM || params[1] == NO_PARAM ||
        params[0] == DIR_KEY || params[1] == DIR_KEY) {
        my_dprintf(2, "ldi: first and second parameters should"
            " be either a register or an indirect.\n");
        return 1;
    }
    return 0;
}

static int check_register(uint8_t *reg, int offset,
    champ_proc_t *champ, vm_t *vm)
{
    *reg = vm->mem[PC_OFFSET(offset)];
    if (*reg < 1 || *reg > 16) {
        my_dprintf(2, "ldi: invalid register id.\n");
        return 1;
    }
    return 0;
}

static void load_val_and_set_carry(vm_t *vm, champ_proc_t *champ, int32_t res,
    uint8_t reg1)
{
    champ->reg[reg1 - 1] = read_4_bytes(vm->mem,
        (PC + (res % IDX_MOD)) % MEM_SIZE);
    champ->carry = (champ->reg[reg1 - 1] == 0) ? 1 : 0;
}

static void load_param(int *offset, int16_t *val1, int16_t res[2], int type)
{
    if (type == IND_KEY) {
        *val1 = res[0];
        *offset += 2;
    } else {
        *val1 = res[1];
        *offset += 1;
    }
    *val1 = (*val1 < 0) ? *val1 + MEM_SIZE : *val1;
}

int my_ldi(champ_proc_t *champ, vm_t *vm)
{
    int *params = get_param_type(vm->mem[PC_OFFSET(1)], false);
    uint8_t reg1 = 0;
    int16_t val1 = 0;
    int16_t val2 = 0;
    int32_t res = 0;
    int offset = 2;

    if (handle_error(params) == 1)
        return 1;
    load_param(&offset, &val1, (int16_t[2]){read_2_bytes(vm->mem,
        PC_OFFSET(2)), vm->mem[PC_OFFSET(2)]}, params[0]);
    load_param(&offset, &val2, (int16_t[2]){read_2_bytes(vm->mem,
        PC_OFFSET(offset)), vm->mem[PC_OFFSET(offset)]}, params[1]);
    if (check_register(&reg1, offset, champ, vm) == 1)
        return 1;
    res = read_2_bytes(vm->mem,
        ((PC + (val1 % IDX_MOD)) % MEM_SIZE) + val2) % MEM_SIZE;
    load_val_and_set_carry(vm, champ, res, reg1);
    my_free(params);
    return 0;
}
