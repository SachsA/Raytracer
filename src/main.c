/*
** main.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Sun May 28 09:02:38 2017 Thomas Lombard
*/

#include <SFML/Graphics.h>
#include "graph.h"
#include "header.h"
#include "texture.h"

/*
** Project name : {{PROJECT}}
*/
static int	rt_launch(t_core *core)
{
  int		r;

  if ((r = thread_init(core)))
    return (r);
  if (core->opti.nb_thrd < MIN_THREAD)
    pixel_process(core);
  else
    thread_processing(core);
  return (0);
}

static inline char	*my_pseudo_getenv(char *ev[], char *var)
{
  int			i;

  i = -1;
  while (ev && ev[++i] && my_strncmp(ev[i], var, m_strl(var)));
  return (ev ? ev[i] : NULL);
}

int		main(int ac, char *av[], char *ev[])
{
  t_core	core;
  int		r;

  if (!(my_pseudo_getenv(ev, "DISPLAY")))
    return (0);
  srand(time(NULL));
  if ((r = core_init(&core, ac, av, ev)) && r != -1)
    return (84);
  if (r == -1)
    return (1);
  if (!init_textures(&core.textures, core.scene.objs))
    return (84);
  rt_launch(&core);
  display_loop(&core);
  write_out_image(&core);
  destroy_textures(core.textures);
  core_kill(&core);
  return (0);
}
