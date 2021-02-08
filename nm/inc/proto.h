/*
** EPITECH PROJECT, 2018
** nm
** File description:
** proto.h
*/

#ifndef PROTO_H_
	#define PROTO_H_
	#include <stdbool.h>
	#include "file_data.h"

int	analyse_elf_file(const char *file, bool multiple_file);

int	get_fd_file(const char *file);
int	get_fd_size(int fd);
void	*read_data(int fd, int size);
int	free_data(void *data, int size);

int	check_is_elf_file(const void *data);
int	select_elf_architecture(const file_data_t *file, bool multiple_file);

int	analyse_elf64(const file_data_t *file, bool multiple_file);
int	check_elf64_data(const elf64_data_t *elf_data);
int	check_elf64_file_hdr_ident(const unsigned char *ident);
int	check_elf64_program_hdr_type(uint32_t program_hdr);
int	check_elf64_program_hdr(const Elf64_Phdr *program_hdr, size_t size);
int	check_elf64_section_hdr(const Elf64_Shdr *program_hdr, size_t size);

int	analyse_elf32(const file_data_t *file, bool multiple_file);
int	check_elf32_data(const elf32_data_t *elf_data);
int	check_elf32_file_hdr_ident(const unsigned char *ident);
int	check_elf32_program_hdr_type(uint32_t program_hdr);
int	check_elf32_program_hdr(const Elf32_Phdr *program_hdr, size_t size);
int	check_elf32_section_hdr(const Elf32_Shdr *program_hdr, size_t size);

int	do_nm64(const elf64_data_t *data,
		const char *file,
		bool multiple_file);
size_t	*get_nm64_idx_sorted_strtab(const elf64_data_t *file,
				const Elf64_Shdr *symtab_section,
				const char *strtab);
char	get_symbol64(const Elf64_Shdr *symtab_section,
			const Elf64_Sym *symbol_section);

int	do_nm32(const elf32_data_t *data,
		const char *file,
		bool multiple_file);
size_t	*get_nm32_idx_sorted_strtab(const elf32_data_t *file,
				const Elf32_Shdr *symtab_section,
				const char *strtab);
char	get_symbol32(const Elf32_Shdr *symtab_section,
			const Elf32_Sym *symbol_section);

size_t	*get_idx_not_sorted_strtab(size_t nb_symbol);
size_t	swap_idx_strtab(size_t *idx_strtab, size_t i);

#endif /* !PROTO_H_ */
