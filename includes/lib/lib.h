/*
** lib.h for test in /home/lombar_e/lib
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Dec 13 17:57:35 2016 Thomas Lombard
** Last update Fri May 26 15:26:18 2017 Theodore Marestin
*/

#ifndef LIB_FUNCS
# define LIB_FUNCS

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "lib/defines.h"
# include "lib/structs.h"

/*
**	    --------------------
**	----      endian.c      ----
**	    --------------------
*/
uint8_t		swap_endian_8(uint8_t nb);
uint16_t	swap_endian_16(uint16_t nb);
uint32_t	swap_endian_32(uint32_t nb);
uint64_t	swap_endian_64(uint64_t nb);
/*
**	    --------------------
**	----      explode.c      ----
**	    --------------------
*/
char	**explode(char *str, int8_t split);
char	*epur_str(char *str);
int	match_next(char *str, char c, int i);
/*
**	    --------------------
**	----	  free_n.c	----
**	    --------------------
*/
void	free_2(char **a);
/*
**	    --------------------
**	----	  getnbr.c	----
**	    --------------------
*/
int	my_getnbr_base(char *nbr, char *base);
int	my_getnbr(char *n);
/*
**	    --------------------
**	----	   gnl.c	----
**	    --------------------
*/
char	*get_next_line(const int fd);
/*
**	    --------------------
**	----	  istype.c	----
**	    --------------------
*/
int	istype(int c, int flag);
int	stristype(char *str, int flag);
/*
**	    --------------------
**	----	   maths.c	----
**	    --------------------
*/
int	my_fact(int nb);
int	my_pow(int nb, int power);
int	my_sqrt(int nb);
int	nbrlen(long nbr);
/*
**	    --------------------
**	----	  memset.c	----
**	    --------------------
*/
void	my_memset(void *ptr, char reset, int64_t size);
void	*my_memcpy(void *dest, const void *src, size_t n);
/*
**	    --------------------
**	----	  nbrlen.c	----
**	    --------------------
*/
int	nbrlen(long nbr);
/*
**	    --------------------
**	----	print_error.c	----
**	    --------------------
*/
void	*print_error(const char *error, ...);
/*
**	    --------------------
**	----	 push_tab.c	----
**	    --------------------
*/
char	**push_tab(char **tab, char *line);
/*
**	    --------------------
**	----	 put_nbrs.c	----
**	    --------------------
*/
void	my_putnbr_base(int nbr, const char *base);
void	my_putdouble(double val, int prec);
void	my_putfloat(float val, int prec);
/*
**	    --------------------
**	----	 put_strs.c	----
**	    --------------------
*/
ssize_t	my_putstr(const char *str);
ssize_t	my_putchar(const char c);
ssize_t	my_puterror(const char *err);
/*
**	    --------------------
**	----	search_str.c	----
**	    --------------------
*/
int	find_words(char *str, char split);
/*
**	    --------------------
**	----	  strcat.c	----
**	    --------------------
*/
char	*my_strcat(char *str, const char *cat);
char	*my_strncat(char *str, const char *cat, size_t n);
char	*concat(char *str, ...);
/*
**	    --------------------
**	----	  strchr.c	----
**	    --------------------
*/
char	*my_strchr(const char *str, int c);
char	*my_strrchr(const char *str, int c);
/*
**	    --------------------
**	----	  strcmp.c	----
**	    --------------------
*/
int	my_strcmp(const char *s1, const char *s2);
int	my_strncmp(const char *s1, const char *s2, int n);
/*
**	    --------------------
**	----	  strcpy.c	----
**	    --------------------
*/
void	my_strcpy(char *dest, const char *src);
void	my_strncpy(char *dest, const char *src, int n);
/*
**	    --------------------
**	----	  strlen.c	----
**	    --------------------
*/
int	my_strlen(const char *str);
/*
**	    --------------------
**	----	  strpbrk.c	----
**	    --------------------
*/
char	*my_strnpbrk(const char *s1, const char *s2, int n);
char	*my_strpbrk(const char *s1, const char *s2);
/*
**	    --------------------
**	----	  strchr.c	----
**	    --------------------
*/
char	*my_strchr(const char *str, int c);
char	*my_strrchr(const char *str, int c);
/*
**	    --------------------
**	----	  substr.c	----
**	    --------------------
*/
char	*substr(const char *str, int start, int end);
/*
**	    --------------------
**	----	  tablen.c	----
**	    --------------------
*/
int	tablen(char **tab);
/*
**	    --------------------
**	----	  xcalloc.c	----
**	    --------------------
*/
void	*xcalloc(uint64_t nmemb, uint64_t nsize);
/*
**	    --------------------
**	----	  xstrdup.c	----
**	    --------------------
*/
char 	*xstrdup(const char *str);
char	*xstrndup(const char *str, int len);

