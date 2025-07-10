/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** print_champ
*/


#include "corewar.h"

void print_champ(champ_t *champ)
{
    if (!champ)
        return;
    my_printf("champ path: %s\n", champ->path_champ);
    my_printf("champ prog_number: %d\n", champ->prog_number);
    my_printf("champ adress: %d\n", champ->load_address);
    my_printf("champ header:\n\tname='%s'\n\tcomment='%s'\n\tprog_size=%d\n",
    champ->header.prog_name, champ->header.comment, champ->header.prog_size);
    my_printf("body:\n");
    print_memory(champ->body, champ->header.prog_size, 16);
    print_champ(champ->next);
}
