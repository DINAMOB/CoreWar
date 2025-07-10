/*
** EPITECH PROJECT, 2025
** fork
** File description:
** fork
*/

#include "corewar.h"

int my_fork(champ_proc_t *champ, vm_t *vm)
{
    int16_t val1 = read_2_bytes(vm->mem, PC_OFFSET(1));
    int new_proc_pc = 0;

    val1 = (val1 < 0) ? val1 + MEM_SIZE : val1;
    new_proc_pc = (PC + (val1 % IDX_MOD)) % MEM_SIZE;
    return add_proc(&champ, champ, new_proc_pc);
}
