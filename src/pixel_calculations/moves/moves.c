/*
** moves.c for Raytracer2 in /home/invicta/raytracer2/src/pixel_calculations/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Fri May  5 20:19:21 2017 Kellian CIPIERRE
** Last update Jul May 27 17:35:44 2017
*/

#include "graph.h"
#include "rotate.h"

int	moves_objs(t_scene *scene, t_obj *obj)
{
  if (obj->type == 4)
    {
      scene->view.dir = scene->ori.dir;
      scene->view.eye = scene->ori.eye;
      return (0);
    }
  if (obj->rot.x || obj->rot.y || obj->rot.z)
    {
      scene->view.dir = rotate_zyx(scene->ori.dir, obj->rot);
      scene->view.eye = translate(scene->ori.eye, obj->pos);
      scene->view.eye = rotate_zyx(scene->view.eye, obj->rot);
    }
  else
    {
      scene->view.eye = translate(scene->ori.eye, obj->pos);
      scene->view.dir = scene->ori.dir;
    }
  return (0);
}
