/*
** printf__functions_chars.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "m_printf.h"

void		printf__gest_c(va_list			ap,
			       UNUSED t_printf_param	param,
			       t_printf_out		*out)
{
  printf__print(va_arg(ap, int), out);
}

void		printf__gest_s(va_list		ap,
			       t_printf_param	param,
			       t_printf_out	*out)
{
  uint32_t	nbr;
  char		*wr;

  wr = va_arg(ap, char *);
  nbr = my_strlen(wr);
  param.prec -= nbr;
  if (param.decal == false || param.decal == unknown)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(' ', out);
    }
  printf__putstr(wr, -1, out);
  if (param.decal == true)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(' ', out);
    }
}

void		printf__gest_S(va_list		ap,
			       t_printf_param	param,
			       t_printf_out	*out)
{
  uint32_t	nbr;
  char		*wr;

  wr = va_arg(ap, char *);
  nbr = my_strlen(wr);
  param.prec -= nbr;
  if (param.decal == false || param.decal == unknown)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(' ', out);
    }
  printf__sputstr(wr, -1, out);
  if (param.decal == true)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(' ', out);
    }
}
