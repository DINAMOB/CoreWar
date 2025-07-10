/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** check_progs_size
*/

#include "corewar.h"

size_t check_progs_size(champ_t *champ)
{
    if (!champ)
        return 0;
    return check_progs_size(champ->next) + champ->header.prog_size;
}
