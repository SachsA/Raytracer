/*
** m_printf.h for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#ifndef M_PRINTF_H_
# define M_PRINTF_H_

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>

# define unknown 2
typedef int trilean;

# define I_DIGIT	1
# define I_LOWER	I_DIGIT << 1
# define I_UPPER	I_LOWER << 1
# define I_PRINT	I_UPPER << 1
# define I_ALPHA	I_LOWER | I_UPPER
# define I_ALNUM	I_LOWER | I_UPPER | I_DIGIT
# define UNUSED __attribute__((unused))
# define isdigit(val)	istype(val, I_DIGIT)

# define PRINTF_SUPPORT "uidboxXfFcsS%np"
# define PRINTF_SUPPORT_LEN 15
# define PRINTF_CONV_L	1
# define PRINTF_CONV_LL	PRINTF_CONV_L << 1
# define PRINTF_CONV_H	PRINTF_CONV_LL << 1
# define PRINTF_CONV_HH	PRINTF_CONV_H << 1

enum		e_output
{
  e_write,
  e_chain,
  e_fd,
  e_fs
};

typedef struct	s_printf_out
{
  size_t	wrote;
  size_t	print_len;
  char		*chain;
  enum e_output	out;
  int		fd;
  FILE		*fs;
}		t_printf_out;

typedef struct	s_printf_param
{
  int		conv;
  int		prec;
  int		prec_float;
  bool		o_aff;
  bool		modifier;
  trilean	decal;
}		t_printf_param;

typedef struct	s_printf_func
{
  char		flag;
  void		(*ptr)(va_list, t_printf_param, t_printf_out*);
}		t_printf_func;

/*
**	--------------------------------
**	 |     PRINTF_CONSTRUCTOR     |
**	--------------------------------
*/
void	printf__construct(t_printf_func	*func);

/*
**	--------------------------------
**	 |        PRINTF_PARSER       |
**	--------------------------------
*/
bool	printf__parse(char **format, va_list ap, t_printf_out *out);
int	printf__calc(const char *format, va_list ap, t_printf_out *out);

/*
**	--------------------------------
**	 |         PRINTF_LIB         |
**	--------------------------------
*/
int		printf__nbrlen(long nbr);
void		printf__putstr(const char *str, int len, t_printf_out *out);
void		printf__sputstr(char *str, int len, t_printf_out *out);
void		printf__print(const char c, t_printf_out *out);
int		printf__getnbr(char **format);
void		printf__putnbr(long nbr, t_printf_out *out);
long		printf__get_int64_t(va_list ap, t_printf_param param);
unsigned long	printf__get_uint64_t(va_list ap, t_printf_param param);
int		printf__nbrlen_base(unsigned long nbr, unsigned int base);
void		printf__putnbr_base(unsigned long int	val,
				    t_printf_out	*out,
				    const char		*base);

/*
**	--------------------------------
**	 |        PRINTF_FLAGS        |
**	--------------------------------
*/
void	printf__gest_di(va_list ap, t_printf_param param, t_printf_out *out);
void	printf__gest_u(va_list ap, t_printf_param param, t_printf_out *out);
void	printf__gest_b(va_list ap, t_printf_param param, t_printf_out *out);
void	printf__gest_o(va_list ap, t_printf_param param, t_printf_out *out);
void	printf__gest_x(va_list ap, t_printf_param param, t_printf_out *out);
void	printf__gest_X(va_list ap, t_printf_param param, t_printf_out *out);
void	printf__gest_f(va_list ap, t_printf_param param, t_printf_out *out);
void	printf__gest_f(va_list ap, t_printf_param param, t_printf_out *out);
void	printf__gest_c(va_list ap, t_printf_param param, t_printf_out *out);
void	printf__gest_s(va_list ap, t_printf_param param, t_printf_out *out);
void	printf__gest_S(va_list ap, t_printf_param param, t_printf_out *out);
void	printf__gest_mod(va_list ap, t_printf_param param, t_printf_out *out);
void	printf__gest_n(va_list ap, t_printf_param param, t_printf_out *out);
void	printf__gest_p(va_list ap, t_printf_param param, t_printf_out *out);

/*
**	--------------------------------
**	 |       PRINTF_VERSION       |
**	--------------------------------
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
**	--------------------------------
**	 |       BASIC_LIBRARY        |
**	--------------------------------
*/
int	my_abs(int nbr);
int	my_strlen(const char *str);
int	istype(int c, int flag);
void	my_memset(void *ptr, char reset, int64_t size);

#endif /* ! HEADER_H_ */
