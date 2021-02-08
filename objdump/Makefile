##
## EPITECH PROJECT, 2018
## objdump
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

NAME		=	my_objdump

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
		src/objdump/objdump64bits.c \
		src/objdump/objdump32bits.c \
		src/objdump/print_file_hdr.c \
		src/objdump/print_file_hdr64.c \
		src/objdump/print_flags64.c \
		src/objdump/print_source64.c \
		src/objdump/print_file_hdr32.c \
		src/objdump/print_flags32.c \
		src/objdump/print_source32.c \
		src/objdump/print_content.c \
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
