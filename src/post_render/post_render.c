/*
** post_render.c for raytracer in /raytracer/src/post_render
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 24 17:35:16 2017 Thomas Lombard
** Last update Sun May 28 09:09:48 2017 Thomas Lombard
*/

#include <SFML/Graphics/Texture.h>
#include <SFML/System/Vector2.h>
#include "header.h"

/*
** Duplicate the originale scene
*/
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
