/*
** find_obj.c for Raytracer2 in /home/invicta/raytracer2/src/pixel_calculations
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Tue May  2 09:47:57 2017 Kellian CIPIERRE
** Last update May May 25 13:46:41 2017
*/

#include <math.h>
#include "graph.h"

sfVector3f	pixel_impact(t_scene *scene, double k)
{
  sfVector3f	impact;

  impact.x = scene->ori.eye.x + k * scene->ori.dir.x;
  impact.y = scene->ori.eye.y + k * scene->ori.dir.y;
  impact.z = scene->ori.eye.z + k * scene->ori.dir.z;
  return (impact);
}

static double  	intersection_obj(t_scene *scene, t_obj *obj)
{
  double	k;

  k = scene->fn_tab[obj->type].impact(&scene->view.eye,
					   &scene->view.dir, obj);
  return (k);
}

double		find_obj(t_scene *scene, t_obj **obj)
{
  t_obj		*tmp;
  double	k1;
  double	k2;

  moves_objs(scene, scene->objs);
  k1 = intersection_obj(scene, scene->objs);
  tmp = scene->objs;
  *obj = tmp;
  tmp = tmp->next;
  while (tmp != NULL)
    {
      moves_objs(scene, tmp);
      k2 = intersection_obj(scene, tmp);
      if ((k1 < 0 && k2 >= 0) || (k2 >= 0 && k2 < k1))
	{
	  k1 = k2;
	  *obj = tmp;
	}
      tmp = tmp->next;
    }
  return (k1);
}
