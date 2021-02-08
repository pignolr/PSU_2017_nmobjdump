/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** print_content.c
*/

#include <stdio.h>

void	print_hexa_content(const char *content, size_t offset, size_t limit)
{
	size_t	i;

	for (i = 0; i < 16; ++i) {
		if (!(i % 4))
			printf(" ");
		if (offset + i < limit)
			printf("%02x", (unsigned char)content[offset + i]);
		else
			printf("  ");
	}
	printf(" ");
}

void	print_char_content(const char *content, size_t offset, size_t limit)
{
	size_t	i;

	printf(" ");
	for (i = 0; i < 16; ++i) {
		if (offset + i < limit) {
			if (content[offset + i] >= ' '
				&& content[offset + i] < 127)
				printf("%c", content[offset + i]);
			else
				printf(".");
		} else
			printf(" ");
	}
}
