/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** print_file_hdr32.c
*/

#include <stdio.h>
#include <string.h>
#include "proto.h"

void	print_format32(void)
{
	printf("file format elf32-x86\n");
}

void	print_start_address32(Elf32_Addr flags)
{
	printf("start address 0x%08x\n", flags);
}

void	print_file_hdr32(const elf32_data_t *data, const char *file)
{
	print_file_name(file);
	print_format32();
	print_architecture(data->file_hdr->e_machine);
	print_flags32(data);
	print_start_address32(data->file_hdr->e_entry);
	printf("\n");
}
