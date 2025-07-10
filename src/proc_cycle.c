/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** proc_cycle
*/

#include "corewar.h"

void wait_update(vm_t *vm, champ_proc_t *proc)
{
    if (proc->wait_cycle == 0)
        proc->wait_cycle = op_tab[vm->mem[proc->pc] - 1].nbr_cycles;
    else
        proc->wait_cycle -= 1;
}

void proc_cycle(vm_t *vm, champ_proc_t *proc)
{
    int size = 0;

    if (!proc)
        return;
    size = get_instrucsize(proc->pc, vm->mem);
    if (size <= 0)
        return proc_cycle(vm, proc->next);
    wait_update(vm, proc);
    if (proc->wait_cycle == 0) {
        if (op_tab[vm->mem[proc->pc] - 1].instruction(proc, vm)) {
            return proc_cycle(vm, proc->next);
        }
        proc->pc += size;
    }
    proc_cycle(vm, proc->next);
}
