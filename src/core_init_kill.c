/*
** core_init-kill.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Sat May 27 19:16:08 2017 Thomas Lombard
*/

#include "header.h"
#include "graph.h"
#include "structs.h"

static void    	init_fn_tab(t_core *core)
{
  if ((core->scene.fn_tab = malloc(sizeof(t_core) * TOTAL)) == NULL)
    return ;
  core->scene.fn_tab[SPHERE].impact = &intersect_sphere;
  core->scene.fn_tab[SPHERE].norm = &get_normal_sphere;
  core->scene.fn_tab[CONE].impact = &intersect_cone;
  core->scene.fn_tab[CONE].norm = &get_normal_cone;
  core->scene.fn_tab[CYLINDER].impact = &intersect_cylinder;
  core->scene.fn_tab[CYLINDER].norm = &get_normal_cylinder;
  core->scene.fn_tab[PLAN].impact = &intersect_plane;
  core->scene.fn_tab[PLAN].norm = &get_normal_plane;
  core->scene.fn_tab[TRIANGLE].impact = &intersect_triangle;
  core->scene.fn_tab[TRIANGLE].norm = &get_normal_triangle;
}

int		core_init(t_core *core, int ac, char **av, char **ev)
{
  int		r;

  my_memset(core, 0, sizeof(t_core));
  core->args = (t_args){ac, av, ev};
  core->opti.chnk_size = (sfVector2i){64, 64};
  core->opti.scn = &core->scene;
  core->win.size = (sfVector2i){WIDTH, HEIGHT};
  init_fn_tab(core);
  if ((r = get_args(core)))
    return (r);
  if ((r = parser(core)))
    P_ERR("FAIL->", r);
  m_printf("====\n\n====\nWindow ... ");
  if ((r = init_window(&core->win, NULL)))
    P_ERR("FAIL->", r);
  core->scene.render_size = core->win.size;
  m_printf("\nOK\n====\n");
  return (e_noErr);
}

int		core_kill(t_core *core)
{
  kill_window(&core->win);
  destruct_scene(&core->scene);
  return (e_noErr);
}
