/*
** generate.c for raytracer2 in /raytracer2/src/post_render
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sat May 27 19:43:06 2017 Thomas Lombard
** Last update Sun May 28 16:42:56 2017 Theodore Marestin
*/

#include <string.h>
#include <SFML/Graphics.h>
#include "structs.h"
#include "graph.h"
#include "events.h"
#include "lib/lib.h"

static const t_eventkey	g_events[] =
{
  {sfKeyA, keyevent_shade, GREY_SHADE},
  {sfKeyR, keyevent_shade, RED_SHADE},
  {sfKeyG, keyevent_shade, GRN_SHADE},
  {sfKeyB, keyevent_shade, BLU_SHADE},
  {sfKeyS, keyevent_shade, SEP_SHADE},
  {sfKeyI, keyevent_invert, INVERT},
  {sfKeyZ, keyevent_flip, FLIP_XY},
  {sfKeyX, keyevent_flip, FLIP_X},
  {sfKeyY, keyevent_flip, FLIP_Y},
  {sfKeySpace, keyevent_save, 0},
  {sfKeyBack, keyevent_back, 0},
  {sfKeyP, keyevent_pastel, 0},
  {sfKeyW, keyevent_white, 0},
  {sfKeyH, keyevent_help, 0},
  {-1, NULL, 0}
};

void	my_window_update(t_core *core)
{
  sfRenderWindow_clear(core->win.win, sfBlack);
  sfTexture_updateFromPixels(core->win.tex, (sfUint8*)core->win.pix.buff,
			     core->win.size.x, core->win.size.y, 0, 0);
  sfRenderWindow_drawSprite(core->win.win, core->win.spr, NULL);
  sfRenderWindow_display(core->win.win);
}

/*
**	Renvoie une sauvegarde du framebuffer donné en paramètre
*/
int	post_render_generate(t_core *core)
{
  int	i;

  if (core->win.evt.key.type != sfEvtKeyPressed)
    return (e_noErr);
  i = -1;
  while (g_events[++i].ptr && core->win.evt.key.code != g_events[i].key);
  if (g_events[i].ptr)
    return (g_events[i].ptr(core, g_events[i].param));
  return (e_noErr);
}

/*
**	my_event loop
*/
int		my_event(t_core *core)
{
  sfEvent	event;

  while (sfRenderWindow_pollEvent(core->win.win, &event))
    {
      if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
	{
	  sfRenderWindow_close(core->win.win);
	  return (0);
	}
    }
  return (1);
}
