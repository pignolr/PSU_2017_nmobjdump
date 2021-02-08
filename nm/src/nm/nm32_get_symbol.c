/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm32_get_symb.c
*/

#include "file_data.h"
#include "error.h"
#include "macro.h"

char	get_symbol32_try_1(const Elf32_Sym *symb)
{
	if (ELF32_ST_BIND(symb->st_info) == STB_GNU_UNIQUE)
		return ('u');
	if (symb->st_shndx == SHN_ABS)
		return ('A');
	if (ELF32_ST_BIND(symb->st_info) == STB_WEAK
		&& ELF32_ST_TYPE(symb->st_info) == STT_OBJECT)
		return (symb->st_shndx == SHN_UNDEF ? 'v' : 'V');
	if (ELF32_ST_BIND(symb->st_info) == STB_WEAK)
		return (symb->st_shndx == SHN_UNDEF ? 'w' : 'W');
	if (symb->st_shndx == SHN_UNDEF)
		return ('U');
	if (symb->st_shndx == SHN_COMMON)
		return ('C');
	return (0);
}

char	get_symbol32_try_2(const Elf32_Shdr *sect, const Elf32_Sym *symb)
{
	if (ELF64_ST_TYPE(symb->st_info) == 6)
		return ('B');
	else if (sect->sh_type == SHT_NOBITS
		&& (sect->sh_flags == 1027
			|| sect->sh_flags == (SHF_ALLOC | SHF_WRITE)))
		return ('B');
	if (symb->st_shndx == 4)
		return ('R');
	else if (ELF64_ST_TYPE(symb->st_info) == STT_OBJECT
		&& symb->st_shndx == 13)
		return ('R');
	else if (sect->sh_type == SHT_PROGBITS && sect->sh_flags == SHF_ALLOC)
		return ('R');
	if ((sect->sh_type == SHT_PROGBITS || sect->sh_type == SHT_DYNAMIC)
		&& sect->sh_flags == (SHF_ALLOC | SHF_WRITE))
		return ('D');
	else if (ELF64_ST_TYPE(symb->st_info) == STT_OBJECT
		&& symb->st_shndx == 21)
		return ('D');
	return (0);
}

char	get_symbol32_try_3(const Elf32_Shdr *sect, const Elf32_Sym *symb)
{
	if ((sect->sh_type == SHT_PROGBITS
			&& sect->sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
		|| symb->st_shndx == 16 || symb->st_shndx == 17
		|| symb->st_shndx == 21 || symb->st_shndx == 19
		|| symb->st_shndx == 20 || symb->st_shndx == 10
		|| symb->st_shndx == 2)
		return ('T');
	if ((sect->sh_type == SHT_PROGBITS && sect->sh_flags == 0)
		|| ELF32_ST_TYPE(symb->st_info) == STT_TLS
		|| ELF32_ST_TYPE(symb->st_info) == STT_NOTYPE)
		return ('n');
	return (0);
}

char	get_symbol32(const Elf32_Shdr *sect, const Elf32_Sym *symb)
{
	char	c;

	c = get_symbol32_try_1(symb);
	if (!c)
		c = get_symbol32_try_2(sect, symb);
	if (!c)
		c = get_symbol32_try_3(sect, symb);
	if (!c)
		c = '?';
	if (ELF32_ST_BIND(symb->st_info) == STB_LOCAL
		&& c != '?' && c != 'U' && c != 'u' && c != 'n')
		c += 32;
	return (c);
}
