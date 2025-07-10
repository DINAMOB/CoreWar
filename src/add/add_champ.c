/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** add_champ
*/

#include "corewar.h"

int add_champ(champ_t **current, int val[2], char *path)
{
    struct stat st = {0};
    champ_t *node = NULL;

    if (stat(path, &st) < 0 || st.st_size <= 0 || S_ISDIR(st.st_mode)) {
        my_dprintf(2, "%sadd_champ: Failed to load '%s'.\n", ERROR, path);
        return 1;
    }
    node = my_malloc(sizeof(champ_t));
    if (!node)
        return 1;
    node->prog_number = val[0];
    node->load_address = val[1];
    node->path_champ = my_strdup(path);
    node->body = NULL;
    node->next = *current;
    *current = node;
    return 0;
}
