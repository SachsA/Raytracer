##
## Makefile for raytracer2 in /Infographie/raytracer2
##
## Made by Thomas Lombard
## Login   <lombar_e@epitech.net>
##
## Started on  Wed May 05 13:53:50 2017 Thomas Lombard
## Last update Sun May 28 14:23:46 2017 Theodore Marestin
##

SHELL		= bash

NAME		=  raytracer2

CFLAGS		+= -W -Wall -Wextra -O2
CFLAGS		+= -I includes/
CFLAGS		+= -pipe
CFLAGS		+= -Wunreachable-code -Winit-self -Wuninitialized
CFLAGS		+= -Wno-unused-result
CFLAGS		+= -fsanitize=leak -fsanitize=unreachable -fsanitize=return -fno-builtin
CFLAGS		+= $(FLAGS)

LDFLAGS		+= -L. -Lsrc/lib/list -Lsrc/lib/bmp
LDFLAGS		+= -lmy -lbmp -lm -lst -lpthread -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

AR		=  ar rcs

LIBNAME		=  libmy.a

CC		=  gcc

RM		=  rm -f

## Ajouter les sources sans src/ (cf 1)

PROJ_SOURCE	=  core_init_kill.c					\
		   main.c						\
		   pixel_calculations/pixel_process.c			\
		   pixel_calculations/find_obj.c			\
		   pixel_calculations/light/add.c			\
		   pixel_calculations/light/update_color.c		\
		   pixel_calculations/vector_calc/calc_dir_vector.c	\
		   pixel_calculations/vector_calc/calc_vector.c		\
		   pixel_calculations/vector_calc/normalize_vector.c	\
		   pixel_calculations/vector_calc/reflect.c		\
		   pixel_calculations/vector_calc/cosinus.c		\
		   pixel_calculations/shapes/delta.c			\
		   pixel_calculations/shapes/cone.c			\
		   pixel_calculations/shapes/cylinder.c			\
		   pixel_calculations/shapes/sphere.c			\
		   pixel_calculations/shapes/plane.c			\
		   pixel_calculations/shapes/triangle.c			\
		   pixel_calculations/moves/rotate.c			\
		   pixel_calculations/moves/rotate2.c			\
		   pixel_calculations/moves/translate.c			\
		   pixel_calculations/moves/moves.c			\
		   pixel_calculations/shadow/find_shadow.c		\
		   use/product.c					\
		   $(addprefix window/,		$(WINDOW_SRC))		\
		   $(addprefix args/,		$(ARGS_SRC))		\
		   $(addprefix threads/,	$(THREAD_SRC))		\
		   $(addprefix process/,	$(PROC_SRC))		\
		   $(addprefix pixels/,		$(PIXELS_SRC))		\
		   $(addprefix parser/,		$(PARSER_SRC))		\
		   $(addprefix output_image/,	$(OUTPUT_SRC))		\
		   $(addprefix texture/,	$(TEXTURE_SRC))		\
		   $(addprefix events/,		$(EVENT_SRC))		\
		   $(addprefix post_render/,	$(POST_SRC))

PARSER_SRC	=  parser.c			\
		   readers_file.c		\
		   destruct_scene.c		\
		   print_scn.c

WINDOW_SRC	=  init.c			\
		   kill.c			\
		   print_text.c			\
		   update_window.c

PIXELS_SRC	=  blit.c			\
		   pixel.c

PROC_SRC	=  start.c			\
		   force_kill.c			\
		   display.c

THREAD_SRC	=  thread_init.c		\
		   data_construct.c		\
		   calculate.c			\
		   destruct_queue.c

ARGS_SRC	=  arg_error.c			\
		   get_args.c			\
		   print_args_status.c		\
		   set_fnc_tab.c		\
		   set_fnc_tab_from_ip.c	\
		   set_fnc_tab_from_if.c	\
		   valid_args.c			\
		   valid_cluster.c

OUTPUT_SRC	=  write_out_image.c

TEXTURE_SRC	=  main.c			\
		   stack.c

POST_SRC	=  back.c			\
		   shade_color.c		\
		   white.c			\
		   generate.c			\
		   flip.c			\
		   copy.c			\
		   invert.c			\
		   save.c			\
		   help.c

