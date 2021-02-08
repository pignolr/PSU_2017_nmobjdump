/*
** EPITECH PROJECT, 2018
** nm
** File description:
** main.c
*/

#include <stdio.h>
#include "proto.h"
#include "macro.h"
#include "error.h"

int	analyse_all_elf_file(int ac, char **av)
{
	int	i;
	int	err;

	err = 0;
	for (i = 1; i < ac; ++i) {
		if (analyse_elf_file(av[i], true))
			err = ERR_CODE;
	}
	return (err);
}

int	main(int ac, char **av)
{
	print_err(av[0], PEF_SET_EXEC_NAME);
	if (ac < 2)
		return (analyse_elf_file(DEFAULT_FILE, false));
	else if (ac == 2)
		return (analyse_elf_file(av[1], false));
	else
		return (analyse_all_elf_file(ac, av));
}
