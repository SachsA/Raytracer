/*
** cone.c for cone in /home/sachs_a/delivery/c_graphical_programming/raytracer1/src
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Tue Feb 14 21:31:16 2017 Alexandre Sachs
** Last update Mar May 23 23:13:24 2017
*/

#include <math.h>
#include "graph.h"
#include "lib/defines.h"

sfVector3f	get_normal_cone(t_obj *obj, sfVector3f *impact)
{
  sfVector3f	norm;
  float		angle;

  angle = obj->angle / 180 * M_PI;
  norm.x = impact->x - obj->pos.x;
  norm.y = impact->y - obj->pos.y;
  norm.z = -tan(angle) * (impact->z - obj->pos.z);
  normalize_vector3f(&norm);
  return (norm);
}

static void	calc_params(sfVector3f *eye, sfVector3f *dir, t_obj *obj,
			    t_params *params)
{
  float		angle;

  angle = obj->angle / 180 * M_PI;
  params->a = (pow(dir->x, 2) + pow(dir->y, 2)) -
      pow(dir->z * tan(angle), 2);
  params->b = ((2 * eye->x * dir->x) +
	      (2 * eye->y * dir->y)) -
  (2 * eye->z * dir->z *
   pow(tan(angle), 2));
  params->c = (pow(eye->x, 2) + pow(eye->y, 2)) -
      (pow(eye->z, 2) * pow(tan(angle), 2));
}

float		intersect_cone(sfVector3f *eye, sfVector3f *dir, t_obj *obj)
{
  t_params	params;
  float		delta;

  if (obj->angle <= 0 || obj->angle >= 90)
    return (-1);
  calc_params(eye, dir, obj, &params);
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
  if ((dir->z * delta + eye->z) > 0)
    return (-1);
  return (delta);
}
