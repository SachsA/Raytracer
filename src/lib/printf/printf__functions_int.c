/*
** printf__functions_int.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Sun Apr 23 11:49:06 2017 Thomas Lombard
*/

#include "m_printf.h"

static void	printf__before_print_di(long		nbr,
					t_printf_param	*param,
					t_printf_out	*out)
{
  --param->prec;
  if (nbr > 0 && param->o_aff && param->decal != unknown)
    printf__print('+', out);
  while (param->prec > 0 && param->prec--)
    printf__print(((param->o_aff) ? '0' : ' '), out);
  if (nbr > 0 && !param->o_aff && param->decal != unknown)
    printf__print('+', out);
}

void	printf__gest_di(va_list		ap,
			t_printf_param	param,
			t_printf_out	*out)
{
  long	nbr;

  nbr = printf__get_int64_t(ap, param);
  param.prec -= printf__nbrlen(nbr);
  if (param.decal == false || param.decal == unknown)
    printf__before_print_di(nbr, &param, out);
  printf__putnbr(nbr, out);
  if (param.decal == true)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(' ', out);
    }
}

void		printf__gest_u(va_list		ap,
			t_printf_param	param,
			t_printf_out	*out)
{
  unsigned long	nbr;

  nbr = printf__get_uint64_t(ap, param);
  param.prec -= printf__nbrlen(nbr);
  if (param.decal == false || param.decal == unknown)
    while (param.prec > 0 && param.prec--)
      printf__print(((param.o_aff) ? '0' : ' '), out);
  printf__putnbr_base(nbr, out, "0123456789");
  if (param.decal == true)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(' ', out);
    }
}
