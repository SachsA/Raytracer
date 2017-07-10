/*
** sphere.c for sphere in /home/sachs_a/delivery/c_graphical_programming/raytracer1/src
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Mon Feb 13 18:57:17 2017 Alexandre Sachs
** Last update Sat May 27 05:34:29 2017 Theodore Marestin
*/

#include <math.h>
#include "graph.h"
#include "lib/defines.h"

sfVector3f	get_normal_sphere(t_obj *obj, sfVector3f *impact)
{
  sfVector3f	normal;

  normal.x = impact->x - obj->pos.x;
  normal.y = impact->y - obj->pos.y;
  normal.z = impact->z - obj->pos.z;
  normalize_vector3f(&normal);
  return (normal);
}

float		intersect_sphere(sfVector3f *eye, sfVector3f *dir, t_obj *obj)
{
  t_params	params;
  float		delta;

  params.a = pow(dir->x, 2) + pow(dir->y, 2) + pow(dir->z, 2);
  params.b = 2 * ((eye->x * dir->x) +
		  (eye->y * dir->y) +
		  (eye->z * dir->z));
  params.c = pow(eye->x, 2) + pow(eye->y, 2) +
      pow(eye->z, 2) - pow(obj->rad, 2);
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
