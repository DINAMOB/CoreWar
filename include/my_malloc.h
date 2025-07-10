/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** my_malloc
*/

#ifndef MY_MALLOC_H_
    #define MY_MALLOC_H_
    #include <stdlib.h>
    #include "macro.h"

typedef struct mem_alloc_s {
    void *ptr;
    size_t size;
    struct mem_alloc_s *next;
} mem_alloc_t;

typedef struct db_mem_s {
    void *data;
} db_mem_t;

void **db_mem(void);

void check_leaks(void);
void *my_malloc(size_t size);
void *my_realloc(void *ptr, size_t new_size);
void *allocdim(int dim, size_t *size, size_t block);

size_t my_free(void *ptr);
void clear_mem(void);
void the_free(void *ptr, int size);
void freedim(void *tof, int depth, size_t *sizes);
void free_sc(void *ptr);
void free_arr(char **arr);

void *my_memmove(void *RSTCT dest, const void *RSTCT src, size_t n);
void *my_memcpy(void *RSTCT destptr, const void *RSTCT srcptr, size_t n);
void *my_memset(void *RSTCT ptr, int value, size_t nbytes);

char *my_strdup(char const *str);
char *my_strndup(char const *str, int n);
char **my_arrdup(char **arr);

size_t my_ptrsize(void *ptr);
char **word_array(char *str, char *limit);
#endif
