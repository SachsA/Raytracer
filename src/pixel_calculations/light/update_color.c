/*
** update_color.c for Raytracer2 in /home/invicta/raytracer2/src/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Tue May  2 14:14:30 2017 Kellian CIPIERRE
** Last update Jul May 27 19:35:15 2017
*/

#include <math.h>
#include "graph.h"
#include "rotate.h"
#include "texture.h"

static int	update_colors(t_scene *scene, sfColor *color,
			      sfColor *light_color)
{
  if ((color->r * light_color->r) / 255 * (scene->hdr.nb_lights) > 255)
    color->r = 255;
  else
    color->r = (color->r * light_color->r) / 255 * (scene->hdr.nb_lights);
  if ((color->g * light_color->g) / 255 * (scene->hdr.nb_lights) > 255)
    color->g = 255;
  else
    color->g = (color->g * light_color->g) / 255 * (scene->hdr.nb_lights);
  if ((color->b * light_color->b) / 255 * (scene->hdr.nb_lights) > 255)
    color->b = 255;
  else
    color->b = (color->b * light_color->b) / 255 * (scene->hdr.nb_lights);
  return (0);
}

int		update_spec(sfColor *color, sfColor *spec_color)
{
  if (color->r + spec_color->r > 255)
    color->r = 255;
  else
    color->r += spec_color->r;
  if (color->g + spec_color->g > 255)
    color->g = 255;
  else
    color->g += spec_color->g;
  if (color->b + spec_color->b > 255)
    color->b = 255;
  else
    color->b += spec_color->b;
  return (0);
}

static t_light	*init_update_color(t_light *light, t_light_calc *new_light)
{
  t_light	*new;
  new = light;
  new_light->light = (sfColor){0, 0, 0, 255};
  new_light->spec = (sfColor){0, 0, 0, 255};
  return (new);
}

static double	calc_light_cos(t_light_calc *new, t_light *light,
			       t_obj *obj, sfVector3f *impact)
{
  double	cosinus;

  if (obj->type != 4)
    new->pos = rotate_pov(&light->pos, &obj->pos, &obj->rot);
  else
    new->pos = light->pos;
  new->vector = calc_vector3f(&new->pos, impact, 1);
  cosinus = cosinus_calc(&new->vector, &new->normal);
  return (cosinus);
}

sfColor		update_light(t_scene *scene, sfColor *color, t_obj *obj,
			     sfVector3f *impact)
{
  t_light_calc	new;
  t_light	*light;
  sfVector3f	impact2;
  double	cosinus;

  light = init_update_color(scene->lights, &new);
  impact2 = rotate_zyx(*impact, obj->rot);
  new.normal = scene->fn_tab[obj->type].norm(obj, &impact2);
  if (cosinus_calc(&new.normal, &scene->view.dir) > 0)
    new.normal = inv_vector3f(&new.normal);
  while (light != NULL)
    {
      if (find_shadow(scene, &light->pos, impact, obj) == 0)
	{
	  cosinus = calc_light_cos(&new, light, obj, &impact2);
	  if (!update_texture(obj, color, *impact))
	    add_color(scene, color, &obj->color, -cosinus);
	  add_color(scene, &new.light, &light->color, -cosinus);
	  new.vector = reflect_vector(scene, &new.vector, obj, &impact2);
	//   add_spec_color(scene, &new.spec, light, &new.vector);
	  add_spec_color(scene, obj, light, &new);
	}
      light = light->next;
    }
  update_colors(scene, color, &new.light);
  return (new.spec);
}
