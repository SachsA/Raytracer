/*
** putpixel.c for raytracer2 in /Infographie/raytracer2/src
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Apr 09 10:57:49 2017 Thomas Lombard
** Last update Sun Apr 09 11:11:48 2017 Thomas Lombard
*/

#include "graph.h"

void		put_pixel(t_my_framebuffer	*pix,
			  int			x,
			  int			y,
			  sfColor		e)
{
  if (x < 0 || x >= pix->width)
    return ;
  if (y < 0 || y >= pix->height)
    return ;
  if (e.a)
    pix->buff[pix->width * y + x] = e;
  return ;
}
