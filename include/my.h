/*
** EPITECH PROJECT, 2025
** Lib_c_skills_Mastery
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include "my_printf.h"
    #include <stdbool.h>
    #include <stddef.h>

typedef struct str_error_s {
    int error;
    char *str;
} str_error_t;

const char *my_strerror(int errnum);

bool my_isnum(char c);
char *my_strcat(char *dest, char const *src);
bool my_str_isnum(char *str);
bool my_str_isalnum(char *str);
bool isalpha_num(char c);
bool my_isalpha(char c);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);

int my_varlen(int nb, ...);
int my_arrlen(char **arr);
int my_strlen(char const *str);
int my_ulonglen(size_t nb);
int my_baselen(int nb, int base);
int my_baselen_st(size_t nb, int base);
int my_intlen(int nb);

int my_atoi(char const *str);

char *replacedata(char *old, char *new);
char *replacestr(char *str, char *trgt, char *rpl);
int replacechr(char *str, char trgt, char rpl);

char *my_jumpspace(char *str);
bool if_same(char c, char *str);
char *my_strspace(char *str);
char *my_strclean(char *str, char *trgt);
char *my_strstr(char *haystack, const char *needle);
char *my_strrchr(char *str, char c);
int my_strfind(const char *str, const char *to_search);
char *my_strchr(char *str, char c);

uint32_t my_revbyte32s(uint32_t nb, int sel);
uint32_t my_revbyte32(uint32_t nb);

#endif
