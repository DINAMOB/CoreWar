/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** core_loop
*/

#include "corewar.h"

int core_loop(dump_cycle_t *dump, vm_t *vm, champ_proc_t *proc)
{
    char cmd[300] = {0};

    if (!vm || !proc)
        return 1;
    for (int i = 0; listproclen(proc) >= 1
        && vm->live.cycle_to_die > 0; i++) {
        proc_cycle(vm, proc);
        if (i >= vm->live.cycle_to_die) {
            print_proclist(proc);
            kill_proc(&proc);
            check_alive(proc);
            i = 0;
        }
        dump_cycle(dump, vm->mem);
    }
    if (vm->name) {
        my_snprintf(cmd, 300, "The player %d(%s)has won !\n", vm->id, vm->name);
        afficher_et_lire_phrase(cmd);
    } else
        afficher_et_lire_phrase("No player win.\n");
    return 0;
}