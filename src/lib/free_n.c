/*
** free_n.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include <stdlib.h>

/*
**	free_2 : Libère le tableau à double entrée "tab"
**
**	Arguments :
**		- tab : Le tableau à libérer
**
**	Valeur de retour : (void)
**
**	Alias : Pas d'allias
*/

void	free_2(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
  tab = NULL;
  return ;
}
