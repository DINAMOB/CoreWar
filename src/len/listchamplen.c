/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** listchamplen
*/

#include "corewar.h"

int listchamplen(champ_t *champ)
{
    if (!champ)
        return 0;
    return listchamplen(champ->next) + 1;
}
