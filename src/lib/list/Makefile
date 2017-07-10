##
## Makefile for chained in /src/lib/list
##
## Made by Thomas Lombard
## Login   <lombar_e@epitech.net>
##
## Started on  Mon Apr 24 14:49:54 2017 Thomas Lombard
## Last update Fri May 26 18:51:32 2017 Theodore Marestin
##

SHELL		=  bash

NAME		=  libst.a

CFLAGS		+= -W -Wall -Wextra
CFLAGS		+= -pipe -O2
CFLAGS		+= -Wunreachable-code -Winit-self -Wuninitialized
CFLAGS		+= -Wno-unused-result
CFLAGS		+= -fsanitize=leak -fsanitize=unreachable -fsanitize=return

AR		=  ar rcs

CC		=  gcc

SRC		=  append.c		\
		   detach.c		\
		   getter.c		\
		   measurement.c	\
		   remove.c

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
	echo -ne "-=[\033[1;31m FAIL \033[m]=-\n"

_init:
	@echo -ne "\033[93mLibrairie:\033[35m" $(NAME) "\033[m\n"

re: fclean all

.PHONY:	all clean fclean re
