/*
** EPITECH PROJECT, 2025
** B-PSU-100-RUN-1-1-mysudo-antonie.morel
** File description:
** my_getline
*/

#include "my_file.h"
#include <stdlib.h>

char *my_getline(FILE *fd)
{
    char *buffer = NULL;
    size_t len = 0;
    int read = 1;

    if (!fd) {
        my_dprintf(2, "%smy_getline: file directory doesn't exist", ERROR);
        return NULL;
    }
    read = getline(&buffer, &len, fd);
    if (read == -1) {
        free(buffer);
        return NULL;
    }
    buffer[read - 1] = (buffer[read - 1] == '\n') ? '\0' : buffer[read - 1];
    return buffer;
}
