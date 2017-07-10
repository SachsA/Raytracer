/*
** translate.c for translate in /home/sachs_a/delivery/c_graphical_programming/raytracer1/src
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Wed Feb 15 19:55:34 2017 Alexandre Sachs
** Last update Mar May 9 15:19:58 2017
*/

#include <graph.h>

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  sfVector3f	new_vector;

  new_vector.x = to_translate.x - translations.x;
  new_vector.y = to_translate.y - translations.y;
  new_vector.z = to_translate.z - translations.z;
  return (new_vector);
}

sfVector3f	obj_translate(sfVector3f to_translate, sfVector3f translations)
{
  sfVector3f	new_vector;

  new_vector.x = to_translate.x + translations.x;
  new_vector.y = to_translate.y + translations.y;
  new_vector.z = to_translate.z + translations.z;
  return (new_vector);
}
