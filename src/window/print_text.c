/*
** print_text.c for Raytracer2 in /home/invicta/raytracer2/src/window/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Wed May 24 19:24:23 2017 Kellian CIPIERRE
** Last update Apr May 24 20:33:16 2017
*/

#include "graph.h"

void	progress_task(t_core *core, int nbr, char *progress)
{
  snprintf(progress, 1024 + 1, "Reste %4d / %4d", nbr, core->opti.nb_task);
  sfText_setString(core->win.text, progress);
  sfText_setOrigin(core->win.text, TEXT_ORIGIN);
  sfRenderWindow_drawText(core->win.win, core->win.text, NULL);
}
