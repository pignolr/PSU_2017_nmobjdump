/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** check_elf32.c
*/

#include <unistd.h>
#include "proto.h"
#include "file_data.h"
#include "macro.h"
#include "error.h"

int	check_elf32_file_hdr(const Elf32_Ehdr *file_hdr)
{
	if (check_elf32_file_hdr_ident(file_hdr->e_ident))
		return (ERR_CODE);
	else if (file_hdr->e_version != EV_CURRENT) {
		print_err(ERR_INVALID, PEF_PRINT);
		return (ERR_CODE);
	}
	return (0);
}

int	check_all_elf32_program_hdr(const elf32_data_t *elf_data)
{
	const Elf32_Phdr	*program_hdr;
	int			i;

	if (elf_data->file_hdr->e_phoff
		+ elf_data->file_hdr->e_phnum
		* elf_data->file_hdr->e_phentsize
		> elf_data->size) {
		print_err(ERR_TRUNCATE, PEF_PRINT);
		return (ERR_CODE);
	}
	program_hdr = elf_data->program_hdr;
	for (i = 0; i < elf_data->file_hdr->e_phnum; ++i) {
		if (check_elf32_program_hdr(program_hdr, elf_data->size))
			return (ERR_CODE);
		program_hdr = (const Elf32_Phdr *)
			((char *)program_hdr + elf_data->file_hdr->e_phentsize);
	}
	return (0);
}

int	check_all_elf32_section_hdr(const elf32_data_t *elf_data)
{
	const Elf32_Shdr	*section_hdr;
	int			i;

	if (elf_data->file_hdr->e_shoff
		+ elf_data->file_hdr->e_shnum
		* elf_data->file_hdr->e_shentsize
		> elf_data->size) {
		print_err(ERR_TRUNCATE, PEF_PRINT);
		return (ERR_CODE);
	}
	section_hdr = elf_data->section_hdr;
	for (i = 0; i < elf_data->file_hdr->e_shnum; ++i) {
		if (check_elf32_section_hdr(section_hdr, elf_data->size))
			return (ERR_CODE);
		section_hdr = (const Elf32_Shdr *)
			((char *)section_hdr + elf_data->file_hdr->e_shentsize);
	}
	return (0);
}

int	check_elf32_data(const elf32_data_t *elf_data)
{
	if (check_elf32_file_hdr(elf_data->file_hdr)
		|| check_all_elf32_program_hdr(elf_data)
		|| check_all_elf32_section_hdr(elf_data))
		return (ERR_CODE);
	return (0);
}
