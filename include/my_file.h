/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** my_file
*/

#ifndef MY_FILE_H_
    #define MY_FILE_H_
    #include <stdio.h>
    #include "macro.h"
    #include "my_printf.h"
    #include <fcntl.h>

char **get_file(size_t *count, char *path);
char *my_getline(FILE *fd);
int my_open(char *path, int oflags);
char *my_read(int fd, size_t size);

#endif
