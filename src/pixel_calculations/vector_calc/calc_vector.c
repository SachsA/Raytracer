/*
** calc_vector.c for Raytracer2 in /home/invicta/raytracer2/src/pixel_calculations/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Tue May  2 19:27:37 2017 Kellian CIPIERRE
** Last update Jul May 27 11:18:20 2017
*/

#include "graph.h"

sfVector3f	calc_vector3f(sfVector3f *from, sfVector3f *to, int normalize)
{
  sfVector3f	vector;

  vector.x = to->x - from->x;
  vector.y = to->y - from->y;
  vector.z = to->z - from->z;
  if (normalize == 1)
    normalize_vector3f(&vector);
return (vector);
}

sfVector3f	inv_vector3f(sfVector3f	*src)
{
  sfVector3f	new;

  new.x = -src->x;
  new.y = -src->y;
  new.z = -src->z;
  return (new);
}
