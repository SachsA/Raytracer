/*
** append.c for chained in /src/lib/list
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Mon Apr 24 12:20:09 2017 Thomas Lombard
** Last update Mon Apr 24 17:25:27 2017 Thomas Lombard
*/

#include "list.h"

/*
**	list_pusha :
**		Ajoute un noeud alloué à la fin d'une liste,
**		quelque soit le type.
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**
**	Arguments :
**		- l    : Un des noeuds de la liste (*)
**		- n    : Un pointeur sur le nouveau noeud (**)
**		- size : La taille du noeud (sizeof ...)
**
**	Valeur de retour :
**		- Le pointeur vers le premier noeud de la liste
**
**	Alias :
**		Pas d'alias
*/
void		*list_pusha(void	*l,
			    void	*n,
			    size_t	size)
{
  t_list	*list;
  t_list	**new;
  t_list	*ret;

  new = (t_list **)n;
  list = (t_list *)l;
  ret = (t_list *)list;
  while (list && list->next)
    list = list->next;
  if (!(*new = xcalloc(1, size)))
    return (NULL);
  if (!list)
    ret = *new;
  (list) ? list->next = *new : 0;
  if (list)
    (*new)->prev = list;
  return (ret);
}

/*
**	list_push :
**		Ajoute un noeud non-alloué à la fin d'une liste,
**		quelque soit le type.
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**
**	Arguments :
**		- l    : Un des noeuds de la liste (*)
**		- n    : Un pointeur sur le nouveau noeud (**)
**		- size : La taille du noeud (sizeof ...)
**
**	Valeur de retour :
**		- Le pointeur vers le premier noeud de la liste
**
**	Alias :
**		Pas d'alias
*/
void		*list_push(void		*l,
			   void		*n)
{
  t_list	*list;
  t_list	*new;
  t_list	*ret;

  new = (t_list *)n;
  list = (t_list *)l;
  ret = (t_list *)list;

  list = list_get_last(list);
  if (!list)
    ret = new;
  if (list)
    {
      list->next = new;
      new->prev = list;
    }
  return (ret);
}
