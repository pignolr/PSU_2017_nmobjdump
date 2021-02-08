/*
** EPITECH PROJECT, 2018
** nm
** File description:
** private_macro_error.h
*/

#ifndef PRIVATE_MACRO_ERROR_H_
	#define PRIVATE_MACRO_ERROR_H_
	#include <stdio.h>

static inline void	print_err_with_print_head_flag(const char *file,
							const char *exec)
{
	fprintf(stderr, "%s: %s: ", file, exec);
}

static inline void	print_err_with_print_flag(const char *file,
							const char *exec,
							const char *str)
{
	fprintf(stderr, "%s: %s: %s\n", file, exec, str);
}

static inline void	print_err_with_invalid_flag(const char *file)
{
	fprintf(stderr, "%s: Invalid flag for print_err\n", file);
}

#endif /* !PRIVATE_MACRO_ERROR_H_ */
