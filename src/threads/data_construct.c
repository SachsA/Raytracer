/*
** data_construct.c for raytracer2 in /raytracer2/src/threads
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Thu Apr 06 09:40:47 2017 Thomas Lombard
** Last update Mon May 22 20:41:48 2017 Thomas Lombard
*/

#include <SFML/Graphics/Color.h>
#include <pthread.h>

#include "lib/lib.h"
#include "header.h"

static inline int	calc_chunk_x(t_core *core, t_chunk *chunk, int i)
{
  chunk->pos.x = i * chunk->size.x;
  chunk->size.x = (((i + 1) * chunk->size.x > core->win.size.x) ?
		   (i + 1) * core->opti.chnk_size.x - core->win.size.x :
		   core->opti.chnk_size.x);
  return (chunk->size.x);
}

static inline int	calc_chunk_y(t_core *core, t_chunk *chunk, int i)
{
  chunk->pos.y = i * chunk->size.y;
  chunk->size.y = (((i + 1) * chunk->size.y > core->win.size.y) ?
		   (i + 1) * core->opti.chnk_size.y - core->win.size.y :
		   core->opti.chnk_size.y);
  return (chunk->size.y);
}

static int	set_chunk(t_queue *node, t_core *core, t_chunk chunk, int id)
{
  if (core->opti.nb_thrd > 0 &&
      !(node->buff.buff = xcalloc(core->opti.chnk_size.x *
				  core->opti.chnk_size.y, sizeof(sfColor))))
    return (e_alloc);
  node->buff.width = core->opti.chnk_size.x;
  node->buff.height = core->opti.chnk_size.y;
  node->color = sfColor_fromRGB(rand() % 256, rand() % 256, rand() % 256);
  node->size = core->opti.chnk_size;
  node->pos = chunk.pos;
  node->id = id;
  return (0);
}

int		construct_list(t_core *core, t_queue **queue)
{
  sfVector2i	inc;
  sfVector2i	nchk;
  t_queue	*node;
  t_chunk	chunk;
  int		i;

  inc.x = -1;
  i = -1;
  nchk = NCHUNK(core->win.size, ((sfVector2i){core->opti.chnk_size.x,
				 	      core->opti.chnk_size.y}));
  chunk = (t_chunk){core->opti.chnk_size, ((sfVector2i){0, 0})};
  while (++inc.x <= nchk.x && calc_chunk_x(core, &chunk, inc.x))
    {
      inc.y = -1;
      while (++inc.y <= nchk.y && calc_chunk_y(core, &chunk, inc.y))
	{
	  ++core->opti.length;
	  if (!(*queue = list_pusha(*queue, &node, sizeof(t_queue))) ||
	      set_chunk(node, core, chunk, ++i))
	    return (e_alloc);
	}
    }
  return (0);
}

int		data_construct(t_core *core, t_thread_data *data)
{
  data->in.mtex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
  data->out.mtex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
  data->cond = (pthread_cond_t)PTHREAD_COND_INITIALIZER;
  data->mtex_cond = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
  construct_list(core, (t_queue **)&data->in.data);
  m_printf("%u tasks generated.\n",
	   (core->opti.nb_task = list_length(data->in.data)));
  return (0);
}
