/*
** xstrdup.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed Apr 05 18:56:11 2017 Thomas Lombard
*/

#include "lib/lib.h"

/*
**	my_strdup : man strdup
**
**	Arguments :
**		- str  : La chaîne à dupliquer
**
**	Valeur de retour :
**		- La chaîne dupliquée
**
**	Alias : Pas d'allias
*/

char 	*xstrdup(const char *str)
{
  char 	*ret;
  int 	i;
  int	l;

  i = 0;
  l = my_strlen(str);
  if (!(ret = xcalloc(l + 1, 1)))
    return (NULL);
  while (i < l && *str)
    ret[i++] = *str++;
  return (ret);
}
