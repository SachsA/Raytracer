/*
** flip.c for raytracer2 in /raytracer2/src/post_render
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun May 28 08:31:19 2017 Thomas Lombard
** Last update Sun May 28 09:50:13 2017 Thomas Lombard
*/

#include "lib/lib.h"
#include "graph.h"

#define MIRROR_Y	(1 << 0)
#define MIRROR_X	(1 << 1)
#define POS(width, p) (width * p.y + p.x)

static inline void	swap_val(unsigned char *a, unsigned char *b)
{
  unsigned char		tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

static inline void	swap_colors(sfColor *a, sfColor *b)
{
  swap_val(&a->r, &b->r);
  swap_val(&a->g, &b->g);
  swap_val(&a->b, &b->b);
  swap_val(&a->a, &b->a);
}

void		mirror_pix_array(t_my_framebuffer *pix, int mode)
{
  sfVector2i	s;
  sfVector2i	e;
  int		w;

  if (!mode)
    return ;
  s.x = 0;
  s.y = 0;
  e.y = (mode & FLIP_Y) ? pix->height - 1 : 0;
  w = pix->width;
  while (s.y < pix->height / ((mode & FLIP_Y && !(mode & FLIP_X)) ? 2 : 1))
    {
      s.x = 0;
      e.x = (mode & FLIP_X) ? pix->width - 1 : 0;
      while (s.x < pix->width / ((mode & FLIP_X) ? 2 : 1))
	{
	  swap_colors(&pix->buff[w * s.y + s.x], &pix->buff[w * e.y + e.x]);
	  s.x++;
	  e.x += (mode & FLIP_X) ? -1 : 1;
	}
      s.y++;
      e.y += (mode & FLIP_Y) ? -1 : 1;
    }
}


bool	keyevent_flip(UNUSED t_core *core, UNUSED int n)
{
  int		mode;

  mode = 0;
  mode += (n & FLIP_X) ? MIRROR_X : 0;
  mode += (n & FLIP_Y) ? MIRROR_Y : 0;
  mirror_pix_array(&core->win.pix, n);
  return (true);
}
