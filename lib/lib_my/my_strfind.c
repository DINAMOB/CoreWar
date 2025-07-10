/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** my_strsearch
*/

int my_strfind(const char *str, const char *to_search)
{
    int k = 0;

    if (!str || !to_search)
        return -1;
    for (int i = 0; str[i]; i++) {
        for (k = 0; to_search[k] && to_search[k] != str[i]; k++);
        if (!to_search[k])
            continue;
        return i;
    }
    return -1;
}
