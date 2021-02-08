/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** check_elf32_file_hdr.c
*/

#include <unistd.h>
#include "proto.h"
#include "file_data.h"
#include "macro.h"
#include "error.h"

int	check_elf32_file_hdr_ident(const unsigned char *ident)
{
	if (check_is_elf_file(ident)
		|| (ident[EI_DATA] != 1 && ident[EI_DATA] != 2)
		|| ident[EI_PAD] != 0) {
		print_err(ERR_INVALID, PEF_PRINT);
		return (ERR_CODE);
	} else if (ident[EI_VERSION] != 1) {
		print_err(ERR_VERSION, PEF_PRINT);
		return (ERR_CODE);
	}
	return (0);
}
int	check_elf32_program_hdr(const Elf32_Phdr *program_hdr, size_t size)
{
	if (program_hdr->p_offset > size) {
		print_err(ERR_TRUNCATE, PEF_PRINT);
		return (ERR_CODE);
	} else if (!(program_hdr->p_align == 1
		|| IS_POWER_2(program_hdr->p_align))) {
		print_err(ERR_INVALID, PEF_PRINT);
		return (ERR_CODE);
	}
	return (0);
}

int	check_elf32_section_hdr(const Elf32_Shdr *section_hdr, size_t size)
{
	if (section_hdr->sh_name > size
		|| section_hdr->sh_offset > size
		|| section_hdr->sh_size > size
		|| section_hdr->sh_size + section_hdr->sh_offset > size) {
		print_err(ERR_TRUNCATE, PEF_PRINT);
		return (ERR_CODE);
	} else if (!IS_POWER_2(section_hdr->sh_addralign)) {
		print_err(ERR_INVALID, PEF_PRINT);
		return (ERR_CODE);
	}
	return (0);
}
