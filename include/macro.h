/*
** EPITECH PROJECT, 2025
** Lib_c_skills_Mastery (Workspace)
** File description:
** macro
*/

#ifndef MACRO_H_
    #define MACRO_H_
    #define ABS(n) (n < 0) ? -n : n
    #define DEG_TO_RAD(X) (M_PI / 180) * X
    #define RAD_TO_DEG(X) (180 / M_PI) * X
    #define PI2 (2 * M_PI)
    #define MAX(a, b) a > b ? a : b
    #define MIN(a, b) a < b ? a : b
    #define UNUSE __attribute__((unused))
    #define MAX_INPUT 4096
    #define PATH_MAX 4096
    #define RSTCT restrict
    #define ERROR "\033[31;1m[ERROR]\033[0m"

typedef struct vector2i_s {
    int y;
    int x;
} vector2i_t;

typedef struct vector2f_s {
    float y;
    float x;
} vector2f_t;

typedef struct arrint_s {
    int **arr;
    int y;
    int x;
} arrint_t;

#endif
