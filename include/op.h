/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-robotfactory-antonie.morel
** File description:
** op
*/

#ifndef _OP_H_
    #define _OP_H_
    #include "stdbool.h"
    #include <unistd.h>

    #define IDX_MOD 512
    #define MAX_ARGS_NUMBER 4
    #define MAX_CHAMP 6
    #define MAX_PROG_SIZE 1024

    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"
    #define MEM_SIZE (6 * 1024)

    #define REG_NUMBER 16
    #define T_REG 1
    #define T_DIR 2
    #define T_IND 4
    #define T_LAB 8

    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE

    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3

    #define CYCLE_TO_DIE 1536
    #define NBR_LIVE 40
    #define CYCLE_DELTA 5

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct champ_proc_s {
    char *name;
    int id;
    int alive;
    size_t pc;
    int carry;
    int reg[REG_NUMBER];
    int wait_cycle;
    struct champ_proc_s *next;
} champ_proc_t;

typedef struct champ_s {
    int prog_number;
    size_t load_address;
    char *path_champ;
    header_t header;
    unsigned char *body;
    struct champ_s *next;
} champ_t;

typedef struct live_data_s {
    int cycle_to_die;
    int nbr_live;
    int live_tab_size;
    bool *live_tab;
} live_data_t;

typedef struct virtual_machine_s {
    live_data_t live;
    char *name;
    int id;
    unsigned char *mem;
} vm_t;

typedef char args_type_t;

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
    int coding_byte;
    int is_index;
    int (*instruction)(champ_proc_t *, vm_t *);
} op_t;

extern const op_t op_tab[];

int my_ld(champ_proc_t *champ, vm_t *vm);
int my_st(champ_proc_t *champ, vm_t *vm);
int my_and(champ_proc_t *champ, vm_t *vm);
int my_add(champ_proc_t *champ, vm_t *vm);
int my_or(champ_proc_t *champ, vm_t *vm);
int my_sub(champ_proc_t *champ, vm_t *vm);
int my_xor(champ_proc_t *champ, vm_t *vm);
int my_aff(champ_proc_t *champ, vm_t *vm);
int my_fork(champ_proc_t *champ, vm_t *vm);
int my_ldi(champ_proc_t *champ, vm_t *vm);
int my_lldi(champ_proc_t *champ, vm_t *vm);
int my_ld(champ_proc_t *champ, vm_t *vm);
int my_lld(champ_proc_t *champ, vm_t *vm);
int my_sti(champ_proc_t *champ, vm_t *vm);
int my_zjmp(champ_proc_t *champ, vm_t *vm);
int my_live(champ_proc_t *champ, vm_t *vm);
int my_lfork(champ_proc_t *champ, vm_t *vm);

#endif
