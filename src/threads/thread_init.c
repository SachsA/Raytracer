/*
** thread_init.c for Raytracer2 in /home/invicta/raytracer2/src/threads/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Sat May 27 15:44:45 2017 Kellian CIPIERRE
** Last update Jul May 27 15:53:07 2017
*/

#include <pthread.h>
#include "graph.h"
#include "header.h"


int		thread_init(t_core *core)
{
  int		i;

  data_construct(core, &core->opti.data);
  if (core->opti.nb_thrd < MIN_THREAD)
    return (0);
  i = -1;
  pthread_mutex_lock(&core->opti.data.in.mtex);
  if (!(core->opti.threads = xcalloc(core->opti.nb_thrd, sizeof(t_thread))))
    return (e_alloc);
  while (++i < core->opti.nb_thrd)
    {
      if (pthread_create(&core->opti.threads[i].thread, NULL,
			 calculate, &core->opti))
	return (e_thread);
    }
  m_printf("thread init successfully\n");
  return (0);
}
