/*
** shade_color.c for raytracer2 in /raytracer2/src/post_render
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sat May 27 18:07:07 2017 Thomas Lombard
** Last update Sun May 28 09:57:52 2017 Thomas Lombard
*/

#include "graph.h"
#include "events.h"

static inline sfColor	to_sep(sfColor col)
{
  sfVector3f    new;

  new.x = ((float) (col.r)) * 0.393;
  new.x += ((float) (col.g)) * 0.769;
  new.x += ((float) (col.b)) * 0.189;
  new.y = ((float) (col.r)) * 0.349;
  new.y += ((float) (col.g)) * 0.686;
  new.y += ((float) (col.b)) * 0.168;
  new.z = ((float) (col.r)) * 0.272;
  new.z += ((float) (col.g)) * 0.534;
  new.z += ((float) (col.b)) * 0.131;
  col.r = (int) (new.x);
  col.g = (int) (new.y);
  col.b = (int) (new.z);
  if (new.x > 254)
    col.r = 255;
  if (new.y > 254)
    col.g = 255;
  if (new.z > 254)
    col.b = 255;
  return (col);
}

void	shade_grey(sfColor *c)
{
  int	a;

  a = c->r + c->g + c->b;
  a /= 3;
  c->r = a;
  c->g = a;
  c->b = a;
}

int	shade_color(sfColor *color, int param)
{
  if (param & GREY_SHADE)
    shade_grey(color);
  if ((param & BLU_SHADE) == BLU_SHADE)
    TO_BLU(color);
  else if ((param & GRN_SHADE) == GRN_SHADE)
    TO_GRN(color);
  else if ((param & RED_SHADE) == RED_SHADE)
    TO_RED(color);
  else if ((param & SEP_SHADE) == SEP_SHADE)
    *color = to_sep(*color);
  return (!0);
}

bool		keyevent_shade(t_core *core, int param)
{
  sfVector2i	pos;

  pos.x = -1;
  while (++pos.x < core->win.size.x)
    {
      pos.y = -1;
      while (++pos.y < core->win.size.y)
	{
	  shade_color(&core->win.pix.buff[core->win.size.x * pos.y + pos.x],
		      param);
	}
    }
  return (true);
}
