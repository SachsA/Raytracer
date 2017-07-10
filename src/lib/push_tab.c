/*
** push_tab.c for raytracer2 in /raytracer2/src/lib
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed Apr 05 18:51:02 2017 Thomas Lombard
** Last update Wed Apr 05 18:53:20 2017 Thomas Lombard
*/

#include "lib/lib.h"

/*
**	push_tab : Ajoute une case à "tab". Crée le tableau si "tab" est NULL
**
**	Arguments :
**		- tab    : Le tableau d'entrée
**		- line   : L'entrée à ajouter
**
**	Valeur de retour :
**		- Le nouveau tableau
**
**	Alias : Pas d'allias
*/

char		**push_tab(char **tab, char *line)
{
  char		**ret;
  int		i;

  i = tablen(tab) + 2;
  if (!(ret = xcalloc(i, sizeof(char *))))
    return (NULL);
  i = -1;
  while (tab && tab[++i])
    ret[i] = tab[i];
  i = (i == -1) ? 0 : i;
  if (!(ret[i] = xstrdup(line)))
    return (NULL);
  free(tab);
  return (ret);
}
