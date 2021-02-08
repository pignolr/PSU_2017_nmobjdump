/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** print_source32.c
*/

#include <stdio.h>
#include "proto.h"

void	print_section_content32(const elf32_data_t *data,
				const Elf32_Shdr *section)
{
	size_t	i;

	for (i = 0; i < section->sh_size; i += 16) {
		printf(" %04lx", section->sh_offset + i);
		print_hexa_content((const char *)data->file_hdr,
				section->sh_offset + i,
				section->sh_size - i);
		print_char_content((const char *)data->file_hdr,
				section->sh_offset + i,
				section->sh_size - i);
		printf("\n");
	}
}

void	print_section32(const elf32_data_t *data,
			const Elf32_Shdr *section)
{
	const char	*strtab;

	strtab = (char *)data->file_hdr
		+ data->section_hdr[data->file_hdr->e_shstrndx].sh_offset;
	printf("Contents of section %s:\n", strtab + section->sh_name);
	print_section_content32(data, section);
}

void	print_source32(const elf32_data_t *data)
{
	size_t		i;

	for (i = 0; i < data->file_hdr->e_shnum; ++i) {
		if (data->section_hdr[i].sh_type != SHT_SYMTAB &&
			data->section_hdr[i].sh_type != SHT_STRTAB &&
			data->section_hdr[i].sh_type != SHT_RELA &&
			data->section_hdr[i].sh_size)
			print_section32(data, data->section_hdr + i);
	}
}
