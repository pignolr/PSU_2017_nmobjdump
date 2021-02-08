/*
** EPITECH PROJECT, 2018
** nm
** File description:
** error.c
*/
#include "private_macro_error.h"
#include "error.h"

void	print_err(const char *str, print_err_flag_t flag)
{
	static const char	*file = NULL;
	static const char	*exec = NULL;

	switch (flag) {
		case PEF_PRINT_HEAD:
			print_err_with_print_head_flag(exec, file);
			break;
		case PEF_PRINT:
			print_err_with_print_flag(exec, file, str);
			break;
		case PEF_SET_FILE_NAME:
			file = str;
			break;
		case PEF_SET_EXEC_NAME:
			exec = str;
			break;
		default:
			print_err_with_invalid_flag(exec);
			break;
	}
}
