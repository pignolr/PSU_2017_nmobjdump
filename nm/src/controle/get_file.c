/*
** EPITECH PROJECT, 2018
** nm
** File description:
** get_file.c
*/

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "macro.h"
#include "error.h"

int	get_fd_file(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1) {
		print_err(NULL, PEF_PRINT_HEAD);
		perror(NULL);
	}
	return (fd);
}

int	get_fd_size(int fd)
{
	struct stat	s;

	if (!fstat(fd, &s))
		return (s.st_size);
	print_err(NULL, PEF_PRINT_HEAD);
	perror(NULL);
	return (-1);
}

void	*read_data(int fd, int size)
{
	void	*data;

	data = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
	if (data != MAP_FAILED)
		return (data);
	print_err(NULL, PEF_PRINT_HEAD);
	perror(NULL);
	return (NULL);
}

int	free_data(void *data, int size)
{
	if (munmap(data, size) != -1)
		return (0);
	print_err(NULL, PEF_PRINT_HEAD);
	perror(NULL);
	return (ERR_CODE);
}
