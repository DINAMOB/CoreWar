/*
** EPITECH PROJECT, 2025
** B-MUL-100-RUN-1-1-myradar-antonie.morel
** File description:
** my_isalpha
*/

#include "my.h"

/**
 * @brief Checks if a character is an alphabetic letter.
 *
 * This function verifies whether the given character is an uppercase
 * ('A'–'Z') or lowercase ('a'–'z') letter.
 *
 * @param c The character to check.
 * @return `true` if the character is alphabetic, `false` otherwise.
 */
bool my_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z')
    || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}
