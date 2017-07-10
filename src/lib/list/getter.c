/*
** getter.c for chained in /src/lib/list
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Mon Apr 24 14:03:55 2017 Thomas Lombard
** Last update Fri May 12 17:25:30 2017 Theodore Marestin
*/

#include "list.h"

/*
**	list_get_first :
**		Renvoie le premier maillon d'une liste, quelque soit son type
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**
**	Arguments :
**		- l    : Un des noeuds de la liste (*)
**
**	Valeur de retour :
**		- Le pointeur vers le premier noeud de la liste
**
**	Alias :
**		Pas d'alias
*/
void		*list_get_first(void	*l)
{
  t_list	*list;

  list = l;
  while (list && list->prev)
    list = list->prev;
  return (list);
}

/*
**	list_get_last :
**		Renvoie le dernier maillon d'une liste, quelque soit son type
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**
**	Arguments :
**		- l    : Un des noeuds de la liste (*)
**
**	Valeur de retour :
**		- Le pointeur vers le dernier noeud de la liste
**
**	Alias :
**		Pas d'alias
*/
void		*list_get_last(void	*l)
{
  t_list	*list;

  list = l;
  while (list && list->next)
    list = list->next;
  return (list);
}

/*
**	list_get_selector :
**		Renvoie le premier noeud n d'une liste que désignera
**		la fonction "selector", quelque soit son type.
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**		Il faut que le sélecteur renvoie 0 pour que le maillon
**		soit renvoyé
**
**	Arguments :
**		- l        : La liste (*)
**		- data     : Les données de référence (*)
**		- selector : La fonction sélectrice (function)
**
**	Valeur de retour :
**		- Le maillon trouvé. NULL le cas échéant
**
**	Alias :
**		Pas d'alias
*/
void		*list_get_selector(void	*l,
				   void	*data,
				   int	(*selector)(void *, void *))
{
  t_list	*list;

  list = list_get_first(l);
  while (list)
    {
      if (selector(data, list) == 0)
	return (list);
      list = list->next;
    }
  return (NULL);
}
