##
## EPITECH PROJECT, 2025
## B-MUL-100-RUN-1-1-myradar-antonie.morel
## File description:
## config
##

#Executable name def
EXEC = corewar
LIB = libperso.a
UNIT_TESTS = unit_tests

#Compiler
CC = gcc

EXT = .c

#Header def
HEADER_DIR = include

CFLAGS = -Wall -Werror -Wextra
CSFLM = -lcsfml-graphics -lcsfml-window -lcsfml-system
LDFLAGS = -L lib -lperso -lm

EXCLUDE = --exclude=lib/lib_file \
	--exclude=lib/lib_malloc \
	--exclude=lib/lib_my \
	--exclude=lib/lib_printf
