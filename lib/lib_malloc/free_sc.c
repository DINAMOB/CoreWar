/*
** EPITECH PROJECT, 2024
** B-CPE-100-RUN-1-1-cpoolday09-antonie.morel
** File description:
** free_sc
*/

#include "my_malloc.h"

void free_sc(void *ptr)
{
    if (ptr)
        free(ptr);
    ptr = NULL;
}
