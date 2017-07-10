/*
** reflect.c for Raytracer2 in /home/invicta/raytracer2/src/pixel_calculations/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Sat May 13 14:31:27 2017 Kellian CIPIERRE
** Last update Thu May 25 12:30:34 2017 Corentin Thomazeau
*/

#include "rotate.h"
#include "graph.h"

int		reflect(t_scene *scene, t_obj *obj, sfVector3f *impact)
{
  sfVector3f	normal_vector;
  sfVector3f	view_vector;
  float		cosinus;
  sfVector3f	impact2;
  sfVector3f	inv;

  inv = inv_vector3f(&obj->rot);
  view_vector = scene->ori.dir;
  normalize_vector3f(&view_vector);
  impact2 = rotate_xyz(*impact, obj->rot);
  scene->ori.eye = *impact;
  normal_vector = scene->fn_tab[obj->type].norm(obj, &impact2);
  normal_vector = rotate_xyz(normal_vector, inv);
  cosinus = cosinus_calc(&normal_vector, &view_vector);
  scene->ori.dir.x = view_vector.x - 2 * cosinus * normal_vector.x;
  scene->ori.dir.y = view_vector.y - 2 * cosinus * normal_vector.y;
  scene->ori.dir.z = view_vector.z - 2 * cosinus * normal_vector.z;
  return (0);
}

sfVector3f	reflect_vector(t_scene *scene, sfVector3f *vector,
			       t_obj *obj, sfVector3f *impact)
{
  sfVector3f	reflect;
  sfVector3f	normal_vector;
  float		cosinus;

  normal_vector = scene->fn_tab[obj->type].norm(obj, impact);
  normalize_vector3f(&normal_vector);
  cosinus = vector->x * normal_vector.x +
      vector->y * normal_vector.y +
  vector->z * normal_vector.z;
  reflect.x = vector->x - 2 * cosinus * normal_vector.x;
  reflect.y = vector->y - 2 * cosinus * normal_vector.y;
  reflect.z = vector->z - 2 * cosinus * normal_vector.z;
  return (reflect);
}
