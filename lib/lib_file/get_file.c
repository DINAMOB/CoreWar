/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-42sh-antonie.morel
** File description:
** get_file
*/

#include "my_file.h"
#include <sys/stat.h>
#include "my_malloc.h"

char ***tab_add(size_t count, size_t *capacity, char ***arr)
{
    char ***new_array = NULL;
    size_t new_capacity = 0;

    if (count >= *capacity) {
        new_capacity = *capacity * 2;
        new_array = my_malloc(sizeof(char **) * new_capacity);
        if (!new_array)
            return NULL;
        for (size_t i = 0; i < count; i++)
            new_array[i] = arr[i];
        my_free(arr);
        *capacity = new_capacity;
        return new_array;
    }
    return arr;
}

char **arr_add(size_t count, size_t *capacity, char **arr)
{
    char **new_array = NULL;
    size_t new_capacity = 0;

    if (count >= *capacity) {
        new_capacity = *capacity * 2;
        new_array = my_malloc(sizeof(char *) * new_capacity);
        if (!new_array)
            return NULL;
        for (size_t i = 0; i < count; i++)
            new_array[i] = arr[i];
        my_free(arr);
        *capacity = new_capacity;
        return new_array;
    }
    return arr;
}

char **get_file(size_t *count, char *path)
{
    size_t capacity = 5;
    FILE *fd = fopen(path, "r");
    char **arr = (fd) ? my_malloc(sizeof(char *) * capacity) : NULL;
    char *line = NULL;
    struct stat st = {0};

    if (!arr || stat(path, &st) < 0 || st.st_size <= 0 || S_ISDIR(st.st_mode))
        return NULL;
    line = my_getline(fd);
    while (line) {
        arr = arr_add(*count, &capacity, arr);
        arr[*count] = my_strdup(line);
        free(line);
        if (!arr[*count])
            break;
        (*count)++;
        line = my_getline(fd);
    }
    return fclose(fd), arr;
}
