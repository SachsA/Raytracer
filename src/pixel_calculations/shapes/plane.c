/*
** plane.c for plane in /home/sachs_a/delivery/c_graphical_programming/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Mon Feb 13 18:58:17 2017 Alexandre Sachs
** Last update Mar May 23 09:31:33 2017
*/

#include "lib/defines.h"
#include "graph.h"
#include "lib/defines.h"

sfVector3f	get_normal_plane(UNUSED t_obj *obj, UNUSED sfVector3f *impact)
{
  sfVector3f	normal;

  normal.x = 0;
  normal.y = 0;
  normal.z = 100;
  normalize_vector3f(&normal);
  return (normal);
}

float		intersect_plane(sfVector3f *eye, sfVector3f *dir,
				UNUSED t_obj *obj)
{
  float		k;

  if (dir->z <= 10e-3 && dir->z >= -10e-3)
    return (-1);
  k = -((eye->z) / dir->z);
  if (k > 0)
    return (k);
  return (-1);
}
