/*
** xcalloc.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "lib/lib.h"
#include "errors.h"

/*
**	xcalloc : man calloc
**
**	Arguments :
**		- nmemb  : Le nombre de cases à allouer
**		- size   : La taille des cases à allouer
**
**	Valeur de retour :
**		- Le buffer alloué et memset à 0
**
**	Alias : Pas d'allias
*/

void		*xcalloc(uint64_t nmemb, uint64_t size)
{
  void		*ret;

  size = nmemb * size + 1;
  if (!(ret = malloc(size)))
    return (NULL);
  my_memset(ret, 0, size);
  return (ret);
}
