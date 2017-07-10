/*
** invert.c for raytracer2 in /raytracer2/src/post_render
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun May 28 09:59:28 2017 Thomas Lombard
** Last update Sun May 28 10:02:03 2017 Thomas Lombard
*/

#include "graph.h"

static inline void	invert(sfColor *color)
{
  color->r = ~color->r;
  color->g = ~color->g;
  color->b = ~color->b;
}

bool		keyevent_invert(t_core *core, UNUSED int param)
{
  sfVector2i	pos;

  pos.x = -1;
  while (++pos.x < core->win.size.x)
    {
      pos.y = -1;
      while (++pos.y < core->win.size.y)
	{
	  invert(&core->win.pix.buff[core->win.size.x * pos.y + pos.x]);
	}
    }
  return (true);
}
