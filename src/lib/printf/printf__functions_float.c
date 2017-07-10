/*
** printf__functions_float.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Sun Apr 23 14:39:09 2017 Thomas Lombard
*/

#include "m_printf.h"

static inline int	  m_pow(int nb, int power)
{
  nb = ((power < 0) ? 0 : \
	(power > 1) ? nb * m_pow(nb, power - 1) : \
	(power == 1) ? nb : 1);
  return (nb);
}
static void	printf__putdouble(double		nbr,
				  t_printf_param	param,
				  t_printf_out		*out)
{
  while (param.prec_float > 0)
    {
      nbr *= 10;
      printf__putnbr((long)nbr, out);
      nbr -= (long)nbr;
      param.prec_float -= 1;
    }
}

void		printf__gest_f(va_list		ap,
			       t_printf_param	param,
			       t_printf_out	*out)
{
  double	nbr;

  nbr = va_arg(ap, double);
  param.prec -= param.prec_float;
  param.prec -= printf__nbrlen((long)nbr);
  if (nbr < 0)
    param.prec--;
  if (param.decal == false || param.decal == unknown)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(((param.o_aff) ? '0' : ' '), out);
    }
  printf__putnbr((long)nbr, out);
  if (nbr < 0)
    nbr *= -1.0;
  if (param.prec_float > 0)
    {
      printf__print('.', out);
      nbr -= (long)nbr;
      nbr *= m_pow(10, printf__nbrlen((long)nbr));
      printf__putdouble(nbr, param, out);
    }
}
