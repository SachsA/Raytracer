/*
** printf__lib.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Sun May 28 11:53:39 2017 Thomas Lombard
*/

#include <limits.h>
#include "m_printf.h"

void	printf__putstr(const char	*str,
		       int		len,
		       t_printf_out	*out)
{
  char	*s;

  s = (char*)str;
  if (!s)
    printf__putstr("(nil)", len, out);
  else
    {
      len = (len == -1) ? my_strlen(str) : len;
      while (len)
	{
	  printf__print(*str, out);
	  ++str;
	  --len;
	}
    }
}

void	printf__sputstr(char		*str,
			int		len,
			t_printf_out	*out)
{
  len = (len == -1) ? my_strlen(str) : len;
  if (!str)
    printf__putstr("(nil)", len, out);
  else
    {
      while (len)
	{
	  if (*str < 32 || *str >= 127)
	    {
	      printf__print('\\', out);
	      if (*str < 8)
		printf__print('0', out);
	      if (*str < 64)
		printf__print('0', out);
	      printf__putnbr_base((int)*str, out, "01234567");
	    }
	  else
	    printf__print(*str, out);
	  ++str;
	  --len;
	}
    }
}

void	printf__print(const char	c,
		      t_printf_out	*out)
{
  if (out->print_len <= 0)
    return ;
  if ((out->out == e_write || out->out == e_fd) && write(out->fd, &c, 1));
  else if (out->out == e_chain)
    out->chain[out->wrote] = c;
  ++out->wrote;
  --out->print_len;
}

void	printf__putnbr(long		nbr,
		       t_printf_out	*out)
{
  const char	*min = "-9223372036854775808";

  if (nbr == LONG_MIN)
    {
      printf__putstr(min, -1, out);
      return ;
    }
  if (nbr < 0)
    {
      nbr *= -1;
      printf__print('-', out);
    }
  if (nbr >= 10)
    printf__putnbr(nbr / 10, out);
  printf__print((nbr % 10) + '0', out);
}

void	printf__putnbr_base(unsigned long int	val,
			    t_printf_out	*out,
			    const char		*base)
{
  unsigned int		strl;

  strl = 0;
  while (base[strl])
    strl++;
  if (val >= strl)
    printf__putnbr_base(val / strl, out, base);
  printf__print(base[val % strl], out);
}
