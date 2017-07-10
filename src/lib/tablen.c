/*
** tablen.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

/*
**	tablen : Mesure la longueur d'un tableau
**
**	Arguments :
**		- tab  : La chaîne à mesurer
**
**	Valeur de retour :
**		- La longueur du tableau
**
**	Alias : Pas d'allias
*/

int	tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i])
    i++;
  return (i);
}
