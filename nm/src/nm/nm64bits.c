/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm64bits.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "proto.h"
#include "error.h"
#include "macro.h"

void	print_symbol64(const char *strtab,
			const Elf64_Sym *symbol_section,
			char symbol)
{
	if (symbol_section->st_shndx)
		printf("%016lx ", symbol_section->st_value);
	else
		printf("                 ");
	printf("%c %s\n", symbol, strtab + symbol_section->st_name);
}

void	print_symtab64(const elf64_data_t *data,
			const Elf64_Shdr *symtab_section,
			const char *strtab,
			const size_t *idx_strtab)
{
	const Elf64_Shdr	*section;
	const Elf64_Sym		*symtab;
	const Elf64_Sym		*symbol_section;
	size_t			i;
	size_t			nb_symbol;
	char			symbol;

	nb_symbol = symtab_section->sh_size / symtab_section->sh_entsize;
	symtab = (Elf64_Sym *)
		((char *)data->file_hdr + symtab_section->sh_offset);
	for (i = 0; i < nb_symbol; ++i) {
		symbol_section = symtab + idx_strtab[i];
		if (symbol_section->st_name) {
			section = data->section_hdr + symbol_section->st_shndx;
			symbol = get_symbol64(section, symbol_section);
			if (symbol != 'a')
				print_symbol64(strtab, symbol_section, symbol);
		}
	}
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
	print_err(ERR_SYMTAB, PEF_PRINT);
	return (NULL);
}

int	do_nm64(const elf64_data_t *data,
		const char *file,
		bool multiple_file)
{
	const Elf64_Shdr	*symtab_section;
	const char		*strtab;
	size_t			*idx_strtab;

	symtab_section = get_nm64_symtab(data);
	if (!symtab_section)
		return (ERR_CODE);
	strtab = (char *)data->file_hdr
		+ data->section_hdr[symtab_section->sh_link].sh_offset;
	idx_strtab = get_nm64_idx_sorted_strtab(data, symtab_section, strtab);
	if (!idx_strtab)
		return (ERR_CODE);
	if (multiple_file)
		printf("\n%s\n", file);
	print_symtab64(data, symtab_section, strtab, idx_strtab);
	free(idx_strtab);
	return (0);
}
