/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** args_parser
*/

#include "corewar.h"

static int champ_params(int *val, int ac, char **av, int *counter)
{
    if (av[0] && (!my_strcmp(av[0], "-n") || !my_strcmp(av[0], "-a"))) {
        if (ac < 2 || !my_str_isnum(av[1]))
            return 1;
        if (av[0][1] == 'n')
            val[0] = my_atoi(av[1]);
        if (av[0][1] == 'a')
            val[1] = my_atoi(av[1]);
        *counter += 2;
        if (ac >= 3 && av[2][0] == '-')
            return champ_params(val, ac - 2, av + 2, counter);
    }
    return 0;
}

static int champ_detect(champ_t **champ, int ac, char **av)
{
    int val[2] = {0};
    int counter = 0;

    if (!av[0])
        return 0;
    if (champ_params(val, ac, av, &counter)) {
        my_dprintf(2, "%schamp_detect: Failed to get params\n", ERROR);
        return -1;
    }
    if (add_champ(champ, val, av[counter]))
        return -1;
    counter += 1;
    return counter;
}

static int dump_detect(dump_cycle_t **node, int ac, char **av)
{
    int tmp = 0;

    if (av[0] && !my_strcmp(av[0], "-dump")) {
        if (ac < 2) {
            my_dprintf(2, "%sdump_detect: too few argument.\n", ERROR);
            return -1;
        }
        tmp = my_atoi(av[1]);
        if (tmp <= 0) {
            my_dprintf(2, "%sdump_detect: negativ number.\n", ERROR);
            return -1;
        }
        return add_dump(node, tmp);
    }
    return 1;
}

int args_parser(binaire_arg_t *arg, int ac, char **av)
{
    int counter = 0;

    if (ac <= 0)
        return 0;
    counter = dump_detect(&arg->dump_node, ac, av);
    if (!counter)
        return args_parser(arg, ac - 2, av + 2);
    if (counter != -1){
        counter = champ_detect(&arg->champ_node, ac, av);
        if (counter > 0) {
            return args_parser(arg, ac - counter, av + counter);
        }
    }
    return 1;
}
