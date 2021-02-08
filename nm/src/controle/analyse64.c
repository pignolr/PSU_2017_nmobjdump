/*
** EPITECH PROJECT, 2018
** nm
** File description:
** analyse64.c
*/

#include "proto.h"
#include "file_data.h"
#include "macro.h"
#include "error.h"

int	init_elf64_data(elf64_data_t *elf_data, const file_data_t *file)
{
	elf_data->size = file->size;
	if (elf_data->size < sizeof(Elf64_Ehdr)) {
		print_err(ERR_INVALID, PEF_PRINT);
		return (ERR_CODE);
	}
	elf_data->file_hdr = (Elf64_Ehdr *)file->data;

	elf_data->program_hdr = (Elf64_Phdr *)
		((char *)elf_data->file_hdr + elf_data->file_hdr->e_phoff);
	elf_data->section_hdr = (Elf64_Shdr *)
		((char *)elf_data->file_hdr + elf_data->file_hdr->e_shoff);
	return (0);
}

int	analyse_elf64(const file_data_t *file, bool multiple_file)
{
	elf64_data_t	elf_data;

	if (init_elf64_data(&elf_data, file)
		|| check_elf64_data(&elf_data)
		|| do_nm64(&elf_data, file->file, multiple_file))
		return (ERR_CODE);
	return (0);
}
