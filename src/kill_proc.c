/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** kill_proc
*/

#include "corewar.h"

void kill_proc(champ_proc_t **proc)
{
    champ_proc_t **curr = proc;
    champ_proc_t *to_free = NULL;
    char cmd[300] = {0};

    for (; *curr;) {
        if ((*curr)->alive == 1) {
            curr = &(*curr)->next;
            continue;
        }
        to_free = *curr;
        *curr = to_free->next;
        my_snprintf(cmd, 300, "The player %d (%s) has been slayed!\n",
            to_free->id, to_free->name);
        afficher_et_lire_phrase(cmd);
        my_free(to_free->name);
        my_free(to_free);
    }
}
