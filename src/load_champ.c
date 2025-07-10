/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** load_champ
*/

#include "corewar.h"

champ_proc_t *load_champ(champ_t *champ, size_t offset, uint8_t *mem, int deep)
{
    champ_proc_t *proc = (champ) ? my_malloc(sizeof(champ_proc_t)) : NULL;
    size_t start = offset * deep;
    static int id = 1;

    if (!proc)
        return NULL;
    if (start >= MEM_SIZE)
        start = start - MEM_SIZE;
    my_memcpy(&mem[start], champ->body, champ->header.prog_size);
    proc->alive = 0;
    proc->name = my_strdup(champ->header.prog_name);
    proc->id = (champ->prog_number) ? champ->prog_number : id;
    if (!champ->prog_number)
        id += 1;
    proc->pc = start;
    proc->reg[0] = proc->id;
    proc->next = load_champ(champ->next, offset, mem, deep + 1);
    return proc;
}
