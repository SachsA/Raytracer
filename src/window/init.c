/*
** init.c for raytracer2 in /raytracer2/src/window
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed Apr 05 17:05:22 2017 Thomas Lombard
** Last update Tue May 23 16:48:28 2017 Thomas Lombard
*/

#include <SFML/Graphics.h>

#include "lib/lib.h"
#include "graph.h"

static int	init_text(t_win *w)
{
  if (!(w->font = sfFont_createFromFile(FONT)) ||
      !(w->text = sfText_create()))
    return (1);
  sfText_setFont(w->text, w->font);
  sfText_setCharacterSize(w->text, TEXT_SIZE);
  sfText_setColor(w->text, sfColor_fromRGB(255, 0, 0));
  sfText_setPosition(w->text, (sfVector2f){TEXT_LEFT, TEXT_TOP});
  return (0);
}

int		init_window(t_win *w, const char *wname)
{
  sfVideoMode	mode;

  mode = WIN_MODE;
  w->size = (sfVector2i){mode.width, mode.height};
  w->win = sfRenderWindow_create(mode, WIN_NAME(wname), WIN_STYLE, NULL);
  sfRenderWindow_setActive(w->win, sfFalse);
  w->spr = sfSprite_create();
  w->tex = sfTexture_create(mode.width, mode.height);
  w->pix.width = mode.width;
  w->pix.height = mode.height;
  w->pix.buff = xcalloc(mode.width * mode.height, sizeof(sfColor));
  if (!w->win || !w->tex || !w->spr || !w->pix.buff)
    return (1);
  sfSprite_setTexture(w->spr, w->tex, sfTrue);
  sfRenderWindow_clear(w->win, sfBlack);
  return (init_text(w));
}
