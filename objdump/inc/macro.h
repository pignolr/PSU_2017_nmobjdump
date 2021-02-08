/*
** EPITECH PROJECT, 2018
** objdump
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

#endif /* !MACRO_H_ */
