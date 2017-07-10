/*
** printf__getnbr.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "m_printf.h"

int	printf__getnbr(char	**format)
{
  int	nb;
  int	save;

  nb = 0;
  save = 0;
  while (isdigit(**format))
    {
      nb += **format - '0';
      if (isdigit(*(*format + 1)))
	nb *= 10;
      if (nb < save)
	return (save);
      ++(*format);
    }
  return (nb);
}

int	printf__nbrlen(long nbr)
{
  int		ret;

  ret = 0;
  nbr = my_abs(nbr);
  if (nbr == 0)
    return (0);
  while (nbr > 0 && nbr / 10)
    {
      nbr /= 10;
      ret++;
    }
  return (ret + 1);
}
