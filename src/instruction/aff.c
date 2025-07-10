/*
** EPITECH PROJECT, 2025
** aff
** File description:
** aff
*/
#include "corewar.h"

int my_aff(champ_proc_t *champ, vm_t *vm)
{
    int *params = get_param_type(PC_OFFSET(1), false);
    uint8_t reg = vm->mem[PC_OFFSET(2)];

    if (params[0] != REG_KEY)
        return 1;
    if (reg < 1 || reg > 16)
        return 1;
    my_printf("%c", champ->reg[reg - 1] % 256);
    my_free(params);
    return 0;
}
