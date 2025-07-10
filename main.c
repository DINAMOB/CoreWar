/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** main
*/

#include "corewar.h"

void afficher_et_lire_phrase(char *phrases)
{
    my_printf("%s\n", phrases);
    char commande[512];
    my_snprintf(commande, sizeof(commande),
        "espeak -v en-us+m3 -s 120 -p 10 -a 200 \"%s\"", phrases);
    system(commande);
}

void check_alive(champ_proc_t *proc)
{
    if (!proc)
        return;
    if (proc->alive == 1) {
        my_printf("The player %d (%s)is alive.\n", proc->id, proc->name);
        proc->alive = 0;
    }
    return check_alive(proc->next);
}

int main(int ac, char **av)
{
    binaire_arg_t *arg = my_malloc(sizeof(binaire_arg_t));
    vm_t *vm = NULL;
    champ_proc_t *proc = NULL;
    int nb_champ = 0;
    int offset = 0;

    if (handle_eror(arg, ac, av))
        return 84;
    nb_champ = listchamplen(arg->champ_node);
    vm = (nb_champ > 1) ? init_vm() : NULL;
    offset = (!vm) ? 0 : MEM_SIZE / nb_champ;
    proc = (vm) ? load_champ(arg->champ_node, offset, vm->mem, 0) : NULL;
    if (core_loop(arg->dump_node, vm, proc))
        return clear_mem(), 84;
    clear_mem();
    return 0;
}
