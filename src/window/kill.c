/*
** kill.c for raytracer2 in /raytracer2/src/window
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed Apr 05 17:27:26 2017 Thomas Lombard
** Last update Fri May 26 14:54:21 2017 Theodore Marestin
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "lib/lib.h"
#include "structs.h"

int	kill_window(t_win *win)
{
  m_printf("====\nKilling Window...\n");
  if (win->spr)
    sfSprite_destroy(win->spr);
  if (win->tex)
    sfTexture_destroy(win->tex);
  if (win->win)
    sfRenderWindow_destroy(win->win);
  if (win->pix.buff)
    free(win->pix.buff);
  my_memset(win, 0, sizeof(t_win));
  m_printf("OK\n");
  return (0);
}
