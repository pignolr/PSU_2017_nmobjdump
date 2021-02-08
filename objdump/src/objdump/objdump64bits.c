/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** objdump64bits.c
*/

#include "proto.h"

int	do_objdump64(const elf64_data_t *data, const char *file)
{
	print_file_hdr64(data, file);
	print_source64(data);
	return (0);
}
