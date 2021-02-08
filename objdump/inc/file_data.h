/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** file_data.h
*/

#ifndef OBJDUMP_H_
	#define OBJDUMP_H_
	#include <stddef.h>
	#include <elf.h>

typedef struct	file_data
{
	const char	*file;
	size_t		size;
	void		*data;
}		file_data_t;

typedef struct			elf64_data
{
	const Elf64_Ehdr	*file_hdr;
	const Elf64_Phdr	*program_hdr;
	const Elf64_Shdr	*section_hdr;
	size_t			size;
}				elf64_data_t;

typedef struct			elf32_data
{
	const Elf32_Ehdr	*file_hdr;
	const Elf32_Phdr	*program_hdr;
	const Elf32_Shdr	*section_hdr;
	size_t			size;
}				elf32_data_t;

#endif /* !OBJDUMP_H_ */
