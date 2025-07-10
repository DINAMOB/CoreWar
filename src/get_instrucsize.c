/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** get_instrucsize
*/

#include "corewar.h"

int no_cb_op(int instruction)
{
    if (instruction == 1)
        return 4;
    if (instruction == 12 || instruction == 9 || instruction == 15)
        return 2;
    return 0;
}

int count_byte(uint8_t cb, op_t op)
{
    int mask = 0b00000011;
    int size = 0;

    if (!op.coding_byte)
        return no_cb_op(op.code) + 1;
    for (int i = 0; i < 8; i += 2) {
        if (((cb >> i) & mask) == 0b00000001)
            size += 1;
        if (((cb >> i) & mask) == 0b00000010)
            size += (op.is_index) ? 4 : 2;
        if (((cb >> i) & mask) == 0b00000011)
            size += 2;
    }
    return size + 2;
}

int get_instrucsize(size_t pc, unsigned char *mem)
{
    if (!mem || (mem[pc] <= 0 && mem[pc] > 16))
        return -1;
    return count_byte(mem[pc + 1], op_tab[mem[pc] - 1]);
}
