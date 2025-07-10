/*
** EPITECH PROJECT, 2025
** add
** File description:
** add.c
*/

#include "corewar.h"

static int modify_pc_on_error(int *params_type)
{
    for (int i = 0; i < 3; i++) {
        if (params_type[i] != REG_KEY)
            return 1;
    }
    return 0;
}

static int check_error_reg(uint8_t reg1, uint8_t reg2, uint8_t reg3)
{
    if (reg1 < 1 || reg1 > 16)
        return 1;
    if (reg2 < 1 || reg2 > 16)
        return 1;
    if (reg3 < 1 || reg3 > 16)
        return 1;
    return 0;
}

int my_add(champ_proc_t *champ, vm_t *vm)
{
    int *params_type = get_param_type(vm->mem[PC_OFFSET(1)], true);
    uint8_t reg1 = 0;
    uint8_t reg2 = 0;
    uint8_t reg3 = 0;

    if (!params_type || modify_pc_on_error(params_type) == 1)
        return 1;
    reg1 = vm->mem[PC_OFFSET(2)];
    reg2 = vm->mem[PC_OFFSET(3)];
    reg3 = vm->mem[PC_OFFSET(4)];
    if (check_error_reg(reg1, reg2, reg3) == 1)
        return 1;
    champ->reg[reg3 - 1] = champ->reg[reg1 - 1] + champ->reg[reg2 - 1];
    champ->carry = (champ->reg[reg3 - 1] == 0) ? 1 : 0;
    my_free(params_type);
    return 0;
}
