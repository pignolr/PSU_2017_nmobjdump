/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** print_file_hdr64.c
*/

#include <stdio.h>
#include <string.h>
#include "proto.h"

void	print_format64(void)
{
	printf("file format elf64-x86-64\n");
}

void	print_start_address64(Elf64_Addr flags)
{
	printf("start address 0x%016lx\n", flags);
}

void	print_file_hdr64(const elf64_data_t *data, const char *file)
{
	print_file_name(file);
	print_format64();
	print_architecture(data->file_hdr->e_machine);
	print_flags64(data);
	print_start_address64(data->file_hdr->e_entry);
	printf("\n");
}
