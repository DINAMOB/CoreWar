/*
** EPITECH PROJECT, 2025
** B-MUL-100-RUN-1-1-myradar-antonie.morel
** File description:
** my_open
*/

#include "my_file.h"

int my_open(char *path, int oflags)
{
    int fd = 0;

    if (!path) {
        my_dprintf(2, "[ERROR]my_open: %s doesn't exist.\n", path);
        return -1;
    }
    fd = open(path, oflags);
    if (fd == -1) {
        perror("open");
        return -1;
    }
    return fd;
}
