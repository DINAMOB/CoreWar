/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** db_mem
*/

#include "my_malloc.h"

void **db_mem(void)
{
    static void *db = NULL;

    return &db;
}
