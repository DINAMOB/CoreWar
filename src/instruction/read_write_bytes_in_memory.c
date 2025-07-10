/*
** EPITECH PROJECT, 2025
** read write in memory
** File description:
** read write in memory
*/
#include "corewar.h"

int16_t read_2_bytes(unsigned char *mem, int index)
{
    int16_t value = 0;
    int high = mem[index % MEM_SIZE];
    int low = mem[(index + 1) % MEM_SIZE];

    value = (high << 8) | low;
    return (int16_t)value;
}

int32_t read_4_bytes(unsigned char *mem, int index)
{
    int32_t result = 0;

    result |= (int32_t)mem[index % MEM_SIZE] << 24;
    result |= (int32_t)mem[(index + 1) % MEM_SIZE] << 16;
    result |= (int32_t)mem[(index + 2) % MEM_SIZE] << 8;
    result |= (int32_t)mem[(index + 3) % MEM_SIZE];
    return result;
}

void write_4_bytes(unsigned char *mem, int index, int32_t value)
{
    mem[index % MEM_SIZE] = (value >> 24) & 0xFF;
    mem[(index + 1) % MEM_SIZE] = (value >> 16) & 0xFF;
    mem[(index + 2) % MEM_SIZE] = (value >> 8) & 0xFF;
    mem[(index + 3) % MEM_SIZE] = value & 0xFF;
}

void write_2_bytes(unsigned char *mem, int index, int16_t value)
{
    mem[index % MEM_SIZE] = (value >> 8) & 0xFF;
    mem[(index + 1) % MEM_SIZE] = value & 0xFF;
}
