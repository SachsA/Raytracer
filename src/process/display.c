/*
** display.c for raytracer2 in /raytracer2/src/process
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Thu Apr 13 23:00:33 2017 Thomas Lombard
** Last update Sun May 28 09:17:06 2017 Thomas Lombard
*/

#include "lib/lib.h"
#include "graph.h"

int	display_loop(t_core *core)
{
  core->win.copy = core->win.pix;
  if (!(core->win.copy.buff =
	xcalloc(core->win.size.x * core->win.size.y, sizeof(sfColor))))
    return (1);
  post_render_copy(&core->win, 1);
  while (sfRenderWindow_isOpen(core->win.win))
    {
      while (sfRenderWindow_pollEvent(core->win.win, &core->win.evt))
	{
	  if (core->win.evt.type == sfEvtClosed ||
	      core->win.evt.key.code == sfKeyEscape)
	    sfRenderWindow_close(core->win.win);
	  post_render_generate(core);
	}
      sfRenderWindow_clear(core->win.win, sfBlack);
      sfTexture_updateFromPixels(core->win.tex, (sfUint8 *)core->win.pix.buff,
				 core->win.size.x, core->win.size.y, 0, 0);
      sfRenderWindow_drawSprite(core->win.win, core->win.spr, NULL);
      sfRenderWindow_display(core->win.win);
    }
  return (0);
}
