/*
** EPITECH PROJECT, 2025
** live
** File description:
** live
*/
#include "corewar.h"

int my_live(champ_proc_t *champ, vm_t *vm)
{
    int32_t val = read_4_bytes(vm->mem, PC_OFFSET(1));
    champ_proc_t *proc = champ;

    if (vm->live.nbr_live <= 0) {
        vm->live.cycle_to_die -= CYCLE_DELTA;
        vm->live.nbr_live = NBR_LIVE;
    }
    vm->live.nbr_live -= 1;
    for (; proc; proc = proc->next) {
        if (proc->id == val) {
            my_free(vm->name);
            vm->name = my_strdup(champ->name);
            vm->id = champ->id;
            proc->alive = true;
        }
    }
    return 0;
}
