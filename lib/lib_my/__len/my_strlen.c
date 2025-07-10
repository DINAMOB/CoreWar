/*
** EPITECH PROJECT, 2025
** Dinamob Lib_c
** File description:
** my_strlen jan 30
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return 0;
    for (; str[i] != '\0'; i++);
    return i;
}
