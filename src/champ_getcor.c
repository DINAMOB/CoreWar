/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** get_champcor
*/

#include "corewar.h"

int champ_getcor(champ_t *champ)
{
    FILE *fd = (champ) ? fopen(champ->path_champ, "r") : NULL;
    size_t size = 0;
    size_t prog_size = 0;

    if (!fd)
        return 0;
    size = fread(&champ->header, sizeof(header_t), 1, fd);
    if (errno || COREWAR_EXEC_MAGIC != my_revbyte32(champ->header.magic))
        return my_fclose(fd), 1;
    prog_size = my_revbyte32(champ->header.prog_size);
    if (prog_size >= MAX_PROG_SIZE)
        return my_fclose(fd), 1;
    champ->header.prog_size = prog_size;
    champ->body = my_malloc(sizeof(unsigned char) * prog_size);
    if (champ->body)
        size = fread(champ->body, sizeof(unsigned char), prog_size, fd);
    my_fclose(fd);
    return (errno || size != prog_size) ? 1 : champ_getcor(champ->next);
}
