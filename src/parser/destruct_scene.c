/*
** destruct_scene.c for raytracer2 in /raytracer2/src/parser
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sat Apr 22 21:33:51 2017 Thomas Lombard
** Last update Sun May 21 12:51:51 2017 Thomas Lombard
*/

#include "header.h"

int	destruct_scene(t_scene *scn)
{
  list_destruct(scn->objs);
  list_destruct(scn->lights);
  return (0);
}
