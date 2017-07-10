/*
** printf__calc.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "m_printf.h"

int			printf__calc(UNUSED const char		*format,
				     UNUSED va_list		ap,
				     UNUSED t_printf_out	*out)
{
  char			*tmp;

  while (format && *format)
    {
      if (*format == '%')
	{
	  tmp = (char *)format + 1;
	  if (printf__parse(&tmp, ap, out))
	    format = tmp;
	  else
	    printf__print(*format, out);
	}
      else
	printf__print(*format, out);
      format++;
    }
  return (out->wrote);
}
