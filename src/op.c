/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-robotfactory-antonie.morel
** File description:
** op
*/

#include "op.h"
#include "stddef.h"

const op_t op_tab[] = {
    {"live", 1, {T_DIR},
        1, 10, "alive",
        0, 1,
        &my_live},

    {"ld", 2, {T_DIR | T_IND, T_REG},
        2, 5, "load",
        1, 1,
        &my_ld},

    {"st", 2, {T_REG, T_IND | T_REG},
        3, 5, "store",
        1, 0,
        &my_st},

    {"add", 3, {T_REG, T_REG, T_REG},
        4, 10, "addition",
        1, 0,
        &my_add},

    {"sub", 3, {T_REG, T_REG, T_REG},
        5, 10, "soustraction",
        1, 0,
        &my_sub},

    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
        6, 6, "et (and  r1, r2, r3   r1&r2 -> r3",
        1, 0,
        &my_and},

    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
        7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3",
        1, 0,
        &my_or},

    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
        8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3",
        1, 0,
        &my_xor},

    {"zjmp", 1, {T_DIR},
        9, 20, "jump if zero",
        0, 0,
        &my_zjmp},

    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
        10, 25, "load index",
        1, 1,
        &my_ldi},

    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
        11, 25, "store index",
        1, 0,
        &my_sti},

    {"fork", 1, {T_DIR},
        12, 800, "fork",
        0, 0,
        &my_fork},

    {"lld", 2, {T_DIR | T_IND, T_REG},
        13, 10, "long load",
        1, 0,
        &my_lld},

    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
        14, 50, "long load index",
        1, 1,
        &my_lldi},

    {"lfork", 1, {T_DIR},
        15, 1000, "long fork",
        0, 1,
        &my_lfork},

    {"aff", 1, {T_REG},
        16, 2, "aff",
        1, 0,
        &my_aff},

    {0, 0, {0}, 0, 0, 0, 0, 0, NULL}
};
