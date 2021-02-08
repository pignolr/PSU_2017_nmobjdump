/*
** EPITECH PROJECT, 2018
** nm
** File description:
** elf_check.c
*/

#include <elf.h>
#include "proto.h"
#include "macro.h"
#include "error.h"

int	check_is_elf_file(const void *data)
{
	if (!(((char *)data)[EI_MAG0] != ELFMAG0 ||
		((char *)data)[EI_MAG1] != ELFMAG1 ||
		((char *)data)[EI_MAG2] != ELFMAG2 ||
		((char *)data)[EI_MAG3] != ELFMAG3))
		return (0);
	return (ERR_CODE);
}
