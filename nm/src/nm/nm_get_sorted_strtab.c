/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm_get_sorted_strtab.c
*/

#include <stdlib.h>
#include "file_data.h"
#include "error.h"
#include "macro.h"

size_t	*get_idx_not_sorted_strtab(size_t nb_symbol)
{
	size_t	*idx_strtab;
	size_t	i;

	idx_strtab = (size_t *)malloc(nb_symbol * sizeof(size_t));
	if (!idx_strtab) {
		print_err(ERR_MALLOC, PEF_PRINT);
		return (NULL);
	}
	for (i = 0; i < nb_symbol; ++i)
		idx_strtab[i] = i;
	return (idx_strtab);
}

size_t	swap_idx_strtab(size_t *idx_strtab, size_t i)
{
	size_t		tmp;

	tmp = idx_strtab[i];
	idx_strtab[i] = idx_strtab[i - 1];
	idx_strtab[i - 1] = tmp;
	if (--i)
		--i;
	return (i);
}
