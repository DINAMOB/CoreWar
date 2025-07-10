/*
** EPITECH PROJECT, 2025
** sti
** File description:
** sti
*/
#include "corewar.h"

static int handle_error(int *params, uint8_t reg)
{
    if (!params)
        return 1;
    if (params[0] != REG_KEY) {
        my_dprintf(2, "sti: first parameter should be a register.\n");
        return 1;
    }
    if (reg < 1 || reg > 16) {
        my_dprintf(2, "sti: invalid register id.\n");
        return 1;
    }
    if (params[1] == NO_PARAM || params[1] == DIR_KEY ||
        params[2] == NO_PARAM || params[2] == DIR_KEY) {
        my_dprintf(2, "sti: error invalid parameter the second and third"
            " parameters should be a register or an indirect.\n");
        return 1;
    }
    return 0;
}

static int load_val_if_reg(int *params, int32_t *val1, int32_t *val2,
    champ_proc_t *champ)
{
    if (params[1] == REG_KEY) {
        if (*val1 < 1 || *val1 > 16)
            return 1;
        *val1 = champ->reg[*val1 - 1];
    }
    if (params[2] == REG_KEY) {
        if (*val2 < 1 || *val2 > 16)
            return 1;
        *val2 = champ->reg[*val2 - 1];
    }
    return 0;
}

static void set_index(int *index, int32_t val1, int32_t val2)
{
    *index = (val1 + val2) % IDX_MOD;
    *index = (*index < 0) ? (*index + MEM_SIZE) % MEM_SIZE : *index;
}

int my_sti(champ_proc_t *champ, vm_t *vm)
{
    int *params = get_param_type(vm->mem[PC_OFFSET(1)], true);
    uint8_t reg1 = vm->mem[PC_OFFSET(2)];
    int32_t val1 = 0;
    int32_t val2 = 0;
    int index = 0;
    int offset = 3;

    if (handle_error(params, reg1) == 1)
        return 1;
    val1 = read_from_type((int[2]){params[1], PC_OFFSET(3)},
        vm->mem, PC_OFFSET(3));
    offset += (params[1] == IND_KEY) ? 2 : 1;
    val2 = read_from_type((int[2]){params[2],
        PC_OFFSET(offset)}, vm->mem, PC_OFFSET(offset));
    if (load_val_if_reg(params, &val1, &val2, champ) == 1)
        return 1;
    set_index(&index, val1, val2);
    write_4_bytes(vm->mem, (PC + index) % MEM_SIZE, champ->reg[reg1 - 1]);
    my_free(params);
    return 0;
}
