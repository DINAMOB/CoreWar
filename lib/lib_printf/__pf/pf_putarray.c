/*
** EPITECH PROJECT, 2024
** MyLib
** File description:
** pf_putarray
*/

#include "my_printf.h"
#include "my.h"

int pf_putarray(char **arr)
{
    int i = 0;

    for (; arr[i] != NULL; i++) {
        pf_puts(arr[i]);
        if (arr[i + 1])
            pf_putchar('\n');
    }
    return i;
}

int pf_putarray_info(char **arr)
{
    int i = 0;

    my_printf("Array size : %d\n", my_arrlen(arr));
    for (; arr[i] != NULL; i++) {
        my_printf("Line size : %d {%s}\n", my_strlen(arr[i]), arr[i]);
    }
    return i;
}
