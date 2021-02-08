/*
** EPITECH PROJECT, 2018
** nm
** File description:
** macro.h
*/

#ifndef MACRO_H_
	#define MACRO_H_

	#define IS_POWER_2(nb) (!(nb & (nb - 1)))

extern const char	*DEFAULT_FILE;
extern const int	ERR_CODE;
extern const char	*ERR_INVALID;
extern const char	*ERR_VERSION;
extern const char	*ERR_TRUNCATE;
extern const char	*ERR_SYMTAB;
extern const char	*ERR_MALLOC;

#endif /* !MACRO_H_ */
