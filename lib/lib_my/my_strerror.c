/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** my_strerror
*/

#include "my.h"
#include <errno.h>

const str_error_t __str_errornum_tab[] = {
    {EACCES, "Permission denied"},
    {EPERM, "Operation not permitted"},
    {ENOENT, "No such file or directory"},
    {ESRCH, "No such process"},
    {EINTR, "Interrupted system call"},
    {EIO, "Input/output error"},
    {ENXIO, "No such device or address"},
    {E2BIG, "Argument list too long"},
    {ENOEXEC, "Exec format error"},
    {EBADF, "Bad file descriptor"},
    {ECHILD, "No child processes"},
    {ENOMEM, "Out of memory"},
    {EFAULT, "Bad address"},
    {EBUSY, "Device or resource busy"},
    {EEXIST, "File exists"},
    {ENODEV, "No such device"},
    {EINVAL, "Invalid argument"},
    {ENFILE, "File table overflow"},
    {EMFILE, "Too many open files"},
    {EPIPE, "Broken pipe"},
    {EAGAIN, "Resource temporarily unavailable"},
    {ENOTDIR, "Not a directory"},
    {EISDIR, "Is a directory"},
    {0, "Unknown error"}
};

const char *my_strerror(int errnum)
{
    for (int i = 0; __str_errornum_tab[i].error; i++) {
        if (errnum == __str_errornum_tab[i].error)
            return __str_errornum_tab[i].str;
    }
    return NULL;
}
