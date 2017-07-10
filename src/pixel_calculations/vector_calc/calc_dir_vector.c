/*
** calc_dir_vector.c for calc_dir_vector in /home/sachs_a/delivery/c_graphical_programming/raytracer1/src
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Mon Feb 13 18:51:24 2017 Alexandre Sachs
** Last update Sat May 27 06:51:59 2017 Theodore Marestin
*/

#include "lib/defines.h"
#include "graph.h"

void	calc_dir_vector(t_scene 	*restrict scene,
			sfVector2i	pos)
{
  scene->ori.dir.x = DIST_TO_PLANE;
  scene->ori.dir.y = (scene->render_size.x / 2 - pos.x);
  scene->ori.dir.z = (scene->render_size.y / 2 - pos.y);
}
