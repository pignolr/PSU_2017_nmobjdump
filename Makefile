##
## EPITECH PROJECT, 2018
## nmobjdump
## File description:
## Makefile
##

MY_MAKE		= $(MAKE)
TARGETS		= nm objdump

all:	$(TARGETS)

nm:
	$(MY_MAKE) -C ./nm && cp ./nm/my_nm .

objdump:
	$(MY_MAKE) -C ./objdump && cp ./objdump/my_objdump .

clean:
	$(MY_MAKE) -C nm clean
	$(MY_MAKE) -C objdump clean

fclean:
	$(MY_MAKE) -C nm fclean
	$(MY_MAKE) -C objdump fclean
	$(RM) my_nm my_objdump

re: fclean all

.PHONY: all nm objdump clean fclean re
