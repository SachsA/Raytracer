/*
** force_kill.c for raytracer in /raytracer/src/process
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Tue May 23 19:29:57 2017 Thomas Lombard
** Last update Tue May 23 19:32:48 2017 Thomas Lombard
*/

#include <pthread.h>
#include "header.h"

void	force_kill_threads(t_core *core)
{
  int	i;

  i = -1;
  while (++i < core->opti.nb_thrd)
    pthread_cancel(core->opti.threads[i].thread);
}
