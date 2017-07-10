/*
** maths.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

/*
**	my_pow : Identique à pow de la libmath
**
**	Arguments :
**		- nb    : Le nombre à multiplier
**		- power : La puissance à appliquer
**
**	Valeur de retour :
**		- Le nombre calculé
**
**	Alias :
**		- m_pow(val) -> my_pow(val)
*/

int	my_pow(int nb, int power)
{
  nb = ((power < 0) ? 0 : \
	(power > 1) ? nb * my_pow(nb, power - 1) : \
	(power == 1) ? nb : 1);
  return (nb);
}

/*
**	my_fact : Calcule la factorielle de nb
**
**	Arguments :
**		- nb    : Le nombre à calculer
**
**	Valeur de retour :
**		- Le nombre calculé
**
**	Alias :
**		- m_fact(val) -> my_fact(val)
*/

int	my_fact(int nb)
{
  if (nb >= 13 || nb <= 0)
    return (0);
  return ((nb > 1) ? nb * my_fact(nb - 1) : 1);
}

/*
**	my_sqrt : Calcule la racine carée de nb
**
**	Arguments :
**		- nb    : Le nombre à chercher
**
**	Valeur de retour :
**		- Le nombre trouvé, 0 en cas d'erreur ou d'absence de résultat
**
**	Alias :
**		- m_sqrt(val) -> my_sqrt(val)
*/

int		my_sqrt(int nb)
{
  const int	max = 46340;
  int		ret;

  ret = 0;
  while (ret < max && ret * ret < nb)
    ++ret;
  return ((ret * ret == nb) ? ret : 0);
}

/*
**	my_abs : Donne la valeur absolue de nb
**
**	Arguments :
**		- val    : Le nombre à calculer
**
**	Valeur de retour :
**		- Le nombre calculé
**
**	Alias :
**		- m_abs(val) -> my_abs(val)
*/

extern inline int	my_abs(int val)
{
  if (val < 0)
    return (val * -1);
  return (val);
}
