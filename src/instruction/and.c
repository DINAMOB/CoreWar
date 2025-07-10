/*
** EPITECH PROJECT, 2025
** and
** File description:
** and command
*/
#include "corewar.h"

/**
 * @brief read_from_type read value on 2 or 4 bytes or get the id of a
 * register get a type and the PC placement to the params to read
 * can be called like this:
 *
 * example: read_from_type((int [2]{params_type[0], PC + 2}, mem, reg, champ))
 *
 * PC + 2 represent the position of the first parameters in the memory for
 * example.
 *
 * if params_type is a REG_KEY then get get the id of the register
 * @param type_and_offset in [0] the type of the params
 * and in [2] the position of the params in mem
 * @param mem the memory of the vm
 * @param index the index of a register in the mem
 * @param champ a champion
 * @return int32_t return the read value
 */
int32_t read_from_type(int type_and_offset[2], unsigned char *mem,
    int index)
{
    switch (type_and_offset[0]) {
        case DIR_KEY:
            return read_4_bytes(mem, type_and_offset[1]);
        case IND_KEY:
            return (int32_t)read_2_bytes(mem, type_and_offset[1]);
        case REG_KEY:
            return (int32_t)mem[index];
        default:
            return 0;
    }
    return 0;
}

static int and_error_handling(int *params_type)
{
    if (!params_type)
        return 1;
    for (int i = 0; i < 3; i++) {
        if (params_type[i] == NO_PARAM) {
            my_dprintf(2, "and: error invalid numbers of parameters.\n");
            return 1;
        }
    }
    if (params_type[2] != REG_KEY) {
        my_dprintf(2, "and: the third parameter must be a register.\n");
        return 1;
    }
    return 0;
}

int new_offset(int params, int current_offset)
{
    int new_offset = current_offset;

    switch (params) {
    case DIR_KEY:
        return new_offset + 4;
    case IND_KEY:
        return new_offset + 2;
    case REG_KEY:
        return new_offset + 1;
    default:
        return 0;
    }
    return 0;
}

static int chech_reg(int32_t reg)
{
    if (reg < 1 || reg > 16)
        return 1;
    return 0;
}

static int check_val_err(int32_t *value1, int32_t *value2,
    int *params, champ_proc_t *champ)
{
    if (params[0] == REG_KEY) {
        if (chech_reg(*value1) == 1)
            return 1;
        *value1 = champ->reg[*value1 - 1];
    }
    if (params[1] == REG_KEY) {
        if (chech_reg(*value2) == 1)
            return 1;
        *value2 = champ->reg[*value2 - 1];
    }
    return 0;
}

int32_t *get_val_and_set_offset(int *params, champ_proc_t *champ,
    vm_t *vm, int *offset)
{
    int32_t value1 = read_from_type((int[2]){params[0], PC_OFFSET(*offset)},
        vm->mem, PC_OFFSET(*offset));
    int32_t value2 = 0;
    int32_t value3 = 0;

    *offset = new_offset(params[0], *offset);
    value2 = read_from_type((int[2]){params[1], PC_OFFSET(*offset)}, vm->mem,
        PC_OFFSET(*offset));
    *offset = new_offset(params[1], *offset);
    value3 = read_from_type((int[2]){params[2], PC_OFFSET(*offset)}, vm->mem,
        PC_OFFSET(*offset));
    if (check_val_err(&value1, &value2, params, champ) == 1)
        return NULL;
    return (int32_t[3]){value1, value2, value3};
}

static int load_val(int32_t val1, int32_t val2,
    champ_proc_t *champ, int32_t reg3)
{
    champ->reg[reg3 - 1] = val1 & val2;
    champ->carry = (champ->reg[reg3 - 1] == 0) ? 1 : 0;
    return 0;
}

int my_and(champ_proc_t *champ, vm_t *vm)
{
    int *params_type = get_param_type(vm->mem[PC_OFFSET(1)], true);
    int32_t *all_val = NULL;
    int err = and_error_handling(params_type);
    int offset = 2;

    if (err == 1)
        return 1;
    all_val = get_val_and_set_offset(params_type, champ, vm, &offset);
    if (all_val == NULL)
        return 1;
    if (all_val[2] < 1 || all_val[2] > 16)
        return 1;
    my_free(params_type);
    return load_val(all_val[0], all_val[1], champ, all_val[2]);
}
