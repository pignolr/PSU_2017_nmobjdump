/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm.c
*/

#include <unistd.h>
#include "proto.h"
#include "file_data.h"
#include "macro.h"
#include "error.h"

int	select_elf_architecture(const file_data_t *file, bool multiple_file)
{
	switch (((const char *)file->data)[EI_CLASS]) {
		case ELFCLASS32:
			if (file->size >= sizeof(Elf32_Ehdr))
				return (analyse_elf32(file, multiple_file));
			break;
		case ELFCLASS64:
			if (file->size >= sizeof(Elf64_Ehdr))
				return (analyse_elf64(file, multiple_file));
			break;
		default:
			break;
	}
	print_err("Invalid format file", PEF_PRINT);
	return (ERR_CODE);
}

int	init_file_info(file_data_t *file_info)
{
	int	fd;

	fd = get_fd_file(file_info->file);
	if (fd == -1)
		return (ERR_CODE);
	file_info->size = get_fd_size(fd);
	if ((int)file_info->size == -1) {
		close(fd);
		return (ERR_CODE);
	}
	file_info->data = read_data(fd, file_info->size);
	close(fd);
	return (file_info->data ? 0 : ERR_CODE);
}

int	analyse_elf_file(const char *file, bool multiple_file)
{
	file_data_t	file_info;
	int		err;

	print_err(file, PEF_SET_FILE_NAME);
	file_info.file = file;
	if (init_file_info(&file_info))
		return (ERR_CODE);
	err = 0;
	if (select_elf_architecture(&file_info, multiple_file))
		err = ERR_CODE;
	err += free_data(file_info.data, file_info.size);
	return (err ? ERR_CODE : 0);
}
