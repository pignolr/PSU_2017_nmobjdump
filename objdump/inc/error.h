/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** error.h
*/

#ifndef ERROR_H_
	#define ERROR_H_

/*
** PEF for print_err_flag
*/
typedef enum	print_err_flag {
	PEF_PRINT = 0,
	PEF_PRINT_HEAD,
	PEF_SET_FILE_NAME,
	PEF_SET_EXEC_NAME
}		print_err_flag_t;

void	print_err(const char *str, print_err_flag_t flag);

#endif /* !ERROR_H_ */
