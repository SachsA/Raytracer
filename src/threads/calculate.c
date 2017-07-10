/*
** calculate.c for raytracer2 in /raytracer2/src/threads
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Thu Apr 06 08:34:52 2017 Thomas Lombard
** Last update Jul May 27 15:54:20 2017
*/

#include <pthread.h>
#include "graph.h"
#include "header.h"

static void	set_thread_end(t_thread *threads, int max)
{
  int		i;
  pthread_t	thrd;

  i = -1;
  thrd = pthread_self();
  while (++i < max)
    {
      if (threads[i].thread == thrd)
	threads[i].end = 1;
    }
}

static inline t_queue	*get_next(t_opti *data)
{
  t_queue		*cur;

  cur = NULL;
  pthread_mutex_lock(&data->data.in.mtex);
  if (data->data.in.data)
    {
      cur = data->data.in.data;
      data->data.in.data = cur->next;
    }
  else
    pthread_mutex_unlock(&data->data.in.mtex);
  return (cur);
}

static void	calc_chunk(t_queue *q, t_scene *scn, t_view *save)
{
  sfVector2i	inc;
  sfColor	color;

  inc.x = -1;
  while (++inc.x < q->size.x && inc.x < q->buff.width)
    {
      inc.y = -1;
      while (++inc.y < q->size.y && inc.y < q->buff.height)
	{
	  scn->ori = *save;
	  color = (sfColor){0, 0, 0, 255};
	  calc_dir_vector(scn,
			  (sfVector2i){inc.x + q->pos.x, inc.y + q->pos.y});
	  pixel_calculation(scn, &color, 0);
	  put_pixel(&q->buff, inc.x, inc.y, color);
	}
    }
}

static inline void	init_cur(t_queue *cur, t_opti *data)
{
  cur->next = NULL;
  cur->prev = NULL;
  data->data.out.data = list_push(data->data.out.data, cur);
}

void		*calculate(void *d)
{
  t_view	save;
  t_opti	*data;
  t_queue	*cur;
  t_scene	scene;

  data = d;
  scene = *data->scn;
  save = scene.ori;
  while (1)
    {
      if (!(cur = get_next(data)))
	break ;
      pthread_mutex_unlock(&data->data.in.mtex);
      calc_chunk(cur, &scene, &save);
      pthread_mutex_lock(&data->data.out.mtex);
      pthread_mutex_lock(&data->data.mtex_cond);
      init_cur(cur, data);
      pthread_cond_broadcast(&data->data.cond);
      pthread_mutex_unlock(&data->data.mtex_cond);
      pthread_mutex_unlock(&data->data.out.mtex);
    }
  set_thread_end(data->threads, data->nb_thrd);
  pthread_exit(NULL);
  return (NULL);
}
