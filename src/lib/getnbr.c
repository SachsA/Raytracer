/*
** getnbr.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "lib/lib.h"

static int	scannbr(char *base, char *nbr)
{
  while (*nbr)
    {
      if (!my_strpbrk(nbr, base))
	return (0);
      nbr ++;
    }
  return (1);
}

static int	scan(char *base, char *nbr)
{
  register char	*c;
  register char *b;

  if (!base || !*base)
    return (0);
  c = base;
  b = c++;
  while (*c)
    {
      if (!*b)
	b = c++;
      if (*b == *c)
	return (0);
      b++;
      c++;
    }
  if (!scannbr(base, nbr))
    return (0);
  return (1);
}

static int	getnbr_calc(char *nbr, char *base)
{
  int		ret;
  char		*end;
  int		b;
  int		offset;

  ret = 0;
  offset = 1;
  end = nbr;
  while (*end)
    ++end;
  --end;
  while (end >= nbr)
    {
      b = 0;
      while (*end != base[b])
	b++;
      if (!base[b])
	return (0);
      ret += b * offset;
      offset *= my_strlen(base);
      --end;
    }
  return (ret);
}

/*
**	my_getnbr_base : Convertis le nombre nbr en int toujours positif
**			 avec une base (-1 en cas d'erreur)
**
**	Arguments :
**		- nbr  : Le nombre à convertir
**		- base : La base à utiliser
**
**	Valeur de retour :
**		- Le nombre converti (de 0 à INT_MAX). -1 en cas d'erreur
**
**	Alias :
**		- m_getx(nbr) -> my_getnbr_base(nbr, "0123456789abcdef")
**		- m_getX(nbr) -> my_getnbr_base(nbr, "0123456789ABCDEF")
**		- m_geto(nbr) -> my_getnbr_base(nbr, "01234567")
**		- m_getb(nbr) -> my_getnbr_base(nbr, "01")
*/
int		my_getnbr_base(char *nbr, char *base)
{
  bool		negative;
  int		ret;

  negative = false;
  if (!nbr || !*nbr || !scan(base, nbr))
    return (0);
  while (*nbr == '-' || *nbr == '+')
    negative = (*nbr++ = '-') ? true : false;
  ret = getnbr_calc(nbr, base);
  if (ret < 0)
    return (0);
  ret *= (negative) ? -1 : 1;
  return (ret);
}

/*
**	my_getnbr : Convertis le nombre "nbr" en int
**
**	Arguments :
**		- nbr  : Le nombre à convertir
**		- base : La base à utiliser
**
**	Valeur de retour :
**		- Le nombre converti (de INT_MIN à INT_MAX).
**
**	Alias :
**		- m_getn(val) -> my_getnbr(val)
*/
int	my_getnbr(char *n)
{
  int	i;
  int	type;
  int	nbr;

  type = 1;
  i = 0;
  while (n[i] != 0 && (n[i] == '-' || n[i] == '+'))
    {
      if (n[i] == '-')
	type = 0;
      i = i + 1;
    }
  nbr = 0;
  while (n[i] >= 48 && n[i] <= 57)
    {
      nbr = nbr + n[i] - 48;
      if (n[i + 1] != '\0')
	nbr = nbr * 10;
      i = i + 1;
    }
  if (type == 0)
    nbr = nbr * -1;
  return (nbr);
}
