/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** print_flags.c
*/

#include <stdio.h>
#include <string.h>
#include "flags.h"
#include "proto.h"

void	set_flags32(const char *strtab,
			const Elf32_Shdr *section,
			size_t *flags)
{
	if (section->sh_type == SHT_SYMTAB)
		*flags |= HAS_SYMS;
	if (section->sh_type == SHT_DYNSYM)
		*flags |= D_PAGED;
	if (!strcmp(strtab + section->sh_name, ".text")
		&& section->sh_flags & SHF_WRITE)
		*flags |= WP_TEXT;
}

size_t	get_flags32(const elf32_data_t *data)
{
	const char	*strtab;
	size_t		flags;
	size_t		i;

	flags = BFD_NO_FLAGS;
	if (data->file_hdr->e_type == ET_EXEC)
		flags = EXEC_P;
	else if (data->file_hdr->e_type == ET_REL)
		flags = HAS_RELOC;
	else if (data->file_hdr->e_type == ET_DYN)
		flags = DYNAMIC;
	strtab = (char *)data->file_hdr
		+ data->section_hdr[data->file_hdr->e_shstrndx].sh_offset;
	for (i = 0; i < data->file_hdr->e_shnum; ++i)
		set_flags32(strtab, data->section_hdr + i, &flags);
	printf("flags 0x%08lx", flags);
	return (flags);
}

void	print_flags32(const elf32_data_t *data)
{
	size_t	flags;

	flags = get_flags32(data);
	if (flags == BFD_NO_FLAGS) {
		printf("\n");
		return ;
	}
	printf(":\n");
	print_if_is_flag(&flags, HAS_RELOC, "HAS_RELOC");
	print_if_is_flag(&flags, EXEC_P, "EXEC_P");
	print_if_is_flag(&flags, HAS_LINENO, "HAS_LINENO");
	print_if_is_flag(&flags, HAS_DEBUG, "HAS_DEBUG");
	print_if_is_flag(&flags, HAS_SYMS, "HAS_SYMS");
	print_if_is_flag(&flags, HAS_LOCALS, "HAS_LOCALS");
	print_if_is_flag(&flags, DYNAMIC, "DYNAMIC");
	print_if_is_flag(&flags, WP_TEXT, "WP_TEXT");
	print_if_is_flag(&flags, D_PAGED, "D_PAGED");
	printf("\n");
}
