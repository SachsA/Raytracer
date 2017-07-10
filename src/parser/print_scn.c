/*
** print_scn.c for raytracer2 in /raytracer2/src/parser
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sat Apr 22 21:46:08 2017 Thomas Lombard
** Last update Fri May 26 14:51:31 2017 Theodore Marestin
*/

#include "header.h"

static void	print_obj_list(t_obj *obj)
{
  int		i;

  i = 0;
  while (obj)
    {
      printf("\nObj [%d] => \n", ++i);
      printf("\tobj->type\t%d\n", obj->type);
      printf("\tobj->rad\t%.2f\n", obj->rad);
      printf("\tobj->angle\t%.2f\n", obj->angle);
      printf("\tobj->flex\t%.2f\n", obj->flex);
      printf("\tobj->frac\t%.2f\n", obj->frac);
      printf("\tobj->pos\t(%.2f, %.2f, %.2f)\n",
	     obj->pos.x, obj->pos.y, obj->pos.z);
      printf("\tobj->rot\t(%.2f, %.2f, %.2f)\n",
	     obj->rot.x, obj->rot.y, obj->rot.z);
      printf("\tobj->min\t(%.2f, %.2f, %.2f)\n",
	     obj->min.x, obj->min.y, obj->min.z);
      printf("\tobj->max\t(%.2f, %.2f, %.2f)\n",
	     obj->max.x, obj->max.y, obj->max.z);
      printf("\tobj->color\t%d %d %d %d\n", obj->color.r, obj->color.g,
	     obj->color.b, obj->color.a);
      printf("\tobj->texture\t%s\n", (obj->tex) ? obj->tex->filename : "no");
      obj = obj->next;
    }
}

static void	print_light_list(t_light *light)
{
  int		i;

  i = 0;
  while (light)
    {
      printf("Light [%d] => \n", ++i);
      printf("\tlight->pos    (%2.2f, %2.2f, %2.2f)\n", light->pos.x,
	     light->pos.y, light->pos.z);
      printf("\tlight->color  %d %d %d %d\n", light->color.r, light->color.g,
	     light->color.b, light->color.a);
      light = light->next;
    }
}

void	print_scene(t_scene *scn)
{
  printf("\nElements \n");
  printf("hdr->magic_nbr  %X\n", scn->hdr.magic_nbr);
  printf("hdr->tag        %s\n", scn->hdr.tag);
  printf("hdr->scene_name %s\n", scn->hdr.scene_name);
  printf("hdr->nb_objs    %d\n", scn->hdr.nb_objs);
  printf("hdr->nb_lights  %d\n", scn->hdr.nb_lights);
  print_obj_list(scn->objs);
  print_light_list(scn->lights);
  printf("View : \n");
  printf("\tPosition     (%2.2f, %2.2f, %2.2f)\n",
	 scn->ori.eye.x, scn->ori.eye.y, scn->ori.eye.z);
  printf("\tDirection    (%2.2f, %2.2f, %2.2f)\n",
	 scn->ori.dir.x, scn->ori.dir.y, scn->ori.dir.z);
}
