/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** proto.h
*/

#ifndef PROTO_H_
	#define PROTO_H_
	#include "file_data.h"

int	analyse_elf_file(const char *file);

int	get_fd_file(const char *file);
int	get_fd_size(int fd);
void	*read_data(int fd, int size);
int	free_data(void *data, int size);

int	check_is_elf_file(const void *data);
int	select_elf_architecture(const file_data_t *file);

int	analyse_elf64(const file_data_t *file);
int	check_elf64_data(const elf64_data_t *elf_data);
int	check_elf64_file_hdr_ident(const unsigned char *ident);
int	check_elf64_program_hdr_type(uint32_t program_hdr);
int	check_elf64_program_hdr(const Elf64_Phdr *program_hdr, size_t size);
int	check_elf64_section_hdr(const Elf64_Shdr *program_hdr, size_t size);

int	analyse_elf32(const file_data_t *file);
int	check_elf32_data(const elf32_data_t *elf_data);
int	check_elf32_file_hdr_ident(const unsigned char *ident);
int	check_elf32_program_hdr_type(uint32_t program_hdr);
int	check_elf32_program_hdr(const Elf32_Phdr *program_hdr, size_t size);
int	check_elf32_section_hdr(const Elf32_Shdr *program_hdr, size_t size);

int	do_objdump64(const elf64_data_t *data, const char *file);
void	print_file_hdr64(const elf64_data_t *data, const char *file);

int	do_objdump32(const elf32_data_t *data, const char *file);
void	print_file_hdr32(const elf32_data_t *data, const char *file);

void	print_file_name(const char *file);
void	print_architecture(uint16_t machine);
void	print_if_is_flag(size_t *value, uint32_t flag, const char *str);
void	print_flags64(const elf64_data_t *data);
void	print_flags32(const elf32_data_t *data);

void	print_source64(const elf64_data_t *data);
void	print_source32(const elf32_data_t *data);
void	print_hexa_content(const char *content,
				size_t offset,
				size_t limit);
void	print_char_content(const char *content,
				size_t offset,
				size_t limit);

#endif /* !PROTO_H_ */
