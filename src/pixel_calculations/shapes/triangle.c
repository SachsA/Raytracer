/*
** triangle.c for rt in /home/THOMAZ_C/raytracer2/src/formes/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Mon Apr 17 14:47:20 2017 Corentin Thomazeau
** Last update Thu May 25 15:13:04 2017 Corentin Thomazeau
*/

#include <math.h>
#include "graph.h"
#include "lib/defines.h"

static int	calc_triangle(sfVector3f eye, sfVector3f dir,
			      sfVector3f *point, float *vector)
{
  sfVector3f	side[2];
  sfVector3f	pvec;
  sfVector3f	tvec;
  sfVector3f	qvec;
  float	det;

  side[0] = use_vec_sous(point[1], point[0]);
  side[1] = use_vec_sous(point[2], point[0]);
  pvec = use_cross_product(dir, side[1]);
  det = use_dot_product(side[0], pvec);
  if (fabs(det) < 0.00000001)
    return (0);
  det = 1 / det;
  tvec = use_vec_sous(eye, point[0]);
  vector[0] = use_dot_product(tvec, pvec) * det;
  if (vector[0] < 0 || vector[0] > 1)
    return (0);
  qvec = use_cross_product(tvec, side[0]);
  vector[1] = use_dot_product(dir, qvec) * det;
  if (vector[1] < 0 || vector[1] + vector[0] > 1)
    return (0);
  vector[2] = use_dot_product(qvec, side[1]) * det;
  return (1);
}

float		intersect_triangle(sfVector3f *eye, sfVector3f *dir,
				   t_obj *obj)
{
  sfVector3f	point[3];
  float	vector[3];

  point[0] = obj->pos;
  point[1] = obj->min;
  point[2] = obj->max;
  if (calc_triangle(*eye, *dir, point, vector))
    return (vector[2]);
  return (-1.0);
}

sfVector3f	get_normal_triangle(t_obj *obj, UNUSED sfVector3f *impact)
{
  sfVector3f	a;
  sfVector3f	b;

  a = use_vec_sous(obj->min, obj->pos);
  b = use_vec_sous(obj->max, obj->pos);
  a = use_cross_product(a, b);
  normalize_vector3f(&a);
  return (a);
}
