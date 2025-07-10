/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-antonie.morel
** File description:
** word_array
*/

#include "my_malloc.h"
#include "my.h"
#include <stdbool.h>

static int count_word(int len, char *str)
{
    int count = 0;

    for (int i = 0; i < len; i++) {
        for (; str[i] == '\0' && i != len; i++);
        if (i >= len)
            return count;
        count += 1;
        for (; my_isalpha(str[i]) == 1; i++);
    }
    return count;
}

static void jump_guigui(char *str, int *i)
{
    if (str[*i] == '"') {
        *i += 1;
        for (*i = *i; str[*i] != '"'; *i += 1);
    }
}

bool if_same(char c, char *str)
{
    for (int i = 0; str[i]; i++)
        if (c == str[i])
            return true;
    return false;
}

static void replace(char *str, char *select, char repl)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        jump_guigui(str, &i);
        if (if_same(str[i], select))
            str[i] = repl;
    }
}

static char **set_arr(char *tmp, char *limt)
{
    char **arr = NULL;
    int len = my_strlen(tmp);
    int lenarr = 0;
    int i = 0;

    replace(tmp, limt, '\0');
    arr = my_malloc(sizeof(char *) * (count_word(len, tmp) + 1));
    for (i = 0; i < len; i++) {
        for (; tmp[i] == '\0' && i != len; i++);
        if (i >= len)
            break;
        arr[lenarr] = my_strdup(tmp +i);
        i += my_strlen(arr[lenarr]);
        lenarr += 1;
    }
    arr[lenarr] = NULL;
    my_free(tmp);
    return arr;
}

char **word_array(char *str, char *limit)
{
    char *tmp = NULL;

    if (!str || !limit)
        return NULL;
    tmp = my_strdup(str);
    return set_arr(tmp, limit);
}
