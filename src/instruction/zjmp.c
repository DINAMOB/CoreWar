/*
** EPITECH PROJECT, 2025
** zjmp
** File description:
** zjmp
*/
#include "corewar.h"

int16_t my_revbytei16(int16_t nb)
{
    int16_t binary = 0;

    for (int i = 0; i < 16; i += 8)
        binary |= (((nb >> i) & 255) << ((16 - 8) - i));
    return binary;
}

int32_t my_revbytei32(int32_t nb)
{
    int32_t binary = 0;

    for (int i = 0; i < 32; i += 8)
        binary |= (((nb >> i) & 255) << ((32 - 8) - i));
    return binary;
}

int my_zjmp(champ_proc_t *champ, vm_t *vm)
{
    int16_t val = read_2_bytes(vm->mem, PC_OFFSET(1));

    if (champ->carry == 0)
        return 1;
    PC = ((PC + 1 + (val % IDX_MOD)) - 4) % MEM_SIZE;
    return 0;
}
