/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** print_source64.c
*/

#include <stdio.h>
#include "proto.h"

void	print_section_content64(const elf64_data_t *data,
				const Elf64_Shdr *section)
{
	size_t	i;

	for (i = 0; i < section->sh_size; i += 16) {
		printf(" %04lx", section->sh_addr + i);
		print_hexa_content((const char *)data->file_hdr,
				section->sh_offset + i,
				section->sh_offset + section->sh_size);
		print_char_content((const char *)data->file_hdr,
				section->sh_offset + i,
				section->sh_offset + section->sh_size);
		printf("\n");
	}
}

void	print_section64(const elf64_data_t *data,
			const Elf64_Shdr *section)
{
	const char	*strtab;

	strtab = (char *)data->file_hdr
		+ data->section_hdr[data->file_hdr->e_shstrndx].sh_offset;
	printf("Contents of section %s:\n", strtab + section->sh_name);
	print_section_content64(data, section);
}

const Elf64_Shdr	*get_nm64_symtab(const elf64_data_t *data)
{
	const Elf64_Shdr	*symtab_section;
	size_t			i;

	symtab_section = data->section_hdr;
	for (i = 0; i < data->file_hdr->e_shnum; ++i) {
		++symtab_section;
		if (symtab_section->sh_type == SHT_SYMTAB
			&& symtab_section->sh_link < data->file_hdr->e_shnum
			&& data->section_hdr[symtab_section->sh_link].sh_type
				== SHT_STRTAB)
			return (symtab_section);
	}
	return (NULL);
}

void	print_source64(const elf64_data_t *data)
{
	const Elf64_Shdr	*symtab_section;
	size_t			i;

	symtab_section = get_nm64_symtab(data);
	for (i = 0; i < data->file_hdr->e_shnum; ++i) {
		if (i != data->file_hdr->e_shstrndx
			&& (!symtab_section || i != symtab_section->sh_link)
			&& data->section_hdr + i != symtab_section
			&& data->section_hdr[i].sh_type != SHT_NOBITS
			&& data->section_hdr[i].sh_size)
			print_section64(data, data->section_hdr + i);
	}
}
