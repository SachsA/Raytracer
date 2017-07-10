/*
** measurement.c for chained in /src/lib/list
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Mon Apr 24 14:08:22 2017 Thomas Lombard
** Last update Sun May 21 14:50:43 2017 Thomas Lombard
*/

#include "list.h"

/*
**	list_length :
**		Renvoie la longueur d'une liste, quelque soit son type
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**
**	Arguments :
**		- l    : Un des noeuds de la liste (*)
**
**	Valeur de retour :
**		- Le nombre de noeuds dans la liste
**
**	Alias :
**		Pas d'alias
*/

size_t		list_length(void *l)
{
  t_list	*list;
  size_t	ret;

  list = list_get_first(l);
  ret = 0;
  while (list)
    {
      list = list->next;
      ++ret;
    }
  return (ret);
}
