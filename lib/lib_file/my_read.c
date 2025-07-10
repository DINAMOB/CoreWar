/*
** EPITECH PROJECT, 2025
** B-MUL-100-RUN-1-1-myradar-antonie.morel
** File description:
** my_read
*/

#include "my_file.h"
#include "my_malloc.h"
#include <unistd.h>

char *my_read(int fd, size_t size)
{
    char *buffer = my_malloc(sizeof(char) * (size + 1));

    size = read(fd, buffer, size);
    if (size == (size_t)-1) {
        my_dprintf(2, "[ERROR]my_read: read failled.\n");
        return NULL;
    }
    buffer[size] = '\0';
    return buffer;
}
