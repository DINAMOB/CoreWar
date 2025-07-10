/*
** EPITECH PROJECT, 2025
** ld
** File description:
** load value
*/

#include "corewar.h"

static int handle_error(int *params_type)
{
    if (!params_type)
        return 1;
    if (params_type[0] == REG_KEY) {
        my_dprintf(2, "ld: the first parameters cannot be a register.\n");
        return 1;
    }
    if (params_type[0] == NO_PARAM || params_type[1] != REG_KEY ||
        params_type[2] != NO_PARAM) {
        my_dprintf(2, "ld: invalid parameters.\n");
        return 1;
    }
    return 0;
}

static void set_carr(champ_proc_t *champ, uint8_t reg1, int *params_type)
{
    champ->carry = (champ->reg[reg1 - 1] == 0) ? 1 : 0;
    my_free(params_type);
}

int my_ld(champ_proc_t *champ, vm_t *vm)
{
    int *params_type = get_param_type(vm->mem[PC_OFFSET(1)], false);
    uint8_t reg1 = 0;
    int32_t val1 = 0;

    if (handle_error(params_type) == 1)
        return 1;
    reg1 = (params_type[0] == IND_KEY) ? vm->mem[PC_OFFSET(4)] :
        vm->mem[PC_OFFSET(6)];
    if (reg1 < 1 || reg1 > 16)
        return 1;
    val1 = read_from_type((int[2]){params_type[0], PC_OFFSET(2)},
        vm->mem, PC_OFFSET(2));
    val1 = (val1 < 0) ? val1 + MEM_SIZE : val1;
    if (params_type[0] == IND_KEY)
        champ->reg[reg1 - 1] = read_4_bytes(vm->mem,
            (PC + (val1 % IDX_MOD)) % MEM_SIZE);
    else
        champ->reg[reg1 - 1] = val1;
    set_carr(champ, reg1, params_type);
    return 0;
}
