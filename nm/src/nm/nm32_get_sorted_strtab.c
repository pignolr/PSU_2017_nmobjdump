/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm_get_sorted_strtab.c
*/

#include <string.h>
#include "proto.h"
#include "error.h"
#include "macro.h"

void	sort_idx_strtab32(const elf32_data_t *file,
				const Elf32_Shdr *symtab_section,
				const char *strtab,
				size_t	*idx_strtab)
{
	const Elf32_Sym	*symtab;
	size_t		nb_symbol;
	size_t		i;

	nb_symbol = symtab_section->sh_size / symtab_section->sh_entsize;
	symtab = (Elf32_Sym *)
		((char *)file->file_hdr + symtab_section->sh_offset);
	i = 1;
	while (i < nb_symbol) {
		if (i && strncmp(strtab + symtab[idx_strtab[i - 1]].st_name,
				strtab + symtab[idx_strtab[i]].st_name,
				symtab_section->sh_entsize) > 0) {
			i = swap_idx_strtab(idx_strtab, i);
		} else
			++i;
	}
}

size_t	*get_nm32_idx_sorted_strtab(const elf32_data_t *file,
				const Elf32_Shdr *symtab_section,
				const char *strtab)
{
	size_t	*idx_strtab;

	idx_strtab = get_idx_not_sorted_strtab(symtab_section->sh_size
						/ symtab_section->sh_entsize);
	if (!idx_strtab)
		return (NULL);
	sort_idx_strtab32(file, symtab_section, strtab, idx_strtab);
	return (idx_strtab);
}
