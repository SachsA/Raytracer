/*
** cylinder.c for cylinder in /home/sachs_a/delivery/c_graphical_programming/raytracer1/src
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Tue Feb 14 10:07:53 2017 Alexandre Sachs
** Last update Thu May 25 15:08:56 2017 Kellian CIPIERRE
*/

#include <math.h>
#include "graph.h"
#include "lib/defines.h"

sfVector3f	get_normal_cylinder(UNUSED t_obj *obj, sfVector3f *impact)
{
  sfVector3f    normal;

  normal.x = impact->x - obj->pos.x;
  normal.y = impact->y - obj->pos.y;
  normal.z = 0;
  normalize_vector3f(&normal);
  return (normal);
}

float		intersect_cylinder(sfVector3f *eye, sfVector3f *dir,
				   t_obj *obj)
{
  t_params	params;
  float		delta;

  if (obj->rad <= 0)
    return (-1);
  params.a = pow(dir->x, 2) + pow(dir->y, 2);
  params.b = (2 * eye->x * dir->x) +
    (2 * eye->y * dir->y);
  params.c = pow(eye->x, 2) + pow(eye->y, 2) -
    pow(obj->rad, 2);
  delta = pow(params.b, 2) - (4 * (params.a * params.c));
  if (delta < 0)
    return (-1);
  else if (delta == 0)
    {
      if ((delta = delta_null(&params)) == -1)
	return (-1);
    }
  else
    if ((delta = delta_pos(delta, &params)) == -1)
      return (-1);
  return (delta);
}
