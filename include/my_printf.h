/*
** EPITECH PROJECT, 2024
** MyLib
** File description:
** printf
*/

#ifndef PRINTF_H_
    #define PRINTF_H_
    #include <stdarg.h>
    #include <stddef.h>
    #include <stdbool.h>
    #include <stdint.h>
    #include "macro.h"

    #define SHARP tab_op[0].modify
    #define SPACE tab_op[1].modify
    #define MOINS tab_op[2].modify
    #define PLUS tab_op[3].modify
    #define ZERO tab_op[4].modify
    #define POINT tab_op[5].modify
    #define NONE tab_op[6].modify
    #define POINT_COND(n) (n == -1) ? n : n

typedef struct buffer_data_s {
    int size;
    char *RSTCT str;
} buffer_data_t;

typedef struct tab_fonction_pointer_s {
    char *str;
    int (*fonction)(va_list list);
} tab_fonction_pointer_t;

typedef struct data_option_s {
    char c;
    int modify;
} data_option_t;

int *pf_output(void);
buffer_data_t *buffering(void);

int my_printf(char const *format, ...);
int my_vprintf(char const *format, va_list list);
int my_dprintf(int output, char const *format, ...);
int my_snprintf(char *RSTCT str, size_t len, char const *format, ...);

void modifier(data_option_t *tab_op, int nb, int base);
void modifier_for_size_t(data_option_t *tab_op, size_t nb, int base);
void modifier_for_float(data_option_t *tab_op, double nb, int base);

data_option_t *data_op(void);
void reset_op(void);

#ifndef INCLUDE_PRINTF_PF_H_
    #define INCLUDE_PRINTF_PF_H_
int *pf_putchar(char c);
int pf_putulong(size_t nb);
int pf_put(char c, int precision);
int pf_puts(char const *str);
int pf_puts_prec(char const *str, int precision);
int pf_putarray(char **arr);
int pf_putarray_info(char **arr);
void pf_putfloat(float num, int precision);
void pf_putnbr(int n);
int pf_putun_base(unsigned int nb, char const *base);
int pf_putlong_base(long nb, char const *base);
void pf_putbit_u8(uint8_t nb);
void pf_putbit_u32(uint32_t nb);
void pf_putbit_u16(uint16_t nb);
#endif

#ifndef INCLUDE_PRINTF_IF_H_
    #define INCLUDE_PRINTF_IF_H_
    #include <stdarg.h>
int if_noflags(va_list list);
int if_bit8(va_list list);
int if_bit16(va_list list);
int if_bit32(va_list list);
int if_array(va_list list);
int if_character(va_list list);
int if_strings(va_list list);
int if_integer(va_list list);
int if_ulong(va_list list);
int if_float(va_list list);
int if_pointer(va_list list);
int if_hexadecimal(va_list list);
int if_majhexadecimal(va_list list);
int if_binaire(va_list list);
int if_octal(va_list list);
int if_uninteger(va_list list);
int if_lencount(va_list list);
int if_percent(va_list list);
#endif

#endif
