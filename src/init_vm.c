/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** init_vm
*/

#include "corewar.h"

vm_t *init_vm(void)
{
    vm_t *vm = my_malloc(sizeof(vm_t));

    vm->name = NULL;
    vm->id = 0;
    vm->live.nbr_live = NBR_LIVE;
    vm->live.cycle_to_die = CYCLE_TO_DIE;
    vm->mem = my_malloc(sizeof(unsigned char) * MEM_SIZE);
    if (!vm->mem) {
        my_dprintf(2, "%sinit_vm: alloc vm failed.\n", ERROR);
    }
    return vm;
}
