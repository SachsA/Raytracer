/*
** bmp_calloc.c for wolf3d in /home/lombar_e/rendu/Infographie/wolf
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Mon  19 19:53:37 2016 Thomas Lombard
** Last update Wed Jan 04 09:42:40 2017 Thomas Lombard
*/

#include "bmp_core.h"

/*
** bmp_calloc -> Fonctionnement identique à calloc avec en plus :
**		alloc de nmemb + 1
**	       Exit si l'alloc fail
**	(Quand surchargé par _LIB_C_ALLOWED ou _EXIT_ALLOWED)
*/

void		*bmp_calloc(uint64_t nmemb, uint64_t msize)
{
  void		*ret;
  uint64_t	size;

  size = (nmemb + 1) * msize;
  if (!(ret = malloc(size)))
    return (NULL);
  bmp_memset(ret, 0, size);
  return (ret);
}
