/*
** normalize_vector.c for Raytracer2 in /home/invicta/raytracer2/src/pixel_calculations/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Tue May  2 19:31:25 2017 Kellian CIPIERRE
** Last update Fri May  5 19:29:57 2017 Theodore Marestin
*/

#include <math.h>
#include "graph.h"

int		normalize_vector3f(sfVector3f *vector)
{
  double	normal;

  normal = sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
  if (normal != 0)
    {
      vector->x /= normal;
      vector->y /= normal;
      vector->z /= normal;
    }
  return (0);
}
