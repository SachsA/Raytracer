/*
** blit.c for raytracer2 in /raytracer2/src/pixels
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Thu Apr 13 15:18:55 2017 Thomas Lombard
** Last update Thu Apr 13 15:28:15 2017 Thomas Lombard
*/

#include "graph.h"

void	pix_blit_(t_my_framebuffer	*pix,
		  t_my_framebuffer	*clip,
		  sfVector2i		start,
		  sfVector2i		size)
{
  sfVector2i	i;
  sfVector2i	p;

  i.y = 0;
  while (i.y < size.y)
    {
      i.x = 0;
      while (i.x < size.x)
	{
	  p.y = start.y + i.y;
	  p.x = start.x + i.x;
	  put_pixel(pix, p.x, p.y, clip->buff[i.y * clip->width + i.x]);
	  ++i.x;
	}
      ++i.y;
    }
}
