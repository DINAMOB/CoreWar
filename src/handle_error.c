/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** handle_error
*/

#include "corewar.h"

int handle_eror(binaire_arg_t *arg, int ac, char **av)
{
    if (args_parser(arg, ac - 1, av + 1) ||
        champ_getcor(arg->champ_node) ||
        check_progs_size(arg->champ_node) >= MEM_SIZE ||
        listchamplen(arg->champ_node) >= 6)
        return clear_mem(), 1;
    return 0;
}
