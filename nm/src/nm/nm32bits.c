/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm32bits.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "proto.h"
#include "error.h"
#include "macro.h"

void	print_symbol32(const char *strtab,
			const Elf32_Sym *symbol_section,
			char symbol)
{
	if (symbol_section->st_shndx)
		printf("%08x ", symbol_section->st_value);
	else
		printf("         ");
	printf("%c %s\n", symbol, strtab + symbol_section->st_name);
}

void	print_symtab32(const elf32_data_t *data,
			const Elf32_Shdr *symtab_section,
			const char *strtab,
			const size_t *idx_strtab)
{
	const Elf32_Shdr	*section;
	const Elf32_Sym		*symtab;
	const Elf32_Sym		*symbol_section;
	size_t			i;
	size_t			nb_symbol;
	char			symbol;

	nb_symbol = symtab_section->sh_size / symtab_section->sh_entsize;
	symtab = (Elf32_Sym *)
		((char *)data->file_hdr + symtab_section->sh_offset);
	for (i = 0; i < nb_symbol; ++i) {
		symbol_section = symtab + idx_strtab[i];
		if (symbol_section->st_name) {
			section = data->section_hdr + symbol_section->st_shndx;
			symbol = get_symbol32(section, symbol_section);
			if (symbol != 'a')
				print_symbol32(strtab, symbol_section, symbol);
		}
	}
}

const Elf32_Shdr	*get_nm32_symtab(const elf32_data_t *data)
{
	const Elf32_Shdr	*symtab_section;
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
	print_err(ERR_SYMTAB, PEF_PRINT);
	return (NULL);
}

int	do_nm32(const elf32_data_t *data,
		const char *file,
		bool multiple_file)
{
	const Elf32_Shdr	*symtab_section;
	const char		*strtab;
	size_t			*idx_strtab;

	symtab_section = get_nm32_symtab(data);
	if (!symtab_section)
		return (ERR_CODE);
	strtab = (char *)data->file_hdr
		+ data->section_hdr[symtab_section->sh_link].sh_offset;
	idx_strtab = get_nm32_idx_sorted_strtab(data, symtab_section, strtab);
	if (!idx_strtab)
		return (ERR_CODE);
	if (multiple_file)
		printf("\n%s\n", file);
	print_symtab32(data, symtab_section, strtab, idx_strtab);
	free(idx_strtab);
	return (0);
}
