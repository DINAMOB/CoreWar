/*
** EPITECH PROJECT, 2024
** Dinamob Lib_c
** File description:
** my_strcmp jan 30
*/

/**
 * @brief Compares two strings up to a given number of characters.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of characters to compare.
 * @return An integer indicating the lexicographical
 * order of `s1` and `s2` up to `n` characters.
 */
int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n <= 0)
        return 0;
    if (!s1 && !s2)
        return 0;
    if (!s1)
        return -1;
    if (!s2)
        return 1;
    for (i = 0; (s1[i] != '\0' || s2[i] != '\0') && i < n - 1; i++)
        if (s1[i] - s2[i] != 0)
            return s1[i] - s2[i];
    return s1[i] - s2[i];
}
