/*
** find_shadow.c for Raytracer2 in /home/invicta/raytracer2/src/pixel_calculations/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Tue May  2 16:26:10 2017 Kellian CIPIERRE
** Last update Jul May 27 17:25:31 2017
*/

#include <math.h>
#include "graph.h"
#include "rotate.h"

static int	find_dist_shadow(t_scene *scene, t_obj *tmp,
			 sfVector3f *light_pos, sfVector3f *vec)
{
  double	dist;
  sfVector3f	pos;
  sfVector3f	vec2;

  if (tmp->type == 4)
    dist = scene->fn_tab[tmp->type].impact(light_pos, vec, tmp);
  else
    {
      vec2 = rotate_zyx(*vec, tmp->rot);
      pos = rotate_pov(light_pos, &tmp->pos, &tmp->rot);
      dist = scene->fn_tab[tmp->type].impact(&pos, &vec2, tmp);
    }
  if (dist > 0 && dist < 1)
    return (1);
  return (0);
}

int		find_shadow(t_scene *scene, sfVector3f *light_pos,
			    sfVector3f *impact, t_obj *obj)
{
  t_obj		*tmp;
  sfVector3f	vec;

  tmp = scene->objs;
  vec = calc_vector3f(light_pos, impact, 0);
  while (tmp != NULL)
    {
      if (tmp != obj)
	{
	  if (find_dist_shadow(scene, tmp, light_pos, &vec))
	    return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}
