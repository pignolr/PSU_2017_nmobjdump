/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** print_file_hdr.c
*/

#include <stdio.h>
#include <string.h>
#include <elf.h>
#include "flags.h"
#include "file_data.h"

void	print_file_name(const char *file)
{
	printf("\n%s:%5c", file, ' ');
}

void	print_architecture(uint16_t machine)
{
	const char	*architecture;

	switch (machine) {
		case EM_X86_64:
			architecture = "i386:x86-64";
			break;
		case EM_386:
			architecture = "i386:x86";
			break;
		default:
			architecture = "unknown";
			break;
	}
	printf("architecture: %s, ", architecture);
}

void	print_if_is_flag(size_t *value, uint32_t flag, const char *str)
{
	if (*value & flag) {
		printf("%s", str);
		*value ^= flag;
		if (*value)
			printf(", ");
	}
}
