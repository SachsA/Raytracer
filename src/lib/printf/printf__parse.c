/*
** printf__parse.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "m_printf.h"

static bool	printf__get_format(char			**format,
				   t_printf_param	*p)
{
  if (**format && **format == '#' && (*format)++)
    p->modifier = true;
  if (**format && (**format == '-' || **format == '+') && (*format)++)
    p->decal = (*((*format) - 1) == '-') ? true : false;
  return (true);
}

static bool	printf__get_prec(char		**format,
				 t_printf_param	*p)
{
  int	check;

  if (**format == '0')
    {
      ++(*format);
      p->o_aff = true;
    }
  check = 0;
  while ((*format)[check] && isdigit((*format)[check]))
    ++check;
  if (check < 10)
    p->prec = printf__getnbr(format);
  if (**format == '.')
    {
      ++(*format);
      check = 0;
      while ((*format)[check] && isdigit((*format)[check]))
	++check;
      if (check < 10)
	p->prec_float = printf__getnbr(format);
    }
  return (true);
}

static bool	printf__get_conversion(char		**format,
				       t_printf_param	*p)
{
  if (**format == 'l')
    {
      ++(*format);
      p->conv = PRINTF_CONV_L;
    }
  else if (**format == 'h')
    {
      ++(*format);
      if (**format && **format == 'h')
	{
	  p->conv = PRINTF_CONV_HH;
	  ++(*format);
	}
      else
	p->conv = PRINTF_CONV_H;
    }
  return (true);
}

bool			printf__parse(char		**format,
				      va_list		ap,
				      t_printf_out	*out)
{
  static t_printf_func	funcs[PRINTF_SUPPORT_LEN + 1] = {{0, 0}};
  t_printf_param	p;
  int			i;

  i = 0;
  my_memset(&p, 0, sizeof(p));
  p.prec_float = 6;
  p.decal = unknown;
  if (funcs[0].flag == 0)
    printf__construct(funcs);
  printf__get_format(format, &p);
  printf__get_prec(format, &p);
  printf__get_conversion(format, &p);
  while (funcs[i].flag != 0 && funcs[i].flag != **format)
    ++i;
  if (funcs[i].flag != 0)
    funcs[i].ptr(ap, p, out);
  else
    return (false);
  return (true);
}
