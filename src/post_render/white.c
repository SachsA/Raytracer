/*
** preserve_color.c for raytracer2 in /home/MAREST_T/Tech1-Projects/CGraph_Prog/Raytracer/raytracer2
**
** Made by Theodore Marestin
** Login   <MAREST_T@epitech.net>
**
** Started on  Sun May 28 14:09:52 2017 Theodore Marestin
** Last update Sun May 28 20:48:08 2017 Thomas Lombard
*/

#include <math.h>
#include "graph.h"
#include "events.h"
#include "lib/lib.h"

/*
**	Find the max value in the intensity of sub-pixels and set the new color
*/
static void	pastel_findmax(t_my_framebuffer *buff, const sfVector2i pos,
			       const int intensity[4][PASTEL_LEVEL + 1])
{
  int		i;
  int		max;
  int		maxid;

  max = 0;
  maxid = 0;
  i = 0;
  while (i < PASTEL_LEVEL + 1)
    {
      if (intensity[0][i] > max)
	{
	  max = intensity[0][i];
	  maxid = i;
	}
      ++i;
    }
  buff->buff[buff->width * pos.y + pos.x].r = intensity[1][maxid] / max;
  buff->buff[buff->width * pos.y + pos.x].g = intensity[2][maxid] / max;
  buff->buff[buff->width * pos.y + pos.x].b = intensity[3][maxid] / max;
}

/*
**	Check all sub-pixels within pastel radius and calculate all average
*/
static void	pastel(t_my_framebuffer *buff, const sfColor *copy,
		       const sfVector2i pos)
{
  sfColor	pixel;
  int		curr;
  int		intensity[4][PASTEL_LEVEL + 1];
  sfVector2i	i;

  my_memset(intensity, 0, sizeof(intensity));
  i.x = pos.x - PASTEL_RADIUS - 1;
  while (++i.x < pos.x + PASTEL_RADIUS)
    {
      i.y = pos.y - abs(abs(pos.x - PASTEL_RADIUS) - abs(i.x));
      while (i.y < pos.y + abs(abs(pos.x + PASTEL_RADIUS) - abs(i.x)))
	{
	  if (i.x >= 0 && i.x < buff->width && i.y >= 0 && i.y < buff->height)
	    {
	      pixel = copy[buff->width * i.y + i.x];
	      curr = (pixel.r + pixel.g + pixel.b) / 3 * PASTEL_LEVEL / 255;
	      ++intensity[0][curr];
	      intensity[1][curr] += pixel.r;
	      intensity[2][curr] += pixel.g;
	      intensity[3][curr] += pixel.b;
	    }
	  ++i.y;
	}
    }
  pastel_findmax(buff, pos, intensity);
}

/*
**	For all pixels, call a subfunction who check all sub-pixels
*/
bool		keyevent_pastel(t_core *core, UNUSED int param)
{
  sfVector2i	pos;

  pos.x = 0;
  while (pos.x < core->win.size.x)
    {
      pos.y = 0;
      while (pos.y < core->win.size.y)
	{
	  pastel(&core->win.pix, core->win.copy.buff, pos);
	  ++pos.y;
	}
      ++pos.x;
    }
  return (true);
}

bool		keyevent_white(t_core *core, UNUSED int param)
{
  int		c;
  sfVector2i	pos;

  pos.x = 0;
  while (pos.x < core->win.size.x)
    {
      pos.y = 0;
      while (pos.y < core->win.size.y)
	{
	  c = core->win.pix.buff[core->win.size.x * pos.y + pos.x].r;
	  c += core->win.pix.buff[core->win.size.x * pos.y + pos.x].g;
	  c += core->win.pix.buff[core->win.size.x * pos.y + pos.x].b;
	  c /= 3;
	  c = (c >= 128) ? 255 : 0;
	  core->win.pix.buff[core->win.size.x * pos.y + pos.x].r = c;
	  core->win.pix.buff[core->win.size.x * pos.y + pos.x].g = c;
	  core->win.pix.buff[core->win.size.x * pos.y + pos.x].b = c;
	  ++pos.y;
	}
      ++pos.x;
    }
  return (true);
}
