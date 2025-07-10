/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** get_params_type
*/

#include "corewar.h"

int *get_param_type(uint8_t cb, bool is_index)
{
    int *params = my_malloc(sizeof(int) * 3);
    int mask = 0b00000011;

    if (!params)
        return NULL;
    params[0] = cb >> 6 & mask;
    params[1] = cb >> 4 & mask;
    params[2] = cb >> 2 & mask;
    if (is_index == false)
        return params;
    for (int i = 0; i < 3; i++) {
        if (params[i] == DIR_KEY)
            params[i] = DIR2_KEY;
    }
    return params;
}
