/*
** product.c for rt in /home/THOMAZ_C/raytracer2/src/use/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Sat Apr 22 17:13:20 2017 Corentin Thomazeau
** Last update Thu May 25 10:55:27 2017 Corentin Thomazeau
*/

#include <math.h>
#include "graph.h"
#include "lib/defines.h"

double		use_inner_product(sfVector3f a, sfVector3f b)
{
  double	ret;

  ret = 0;
  ret += a.x * b.x + a.x * b.y + a.x * b.z;
  ret += a.y * b.x + a.y * b.y + a.y * b.z;
  ret += a.z * b.x + a.z * b.y + a.z * b.z;
  return (ret);
}

double		use_dot_product(sfVector3f a, sfVector3f b)
{
  double	ret;

  ret = 0;
  ret += a.x * b.x;
  ret += a.y * b.y;
  ret += a.z * b.z;
  return (ret);
}

sfVector3f	use_cross_product(sfVector3f a, sfVector3f b)
{
  sfVector3f	ret;

  ret.x = a.y * b.z - a.z * b.y;
  ret.y = a.z * b.x - a.x * b.z;
  ret.z = a.x * b.y - a.y * b.x;
  return (ret);
}

sfVector3f	use_vec_sous(sfVector3f a, sfVector3f b)
{
  sfVector3f	c;

  c.x = a.x - b.x;
  c.y = a.y - b.y;
  c.z = a.z - b.z;
  return (c);
}