/*
**	            ********
**	--------------------------------
**	 |      LIB CHAINED LIST      |
**	--------------------------------
**	            ********
*/
void	*list_pusha(void *, void *, size_t);
void	*list_push(void *, void *);
void	*list_get_first(void *);
void	*list_get_last(void *);
void	*list_get_selector(void *, void *, int (*)(void *, void *));
void	*list_detach_selector(void *, void *, int (*)(void *, void *));
void	*list_detach_last(void *l);
void	*list_detach_first(void *l);
void	*list_detach(void *n);
size_t	list_length(void *);
void	*list_remove(void *, void *);
void	*list_remove_method(void *, void *, void (*)(void *));
void	list_destruct(void *);
void	list_destruct_method(void *, void (*)(void *));
/*
**	            ********
**	--------------------------------
**	 |       PRINTF_VERSION       |
**	--------------------------------
**	            ********
*/
int	m_printf(const char *format, ...);
int	m_fprintf(FILE *fs, const char *format, ...);
int	m_dprintf(int fd, const char *format, ...);
int	m_sprintf(char *str, const char *format, ...);
int	m_snprintf(char *str, size_t size, const char *format, ...);
int	m_vprintf(const char *format, va_list ap);
int	m_vfprintf(FILE *fs, const char *format, va_list ap);
int	m_vdprintf(int fd, const char *format, va_list ap);
int	m_vsprintf(char *str, const char *format, va_list ap);
int	m_vsnprintf(char *str, size_t size, const char *format, va_list ap);

/*
**	            ********
**	--------------------------------
**	 |        ALLIAS LIST         |
**	--------------------------------
**	            ********
*/
# define my_str_to_wordtab	explode
# define m_getx(nbr)		my_getnbr_base(nbr, "0123456789abcdef")
# define m_getX(nbr)		my_getnbr_base(nbr, "0123456789ABCDEF")
# define m_geto(nbr)		my_getnbr_base(nbr, "01234567")
# define m_getb(nbr)		my_getnbr_base(nbr, "01")
# define m_getn(val)		my_getnbr(val)
# define gnl(fd)		get_next_line(fd)
# ifndef isalpha
#  define isalpha(val)		istype(val, I_ALPHA)
#  define isdigit(val)		istype(val, I_DIGIT)
#  define islower(val)		istype(val, I_LOWER)
#  define isupper(val)		istype(val, I_UPPER)
#  define isalnum(val)		istype(val, I_ALNUM)
#  define isprint(val)		istype(val, I_PRINT)
# endif /* ! isalpha */
# define strisalpha(val)	stristype(val, I_ALPHA)
# define strisdigit(val)	stristype(val, I_DIGIT)
# define strislower(val)	stristype(val, I_LOWER)
# define strisupper(val)	stristype(val, I_UPPER)
# define strisalnum(val)	stristype(val, I_ALNUM)
# define strisprint(val)	stristype(val, I_PRINT)
# define m_pow(val)		my_pow(val)
# define m_fact(val)		my_fact(val)
# define m_sqrt(val)		my_sqrt(val)
# define m_abs(val)		my_abs(val)
# define m_putx(nbr)		my_putnbr_base(nbr, "0123456789abcdef")
# define m_putX(nbr)		my_putnbr_base(nbr, "0123456789ABCDEF")
# define m_putn(nbr)		my_putnbr_base(nbr, "0123456789")
# define m_puto(nbr)		my_putnbr_base(nbr, "01234567")
# define m_putb(nbr)		my_putnbr_base(nbr, "01")
# define m_putd(nbr)		my_putdouble(nbr, 6)
# define m_putf(nbr)		my_putfloat(nbr, 6)
# define m_puts(str)		my_putstr(str)
# define m_putc(c)		my_putchar(c)
# define m_pute(err)		my_puterror(err)
# define m_strl(str)		my_strlen(str)

#endif
