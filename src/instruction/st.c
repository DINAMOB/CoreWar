/*
** EPITECH PROJECT, 2025
** st
** File description:
** instruction st
*/

#include "corewar.h"

static int check_error_second_param(int *params_type, int16_t val)
{
    if (params_type[1] == 1) {
        if (val < 1 || val > 16) {
            my_dprintf(2, "st: error incorrect register index.\n");
            return 1;
        }
    }
    return 0;
}

static int st_handle_error(int *params_type, uint8_t reg_id, int16_t val)
{
    if (reg_id < 1 || reg_id > 16) {
        my_dprintf(2, "st: error incorrect register index.\n");
        return 1;
    }
    if (params_type == NULL || params_type[2] != NO_PARAM) {
        my_dprintf(2, "st: too many arguments.\n");
        return 1;
    }
    if (params_type[0] != REG_KEY) {
        my_dprintf(2, "st: don't get a register in first parameter\n");
        return 1;
    }
    if (params_type[1] != REG_KEY && params_type[1] != IND_KEY) {
        my_dprintf(2, "st: don't get a register"
            " or a number in second parameter\n");
        return 1;
    }
    if (check_error_second_param(params_type, val) == 1)
        return 1;
    return 0;
}

static void write_or_load_val(champ_proc_t *champ, vm_t *vm,
    int *params_type, uint8_t reg_id)
{
    int index = 0;
    int16_t val = vm->mem[PC_OFFSET(3)];

    if (params_type[1] == IND_KEY) {
        val = read_2_bytes(vm->mem, PC_OFFSET(3));
        index = (PC + val % IDX_MOD) % MEM_SIZE;
        index += (index < 0) ? MEM_SIZE : 0;
        write_4_bytes(vm->mem, PC_OFFSET(index), champ->reg[reg_id - 1]);
    } else
        champ->reg[val - 1] = champ->reg[reg_id - 1];
    my_free(params_type);
}

int my_st(champ_proc_t *champ, vm_t *vm)
{
    int *params_type = get_param_type(vm->mem[PC_OFFSET(1)], true);
    uint8_t reg_id = 0;
    int16_t val = 0;

    reg_id = vm->mem[PC_OFFSET(2)];
    val = vm->mem[PC_OFFSET(3)];
    if (st_handle_error(params_type, reg_id, val) == 1)
        return 1;
    write_or_load_val(champ, vm, params_type, reg_id);
    return 0;
}
