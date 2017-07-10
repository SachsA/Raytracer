/*
** add.c for add in /home/sachs_a/delivery/c_graphical_programming/raytracer2
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Tue May 23 17:30:43 2017 Alexandre Sachs
** Last update Jul May 27 19:43:03 2017
*/

#include <math.h>
#include "graph.h"

// int		add_spec_color(t_scene *scene, sfColor *new->spec.// 			       t_light *light, sfVector3f *spec)
// {
//   double        cosinus;
//   sfVector3f    view;
//
//   view = scene->view.dir;
//   normalize_vector3f(&view);
//   cosinus = -(spec->x * view.x) - (spec->y * view.y) - (spec->z * view.z);
//   if (cosinus <= 0)
//     return (0);
//   if (new->spec.r == 255 || new->spec.r + light->color.r * 1 * pow(cosinus, 50) > 255)
//     new->spec.r = 255;
//   else
//     new->spec.r += light->color.r * 1 * pow(cosinus, 50);
//   if (new->spec.g == 255 || new->spec.g + light->color.g * 1 * pow(cosinus, 50) > 255)
//     new->spec.g = 255;
//   else
//     new->spec.g += light->color.g * 1 * pow(cosinus, 50);
//   if (new->spec.b == 255 || new->spec.b + light->color.b * 1 * pow(cosinus, 50) > 255)
//     new->spec.b = 255;
//   else
//     new->spec.b += light->color.b * 1 * pow(cosinus, 50);
//   return (0);
// }

int		add_spec_color(t_scene *scene, t_obj *obj,
			       t_light *light, t_light_calc *new)
{
  double        cosinus;
  sfVector3f    view;

  view = scene->view.dir;
  normalize_vector3f(&view);
  cosinus = -(new->vector.x * view.x) - (new->vector.y * view.y) - (new->vector.z * view.z);
  if (cosinus <= 0)
    return (0);
  if (new->spec.r == 255 || new->spec.r + light->color.r * pow(cosinus, obj->frac) > 255)
    new->spec.r = 255;
  else
    new->spec.r += light->color.r * pow(cosinus, obj->frac);
  if (new->spec.g == 255 || new->spec.g + light->color.g * pow(cosinus, obj->frac) > 255)
    new->spec.g = 255;
  else
    new->spec.g += light->color.g * pow(cosinus, obj->frac);
  if (new->spec.b == 255 || new->spec.b + light->color.b * pow(cosinus, obj->frac) > 255)
    new->spec.b = 255;
  else
    new->spec.b += light->color.b * pow(cosinus, obj->frac);
  return (0);
}

int		add_color(t_scene *scene, sfColor *color, sfColor *new,
                          double cosinus)
{
  if (cosinus > 0)
    {
      color->r += cosinus * new->r / scene->hdr.nb_lights;
      color->g += cosinus * new->g / scene->hdr.nb_lights;
      color->b += cosinus * new->b / scene->hdr.nb_lights;
    }
  return (0);
}

int		add_effect_color(sfColor *color, sfColor *reflec,
				 t_obj *obj)
{
  color->r = color->r * (1 - obj->flex) + reflec->r * obj->flex;
  color->g = color->g * (1 - obj->flex) + reflec->g * obj->flex;
  color->b = color->b * (1 - obj->flex) + reflec->b * obj->flex;
  return (0);
}
