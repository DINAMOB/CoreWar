/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** listproclen
*/

#include "corewar.h"

int listproclen(champ_proc_t *list)
{
    if (!list)
        return 0;
    return listproclen(list->next) + 1;
}
