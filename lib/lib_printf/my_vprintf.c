/*
** EPITECH PROJECT, 2024
** MyLib
** File description:
** my_printf
*/

#include "my_printf.h"
#include "my.h"

static const tab_fonction_pointer_t tab[] = {
    {"Error", &if_noflags},
    {"bit8", &if_bit8},
    {"bit16", &if_bit16},
    {"bit32", &if_bit32},
    {"arr", &if_array},
    {"ul", &if_ulong},
    {"c", &if_character},
    {"s", &if_strings},
    {"d/i", &if_integer},
    {"f/F", &if_float},
    {"p", &if_pointer},
    {"x", &if_hexadecimal},
    {"X", &if_majhexadecimal},
    {"b", &if_binaire},
    {"o", &if_octal},
    {"u", &if_uninteger},
    {"n", &if_lencount},
    {"%", &if_percent},
    {NULL, NULL}
};

int multi_flags_selector(char const *flags, char const *str)
{
    int i_in = 0;

    for (i_in = 0; flags[i_in] != '\0' && flags[i_in] != '/'; i_in++);
    if (my_strncmp(flags, str, i_in) == 0) {
        return i_in;
    }
    if (flags[i_in] == '/')
        return multi_flags_selector(flags +(i_in + 1), str);
    return 0;
}

int find_flags(char const *str, int *index)
{
    int tab_i = 0;
    int i_in = 0;

    for (tab_i = 0; tab[tab_i].str != NULL; tab_i++) {
        i_in = multi_flags_selector(tab[tab_i].str, str);
        if (i_in > 0) {
            *index += i_in;
            return tab_i;
        }
    }
    return 0;
}

int op_size(char const *str, char c, int *index)
{
    int i = 0;

    if (c == '0' || c == '.' || c == '-') {
        i = my_atoi(str);
        *index += my_intlen(i);
        return i;
    }
    return 1;
}

void format_op(char const *str, int *index)
{
    int l = 0;
    data_option_t *tab_op = data_op();

    for (; str[*index] != '\0' && tab_op[l].c != 0; *index += 1) {
        if (my_atoi(str + *index) != 0 && str[*index] != '0' &&
        str[*index] != '-' && str[*index] != '+') {
            NONE = my_atoi(str + *index);
            *index += my_intlen(NONE);
        }
        for (l = 0; tab_op[l].c != 0 && tab_op[l].c != str[*index]; l++);
        if (tab_op[l].c != 0)
            tab_op[l].modify = op_size(str +(*index + 1), tab_op[l].c, index);
    }
    if (POINT > 0 || MOINS > 0) {
        NONE = ZERO;
        ZERO = 0;
    }
    *index -= 1;
}

int my_vprintf(char const *format, va_list list)
{
    int size = 0;
    int limit = buffering()->size;

    for (int index = 0; format[index]; index++) {
        if (limit != 0 && size >= limit - 1)
            break;
        if (format[index] == '%') {
            format_op(format +1, &index);
            tab[find_flags(format +(index + 1), &index)].fonction(list);
            reset_op();
        } else
            pf_putchar(format[index]);
        size = *pf_putchar(0);
    }
    size = *pf_putchar(0);
    *pf_putchar(0) = 0;
    return size;
}
