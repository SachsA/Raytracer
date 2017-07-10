/*
** nbrlen.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

/*
**	nbrlen : Donne la longueur d'un nombre s'il devait être affiché
**
**	Arguments :
**		- nb    : Le nombre à mesurer
**
**	Valeur de retour :
**		- La longueur mesurée
**
**	Alias : Pas d'allias
*/

int	nbrlen(long nbr)
{
  int	ret;

  ret = 0;
  while (nbr > 0 && nbr / 10 > 10)
    {
      nbr /= 10;
      ++ret;
    }
  return (ret);
}
