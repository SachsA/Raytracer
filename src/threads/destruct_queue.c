/*
** destruct_queue.c for raytracer2 in /raytracer2/src/threads
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Mon Apr 24 18:42:47 2017 Thomas Lombard
** Last update Mon Apr 24 18:43:58 2017 Thomas Lombard
*/

#include "header.h"

void		destruct_queue(void *queue)
{
  t_queue	*cur;

  cur = queue;
  free(cur->buff.buff);
}
