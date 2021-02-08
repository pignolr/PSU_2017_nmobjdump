/*
** EPITECH PROJECT, 2018
** nm
** File description:
** analyse32.c
*/

#include "proto.h"
#include "file_data.h"
#include "macro.h"
#include "error.h"

int	init_elf32_data(elf32_data_t *elf_data, const file_data_t *file)
{
	elf_data->size = file->size;
	if (elf_data->size < sizeof(Elf32_Ehdr)) {
		print_err(ERR_INVALID, PEF_PRINT);
		return (ERR_CODE);
	}
	elf_data->file_hdr = (Elf32_Ehdr *)file->data;

	elf_data->program_hdr = (Elf32_Phdr *)
		((char *)elf_data->file_hdr + elf_data->file_hdr->e_phoff);
	elf_data->section_hdr = (Elf32_Shdr *)
		((char *)elf_data->file_hdr + elf_data->file_hdr->e_shoff);
	return (0);
}

int	analyse_elf32(const file_data_t *file, bool multiple_file)
{
	elf32_data_t	elf_data;

	if (init_elf32_data(&elf_data, file)
		|| check_elf32_data(&elf_data)
		|| do_nm32(&elf_data, file->file, multiple_file))
		return (ERR_CODE);
	return (0);
}
