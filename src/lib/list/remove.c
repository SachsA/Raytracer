/*
** remove.c for chained in /src/lib/list
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Mon Apr 24 13:49:52 2017 Thomas Lombard
** Last update Mon Apr 24 18:40:03 2017 Thomas Lombard
*/

#include <stdlib.h>

#include "list.h"

/*
**	list_remove :
**		Supprime un maillon d'une liste, quelque soit son type
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**
**	Arguments :
**		- l    : Un des noeuds de la liste (*)
**		- n    : Le noeud à supprimer (*)
**
**	Valeur de retour :
**		- Le pointeur vers le premier noeud de la liste
**
**	Alias :
**		Pas d'alias
*/

void		*list_remove(void	*l,
			     void	*n)
{
  l = list_detach(n);
  free(n);
  return (l);
}

/*
**	list_remove :
**		Supprime un maillon d'une liste suivant une méthode
**		spécifiée par method, quelque soit son type
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**
**	Arguments :
**		- l      : Un des noeuds de la liste (*)
**		- n      : Le noeud à supprimer (*)
**		- method : La fonction supprimant le contenu du noeud
**
**	Valeur de retour :
**		- Le pointeur vers le premier noeud de la liste
**
**	Alias :
**		Pas d'alias
*/

void		*list_remove_method(void	*l,
				    void	*n,
				    void	(method)(void *))
{
  l = list_detach(n);
  method(n);
  free(n);
  return (l);
}

/*
**	list_destruct :
**		Détruit la liste l quel que soit son type
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**
**	Arguments :
**		- l      : Un des noeuds de la liste (*)
**		- n      : Le noeud à supprimer (*)
**		- method : La fonction supprimant le contenu du noeud
**
**	Valeur de retour :
**		- Le pointeur vers le premier noeud de la liste
**
**	Alias :
**		Pas d'alias
*/
void		list_destruct(void	*l)
{
  t_list	*list;

  list = l;
  while (list)
    {
      l = list;
      list = list->next;
      free(l);
    }
}

/*
**	list_destruct_method :
**		Détruit la liste l quel que soit son type selon la methode
**		spécifiée par la fonction method
**		!! Ne fonctionne seulement si les deux premiers items de
**		   la structure chaînée sont un pointeur next puis prev.
**
**	Arguments :
**		- l      : Un des noeuds de la liste (*)
**		- n      : Le noeud à supprimer (*)
**		- method : La fonction supprimant le contenu du noeud
**
**	Valeur de retour :
**		- Le pointeur vers le premier noeud de la liste
**
**	Alias :
**		Pas d'alias
*/
void		list_destruct_method(void	*l,
				     void	(method)(void *))
{
  t_list	*list;

  list = l;
  while (list)
    {
      l = list;
      list = list->next;
      method(l);
    }
}
