/*
** rotate.c for raytracer 1 in /home/MAREST_T/Tech1-Projects/CGraph_Prog/Raytracer1/raytracer1
**
** Made by Theodore Marestin
** Login   <MAREST_T@epitech.net>
**
** Started on  Mon Feb 13 20:28:43 2017 Theodore Marestin
** Last update Apr May 24 19:14:57 2017
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "graph.h"
#include "rotate.h"

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  t_rotate	mtx_rotate;
  sfVector3f	new_vect;

  if (angles.x == 0 && angles.y == 0 && angles.z == 0)
    return (to_rotate);
  init_mtx_rotx(mtx_rotate.rot_x, angles);
  init_mtx_roty(mtx_rotate.rot_y, angles);
  init_mtx_rotz(mtx_rotate.rot_z, angles);
  init_id_mtx(mtx_rotate.result);
  mtx_rotate.result[0] = to_rotate.x;
  mtx_rotate.result[1] = to_rotate.y;
  mtx_rotate.result[2] = to_rotate.z;
  product_matrix(mtx_rotate.result, mtx_rotate.rot_x);
  product_matrix(mtx_rotate.result, mtx_rotate.rot_y);
  product_matrix(mtx_rotate.result, mtx_rotate.rot_z);
  new_vect.x = mtx_rotate.result[0];
  new_vect.y = mtx_rotate.result[1];
  new_vect.z = mtx_rotate.result[2];
  return (new_vect);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  t_rotate	mtx_rotate;
  sfVector3f	new_vect;

  if (angles.x == 0 && angles.y == 0 && angles.z == 0)
    return (to_rotate);
  init_mtx_rotx(mtx_rotate.rot_x, angles);
  init_mtx_roty(mtx_rotate.rot_y, angles);
  init_mtx_rotz(mtx_rotate.rot_z, angles);
  init_id_mtx(mtx_rotate.result);
  mtx_rotate.result[0] = to_rotate.x;
  mtx_rotate.result[1] = to_rotate.y;
  mtx_rotate.result[2] = to_rotate.z;
  product_matrix(mtx_rotate.result, mtx_rotate.rot_z);
  product_matrix(mtx_rotate.result, mtx_rotate.rot_y);
  product_matrix(mtx_rotate.result, mtx_rotate.rot_x);
  new_vect.x = mtx_rotate.result[0];
  new_vect.y = mtx_rotate.result[1];
  new_vect.z = mtx_rotate.result[2];
  return (new_vect);
}

sfVector3f	rotate_pov(sfVector3f *light, sfVector3f *pos, sfVector3f *rot)
{
  sfVector3f	new_pos;

  new_pos = translate(*light, *pos);
  new_pos = rotate_zyx(new_pos, *rot);
  return (new_pos);
}
