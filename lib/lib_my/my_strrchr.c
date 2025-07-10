/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** strrchr
*/

char *my_strrchr(char *str, char c)
{
    int pos = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            pos = i;
    return str + pos;
}
