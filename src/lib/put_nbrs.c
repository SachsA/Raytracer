/*
** put_nbrs.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "lib/lib.h"

/*
**	my_putnbr_base : Affiche le nombre "nbr" avec une base
**
**	Arguments :
**		- nbr  : Le nombre à afficher
**		- base : La base à utiliser
**
**	Valeur de retour :
**		- (void)
**
**	Alias :
**		- m_putx(nbr) -> my_putnbr_base(nbr, "0123456789abcdef")
**		- m_putX(nbr) -> my_putnbr_base(nbr, "0123456789ABCDEF")
**		- m_putn(nbr) -> my_putnbr_base(nbr, "0123456789")
**		- m_puto(nbr) -> my_putnbr_base(nbr, "01234567")
**		- m_putb(nbr) -> my_putnbr_base(nbr, "01")
*/

void	my_putnbr_base(int nbr, const char *base)
{
  int	strl;

  strl = my_strlen(base);
  if (nbr < 0)
    {
      nbr = nbr * -1;
      my_putchar('-');
    }
  if (nbr >= strl)
    my_putnbr_base(nbr / strl, base);
  my_putchar(base[nbr % strl]);
}

/*
**	my_putdouble : Affiche le double "val" avec une précision
**
**	Arguments :
**		- val  : Le double à afficher
**		- prec : La précision à utiliser
**
**	Valeur de retour :
**		- (void)
**
**	Alias :
**		- m_putd(nbr) -> my_putdouble(nbr, 6)
*/

void	my_putdouble(double val, int prec)
{
  int	fact;

  if (val < 0)
    {
      my_putchar('-');
      val *= -1;
    }
  my_putnbr_base((int)val, "0123456789");
  val -= (int)val;
  my_putchar('.');
  fact = my_pow(10, prec);
  val *= fact;
  my_putnbr_base((int)val, "0123456789");
}

/*
**	my_putfloat : Affiche le float "val" avec une précision
**
**	Arguments :
**		- val  : Le float à afficher
**		- prec : La précision à utiliser
**
**	Valeur de retour :
**		- (void)
**
**	Alias :
**		- m_putf(nbr) -> my_putfloat(nbr, 6)
*/

void	my_putfloat(float val, int prec)
{
  int	fact;

  if (val < 0)
    {
      my_putchar('-');
      val *= -1;
    }
  my_putnbr_base((int)val, "0123456789");
  val -= (int)val;
  my_putchar('.');
  fact = my_pow(10, prec);
  val *= fact;
  my_putnbr_base((int)val, "0123456789");
}
