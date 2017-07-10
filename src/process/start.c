/*
** start.c for raytracer2 in /raytracer2/src/process
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Apr 09 21:45:22 2017 Thomas Lombard
** Last update Wed May 24 14:46:37 2017 Thomas Lombard
*/

#include <semaphore.h>
#include "graph.h"
#include "header.h"

static void	blit_pos(t_my_framebuffer	*pix,
			 t_my_framebuffer	*blit,
			 sfVector2i		pos)
{
  sfVector2i	i;

  i.y = -1;
  while (++i.y < blit->height && i.y + pos.y < pix->height)
    {
      i.x = -1;
      while (++i.x < blit->width && i.x + pos.x < pix->width)
	{
	  pix->buff[(i.y + pos.y) * pix->width + (i.x + pos.x)] =
	  blit->buff[i.y * blit->width + i.x];
	}
    }
}

static inline int	thread_turn(t_thread	*thrd, int max)
{
  int			i;

  i = -1;
  while (++i < max)
    {
      if (thrd[i].end == 0)
	return (1);
    }
  return (0);
}

static inline void	update_text(t_core *core, int nbr, char *progress)
{
  snprintf(progress, 1024 + 1, "Reste %4d / %4d", nbr, core->opti.nb_task);
  sfText_setString(core->win.text, progress);
  sfText_setOrigin(core->win.text, TEXT_ORIGIN);
  sfRenderWindow_drawText(core->win.win, core->win.text, NULL);
}

static void	display_chunk(t_core *core, t_queue *cur,
			      int nbr, char *progress)
{
  while (cur)
    {
      blit_pos(&core->win.pix, &cur->buff, cur->pos);
      sfTexture_updateFromPixels(core->win.tex, (sfUint8 *)core->win.pix.buff,
				 core->win.pix.width, core->win.pix.height,
				 0, 0);
      --core->opti.length;
      cur = cur->next;
    }
  sfRenderWindow_clear(core->win.win, sfBlack);
  sfRenderWindow_drawSprite(core->win.win, core->win.spr, NULL);
  update_text(core, nbr, progress);
  sfRenderWindow_display(core->win.win);
  my_memset(progress, 0, m_strl(progress));
}

int		thread_processing(t_core *core)
{
  t_queue	*cur;
  int		nbr;
  char		progress[1024 + 1];

  pthread_mutex_unlock(&core->opti.data.in.mtex);
  while (1 && thread_turn(core->opti.threads, core->opti.nb_thrd) &&
	 sfRenderWindow_isOpen(core->win.win))
    {
      pthread_mutex_lock(&core->opti.data.mtex_cond);
      pthread_cond_wait(&core->opti.data.cond, &core->opti.data.mtex_cond);
      cur = core->opti.data.out.data;
      core->opti.data.out.data = NULL;
      nbr = core->opti.length;
      pthread_mutex_unlock(&core->opti.data.mtex_cond);
      display_chunk(core, cur, nbr, progress);
      list_destruct_method(cur, destruct_queue);
    }
  display_chunk(core, core->opti.data.out.data, core->opti.length, progress);
  return (0);
}
