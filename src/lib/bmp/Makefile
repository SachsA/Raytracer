##
## Makefile for wolf3d in /home/lombar_e/rendu/Infographie/wolf3d/src/libbmp
##
## Made by Thomas Lombard
## Login   <lombar_e@epitech.net>
##
## Started on  Tue Jan 03 16:42:46 2017 Thomas Lombard
## Last update Fri May 26 18:52:51 2017 Theodore Marestin
##

SHELL		=  bash

NAME		=  libbmp.a

CFLAGS		+= -W -Wall -Wextra
CFLAGS		+= -pipe -O2
CFLAGS		+= -Wunreachable-code -Winit-self -Wuninitialized
CFLAGS		+= -Wno-unused-result
CFLAGS		+= -fsanitize=leak -fsanitize=unreachable -fsanitize=return

AR		=  ar rcs

CC		=  gcc

SRC		=  load.c		\
		   parser_init.c	\
		   load_bitmap.c	\
		   bmp_calloc.c		\
		   bmp_memset.c		\
		   load_1-8bits.c	\
		   load_16-32bits.c

OBJ		=  $(SRC:.c=.o)

RM		=  rm -f

$(NAME): _init $(OBJ)
	@echo -ne "\033[93mLinkage de\033[35m" $(NAME) "\033[m"
	@tput hpa $$(($$(tput cols) - 18));
	@$(AR) $(NAME) $(OBJ) &&				\
	echo -ne "-=[\033[1;32m  COMPLETE  \033[m]=-\n" ||	\
	echo -ne "-=[\033[1;31m FAIL \033[m]=-\n"

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

.c.o:
	@echo -ne "\033[33mCompilation de\033[36m" $(notdir $<) "\033[m"
	@tput hpa $$(($$(tput cols) - 12));
	@$(CC) -c -o $@ $< $(CFLAGS) &&			\
	echo -ne "-=[\033[1;32m  OK  \033[m]=-\n" ||	\
	echo -ne "-=[\033[1;31m  FAIL  \033[m]=-\n"

_init:
	@echo -ne "\033[93mLibrairie:\033[35m" $(NAME) "\033[m\n"

re: fclean all

.PHONY:	all clean fclean re
