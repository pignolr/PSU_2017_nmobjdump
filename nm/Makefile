##
## EPITECH PROJECT, 2018
## nm
## File description:
## Makefile
##

CC		= gcc

CFLAGS		+= -W -Wall -Wextra -Werror

DEBUG		?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

CPPFLAGS	+= -Iinc

LDFLAGS		+=

LDLIBS		+=

NAME		=	my_nm

SRCS		=\
		src/controle/analyse.c \
		src/controle/analyse64.c \
		src/controle/analyse32.c \
		src/controle/get_file.c \
		src/elf_check/check_elf.c \
		src/elf_check/check_elf64.c \
		src/elf_check/check_elf64_extra.c \
		src/elf_check/check_elf32.c \
		src/elf_check/check_elf32_extra.c \
		src/utilities/error.c \
		src/utilities/macro.c \
		src/nm/nm_get_sorted_strtab.c \
		src/nm/nm32_get_sorted_strtab.c \
		src/nm/nm64_get_sorted_strtab.c \
		src/nm/nm32_get_symbol.c \
		src/nm/nm64_get_symbol.c \
		src/nm/nm32bits.c \
		src/nm/nm64bits.c \
		src/main.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
