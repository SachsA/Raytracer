/*
** printf__functions_base.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "m_printf.h"

int	printf__nbrlen_base(unsigned long	nbr,
			    unsigned int	base)
{
  int		ret;

  ret = 0;
  if (nbr >= base)
    ret += printf__nbrlen_base(nbr / base, base);
  ret ++;
  return (ret);
}

void	printf__gest_b(va_list		ap,
		       t_printf_param	param,
		       t_printf_out	*out)
{
  unsigned long	nbr;

  nbr = printf__get_uint64_t(ap, param);
  param.prec -= printf__nbrlen_base(nbr, 2);
  if (param.decal == false || param.decal == unknown)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(((param.o_aff) ? '0' : ' '), out);
    }
  printf__putnbr_base(nbr, out, "01");
  if (param.decal == true)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(' ', out);
    }
}

void	printf__gest_o(va_list		ap,
		       t_printf_param	param,
		       t_printf_out	*out)
{
  unsigned long	nbr;

  nbr = printf__get_uint64_t(ap, param);
  if (param.modifier)
    --param.prec;
  param.prec -= printf__nbrlen_base(nbr, 2);
  if (param.decal == false || param.decal == unknown)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(((param.o_aff) ? '0' : ' '), out);
    }
  if (param.modifier)
    printf__print('0', out);
  printf__putnbr_base(nbr, out, "01234567");
  if (param.decal == true)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(' ', out);
    }
}

void	printf__gest_x(va_list		ap,
		       t_printf_param	param,
		       t_printf_out	*out)
{
  unsigned long	nbr;

  nbr = printf__get_uint64_t(ap, param);
  if (param.modifier)
    param.prec -= 2;
  param.prec -= printf__nbrlen_base(nbr, 16);
  if (param.decal == false || param.decal == unknown)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(((param.o_aff) ? '0' : ' '), out);
    }
  if (param.modifier)
    printf__putstr("0x", -1, out);
  printf__putnbr_base(nbr, out, "0123456789abcdef");
  if (param.decal == true)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(' ', out);
    }
}

void	printf__gest_X(va_list		ap,
		       t_printf_param	param,
		       t_printf_out	*out)
{
  unsigned long	nbr;

  nbr = printf__get_uint64_t(ap, param);
  if (param.modifier)
    param.prec -= 2;
  param.prec -= printf__nbrlen_base(nbr, 16);
  if (param.decal == false || param.decal == unknown)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(((param.o_aff) ? '0' : ' '), out);
    }
  if (param.modifier)
    printf__putstr("0X", -1, out);
  printf__putnbr_base(nbr, out, "0123456789ABCDEF");
  if (param.decal == true)
    {
      while (param.prec > 0 && param.prec--)
	printf__print(' ', out);
    }
}
