/*
** EPITECH PROJECT, 2024
** Dinamob Lib_c
** File description:
** my_atoi jan 30
*/

int my_atoi(char const *str)
{
    int i = 0;
    int nb = 0;
    int moins = 0;

    if (!str)
        return 0;
    for (; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            moins += 1;
    for (int l = 0; str[i + l] >= '0' && str[i + l] <= '9'; l++)
        nb = (nb * 10) + (str[i + l] - 48);
    nb = (moins % 2 != 0) ? - nb : nb;
    return nb;
}
