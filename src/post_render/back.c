/*
** back.c for raytracer2 in /raytracer2/src/post_render
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sat May 27 17:15:32 2017 Thomas Lombard
** Last update Sun May 28 09:14:55 2017 Thomas Lombard
*/

#include "graph.h"

/*
**	Evenement touche Backspace (remet l'affichage normal)
*/
bool		keyevent_back(t_core *core, UNUSED int n)
{
  post_render_copy(&core->win, 0);
  return (true);
}
