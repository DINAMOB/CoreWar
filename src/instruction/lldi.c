/*
** EPITECH PROJECT, 2025
** lldi
** File description:
** lldi
*/

#include "corewar.h"

static int handle_error(int *params)
{
    if (params[2] != REG_KEY) {
        my_dprintf(2, "lldi: third parameters should be a register.\n");
        return 1;
    }
    if (params[0] == NO_PARAM || params[1] == NO_PARAM ||
        params[0] == DIR_KEY || params[1] == DIR_KEY) {
        my_dprintf(2, "lldi: first and second parameters should"
            " be either a register or an indirect.\n");
        return 1;
    }
    return 0;
}

int read_two_params_and_set_offset(int *params, champ_proc_t *champ, vm_t *vm,
    int16_t **val)
{
    int offset = 2;

    *val[0] = read_from_type((int[2]){params[0], PC_OFFSET(2)}, vm->mem,
        PC_OFFSET(2));
    offset = new_offset(params[0], offset);
    *val[1] = read_from_type((int[2]){params[0], PC_OFFSET(offset)}, vm->mem,
        PC_OFFSET(offset));
    offset = new_offset(params[1], offset);
    return offset;
}

static void load_val_and_set_carry(uint8_t reg1, int32_t res,
    vm_t *vm, champ_proc_t *champ)
{
    champ->reg[reg1 - 1] = read_4_bytes(vm->mem,
        (PC + res) % MEM_SIZE);
    champ->carry = (champ->reg[reg1 - 1] == 0) ? 1 : 0;
}

int my_lldi(champ_proc_t *champ, vm_t *vm)
{
    int *params = get_param_type(vm->mem[PC_OFFSET(1)], false);
    uint8_t reg1 = 0;
    int16_t val1 = 0;
    int16_t val2 = 0;
    int32_t res = 0;
    int offset = 0;

    if (handle_error(params) == 1)
        return 1;
    offset = read_two_params_and_set_offset(params, champ, vm,
        (int16_t *[2]){&val1, &val2});
    reg1 = vm->mem[PC_OFFSET(offset)];
    if (reg1 < 1 || reg1 > 16)
        return 1;
    val1 = (val1 < 0) ? val1 + MEM_SIZE : val1;
    res = read_2_bytes(vm->mem, (PC + val1) % MEM_SIZE) + val2;
    load_val_and_set_carry(reg1, res, vm, champ);
    my_free(params);
    return 0;
}
