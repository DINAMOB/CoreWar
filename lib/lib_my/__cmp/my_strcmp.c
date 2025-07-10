/*
** EPITECH PROJECT, 2024
** Dinamob Lib_c
** File description:
** my_strcmp jan 30
*/

/**
 * @brief Compares two strings lexicographically.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return An integer indicating the lexicographical order of `s1` and `s2`.
 */
int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (!s1 && !s2)
        return 0;
    if (!s1)
        return -1;
    if (!s2)
        return 1;
    for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
        if (s1[i] - s2[i] != 0)
            return s1[i] - s2[i];
    return s1[i] - s2[i];
}
