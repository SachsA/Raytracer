/*
** utils.c for utils in /home/sachs_a/delivery/c_graphical_programming/raytracer1/src
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar 17 10:45:22 2017 Alexandre Sachs
** Last update Mar May 2 20:20:36 2017
*/

#include <math.h>
#include "graph.h"

float		delta_null(t_params *params)
{
  float         k1;

  if ((k1 = (-params->b) / (2 * params->a)) < 0)
    return (-1);
  return (k1);
}

float		delta_pos(float delta, t_params *params)
{
  float         k1;
  float         k2;

  k1 = ((-params->b) + sqrt(delta)) / (2 * params->a);
  k2 = ((-params->b) - sqrt(delta)) / (2 * params->a);
  if ((k1 > 0 && k2 < 0) || (k1 > 0 && k2 > 0 && k1 < k2))
    return (k1);
  else if (k2 > 0)
    return (k2);
  else
    return (-1);
}
