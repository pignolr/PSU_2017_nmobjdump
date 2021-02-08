/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** objdump32bits.c
*/

#include <stdio.h>
#include <string.h>
#include "proto.h"

int	do_objdump32(const elf32_data_t *data, const char *file)
{
	print_file_hdr32(data, file);
	print_source32(data);
	return (0);
}
