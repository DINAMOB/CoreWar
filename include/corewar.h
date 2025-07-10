/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_
    #include "my_malloc.h"
    #include "my_printf.h"
    #include "op.h"
    #include "my.h"
    #include <sys/stat.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <errno.h>
    #define NO_PARAM 0
    #define REG_KEY 1
    #define DIR_KEY 2
    #define DIR2_KEY 3
    #define IND_KEY 3
    #define PC champ->pc
    #define PC_OFFSET(X) ((PC + X) % MEM_SIZE)

typedef struct dump_cycle_s {
    int nb_cycle;
    int counter;
    struct dump_cycle_s *next;
} dump_cycle_t;

typedef struct binaire_arg_s {
    dump_cycle_t *dump_node;
    champ_t *champ_node;
} binaire_arg_t;

void afficher_et_lire_phrase(char *phrases);
int *get_param_type(uint8_t cb, bool is_index);
void my_fclose(FILE *fd);

int listchamplen(champ_t *champ);
int listproclen(champ_proc_t *list);

void print_proclist(champ_proc_t *proc);
void print_memory(unsigned char *mem, int size, int package);
void print_champ(champ_t *champ);
void print_dump_cycle(dump_cycle_t *node);

int add_champ(champ_t **current, int val[2], char *path);
int add_dump(dump_cycle_t **current, int nb);

vm_t *init_vm(void);
int *get_param_type(uint8_t cb, bool is_index);
int champ_getcor(champ_t *champ);
int args_parser(binaire_arg_t *arg, int ac, char **av);
champ_proc_t *load_champ(champ_t *champ, size_t offset,
    unsigned char *mem, int deep);


int16_t read_2_bytes(unsigned char *mem, int index);
int32_t read_4_bytes(unsigned char *mem, int index);
void write_4_bytes(unsigned char *mem, int index, int32_t value);
void write_2_bytes(unsigned char *mem, int index, int16_t value);
int32_t read_from_type(int type_and_offset[2], unsigned char *mem,
    int reg1);
int add_proc(champ_proc_t **current, champ_proc_t *proc, size_t pc);
int new_offset(int params, int current_offset);
int handle_eror(binaire_arg_t *arg, int ac, char **av);
size_t check_progs_size(champ_t *champ);
int core_loop(dump_cycle_t *dump, vm_t *vm, champ_proc_t *proc);
void kill_proc(champ_proc_t **proc);
int get_instrucsize(size_t pc, unsigned char *mem);
void proc_cycle(vm_t *vm, champ_proc_t *proc);
void dump_cycle(dump_cycle_t *dump, unsigned char *mem);

int32_t my_revbytei32(int32_t nb);
int16_t my_revbytei16(int16_t nb);
#endif