LIB_SOURCE	=  endian.c			\
		   explode.c			\
		   free_n.c			\
		   getnbr.c			\
		   gnl.c			\
		   istype.c			\
		   maths.c			\
		   memcpy.c			\
		   memset.c			\
		   nbrlen.c			\
		   print_error.c		\
		   push_tab.c			\
		   put_nbrs.c			\
		   put_strs.c			\
		   search_str.c			\
		   strcat.c			\
		   strchr.c			\
		   strcmp.c			\
		   strcpy.c			\
		   strlen.c			\
		   strpbrk.c			\
		   substr.c			\
		   tablen.c			\
		   xcalloc.c			\
		   xstrdup.c			\
		   $(addprefix printf/, $(PRINTF_SRC))

PRINTF_SRC	=  printf__calc.c		\
		   printf__constructor.c	\
		   printf__functions_base.c	\
		   printf__functions_chars.c	\
		   printf__functions_float.c	\
		   printf__functions_int.c	\
		   printf__functions_other.c	\
		   printf__getnbr.c		\
		   printf__getters.c		\
		   printf__lib.c		\
		   printf__parse.c		\
		   printf__printf.c		\
		   printf__vprintf.c

## 1
PROJ_FILES	=  $(addprefix src/, $(PROJ_SOURCE))

LIB_FILES	=  $(addprefix src/lib/, $(LIB_SOURCE))

LIB		=  $(LIB_FILES:.c=.o)

PROJ		=  $(PROJ_FILES:.c=.o)

VISUAL		= true

ifdef HEIGHT
CFLAGS		+= -DHEIGHT=$(HEIGHT)
endif
ifdef WIDTH
CFLAGS		+= -DWIDTH=$(WIDTH)
endif

ifeq ($(RELEASE), false)
CFLAGS		+= -g -ggdb
CFLAGS		+= -D__DEBUG__ -D__INTERFACE__
PARSER_SRC	+= interface.c
endif
ifeq ($(RELEASE), opti)
CFLAGS		+= -O2
endif
ifeq ($(BONUS), yes)
CFLAGS		+= -D__BONUS__ -D__INTERFACE__
PARSER_SRC	+= interface.c
endif

ifeq ($(VISUAL), true)
$(NAME): $(LIB) $(PROJ)
	@echo -ne "\033[93mLinkage de\033[35m" $(LIBNAME) "\033[m"
	@tput hpa $$(($$(tput cols) - 18));
	@$(AR) $(LIBNAME) $(LIB) &&				\
	echo -ne "-=[\033[1;32m  COMPLETE  \033[m]=-\n\n" ||	\
	echo -ne "-=[\033[1;31m FAIL \033[m]=-\n"
	@make --no-print-directory -C src/lib/list
	@echo -ne "\n"
	@make --no-print-directory -C src/lib/bmp
	@echo -ne "\n"
	@echo -ne "\033[93mLinkage des fichiers\033[m"
	@tput hpa $$(($$(tput cols) - 17));
	@$(CC) -o $(NAME) $(LIB) $(PROJ) $(LDFLAGS) &&	\
	echo -e "-=[\033[1;32m  SUCCESS  \033[m]=-" ||	\
	echo -e "-=[\033[1;31m FAILED \033[m]=-"
else
$(NAME): $(LIB) $(PROJ)
	$(AR) $(LIBNAME) $(LIB)
	make --no-print-directory -C src/lib/list
	make --no-print-directory -C src/lib/bmp
	$(CC) -o $(NAME) $(LIB) $(PROJ) $(LDFLAGS)
endif

all: $(NAME)

clean:
	make clean -C src/lib/list
	make clean -C src/lib/bmp
	$(RM) $(LIB) $(PROJ)
	$(RM) $(LIBNAME)

fclean: clean
	make fclean -C src/lib/list
	make fclean -C src/lib/bmp
	$(RM) $(NAME)

ifeq ($(VISUAL), true)
.c.o:
	@echo -ne "\033[33mCompilation de\033[36m" $(notdir $<) "\033[m";
	@tput hpa $$(($$(tput cols) - 12));
	@$(CC) -c -o $@ $< $(CFLAGS) &&					\
	echo -e "-=[\033[1;32m  OK  \033[m]=-" ||			\
	echo -e "-=[\033[1;31m FAIL \033[m]=-"
endif

re: fclean all

.PHONY: all clean fclean re
