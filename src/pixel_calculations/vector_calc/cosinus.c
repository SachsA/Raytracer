/*
** cosinus.c for Raytracer2 in /home/invicta/raytracer2/src/pixel_calculations/vector_calc/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Tue May 23 09:11:59 2017 Kellian CIPIERRE
** Last update Mar May 23 09:21:36 2017
*/

#include "graph.h"

double		cosinus_calc(sfVector3f *vec1, sfVector3f *vec2)
{
  double	cosinus;

  cosinus = (vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z);
  return (cosinus);
}
