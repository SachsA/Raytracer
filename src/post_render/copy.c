/*
** copy.c for raytracer2 in /raytracer2/src/post_render
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun May 28 08:59:45 2017 Thomas Lombard
** Last update Sun May 28 09:22:03 2017 Thomas Lombard
*/

#include "graph.h"

void			post_render_copy(t_win *win, int mode)
{
  int			i;
  int			j;
  int			width;
  int			height;
  t_my_framebuffer	*origin;
  t_my_framebuffer	*target;

  i = -1;
  target = &win->pix;
  origin = &win->copy;
  if (mode)
    {
      origin = &win->pix;
      target = &win->copy;
    }
  width = origin->width;
  height = origin->height;
  while (++i < width)
    {
      j = -1;
      while (++j < height)
	{
	  target->buff[i * height + j] = origin->buff[i * height + j];
	}
    }
}
