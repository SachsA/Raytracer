/*
** remove.c for chained in /src/lib/list
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Mon Apr 24 12:32:47 2017 Thomas Lombard
** Last update Mon Apr 24 15:43:06 2017 Thomas Lombard
*/

#include "list.h"

/*
**	list_detach_first :
**		Détache le premier noeud de la liste l,
**		quelque soit son type.
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**
**	Arguments :
**		- l    : Un pointeur sur la liste (**)
**
**	Valeur de retour :
**		- Le premier maillon de la liste
**
**	Alias :
**		Pas d'alias
*/
void		*list_detach_first(void *l)
{
  t_list	**list;
  t_list	*node;

  list = l;
  node = list_get_first(*list);
  if (!node)
    return (NULL);
  *list = (node->next) ? node->next : NULL;
  node->next = NULL;
  return (node);
}

/*
**	list_detach_first :
**		Détache le dernier noeud de la liste l,
**		quelque soit son type.
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**
**	Arguments :
**		- l    : Un pointeur sur la liste (**)
**
**	Valeur de retour :
**		- Le dernier maillon de la liste
**
**	Alias :
**		Pas d'alias
*/
void		*list_detach_last(void *l)
{
  t_list	**list;
  t_list	*node;

  list = l;
  node = list_get_last(*list);
  if (!node)
    return (NULL);
  *list = (node->prev) ? node->prev : NULL;
  node->prev = NULL;
  return (node);
}

/*
**	list_detach :
**		Détache le noeud désigné par n d'une liste,
**		quelque soit son type.
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**
**	Arguments :
**		- n    : Un pointeur sur le noeud (*)
**
**	Valeur de retour :
**		- Un des maillons de la liste
**
**	Alias :
**		Pas d'alias
*/
void		*list_detach(void	*n)
{
  t_list	*node;

  node = n;
  if (!node)
    return (NULL);
  n = (node->next) ? node->next : (node->prev) ? node->prev : NULL;
  if (node->next && node->prev)
    {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }
  else if (!node->next && node->prev)
    node->prev->next = NULL;
  else if (node->next && !node->prev)
    node->next->prev = NULL;
  node->prev = NULL;
  node->next = NULL;
  return (n);
}

/*
**	list_detach_selector :
**		Détache le noeud n d'une liste que désignera
**		la fonction "selector", quelque soit le type.
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**		Il faut que le sélecteur renvoie 0 pour que le maillon
**		soit détaché
**
**	Arguments :
**		- l        : La liste (**)
**		- data     : Les données de référence (*)
**		- selector : La fonction sélectrice (function)
**
**	Valeur de retour :
**		- Le maillon détaché. NULL le cas échéant
**
**	Alias :
**		Pas d'alias
*/
void		*list_detach_selector(void	*l,
				      void	*data,
				      int	(selector)(void *, void *))
{
  t_list	**list;
  t_list	*cursor;

  list = l;
  cursor = *list;
  while (cursor)
    {
      if (selector(data, cursor) == 0)
	{
	  *list = list_detach(cursor);
	  return (cursor);
	}
      cursor = cursor->next;
    }
  return (NULL);
}
