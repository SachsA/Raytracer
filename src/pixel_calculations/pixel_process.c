/*
** pixel_process.c for Raytracer2 in /home/invicta/raytracer2/src/main_loop/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Mon Apr 10 16:00:02 2017 Kellian CIPIERRE
** Last update Sun May 28 09:04:08 2017 Thomas Lombard
*/

#include <SFML/Graphics.h>
#include "structs.h"
#include "lib/lib.h"
#include "graph.h"

static sfColor	update_reflection(t_scene *scene, t_obj *obj,
				  sfVector3f *impact, int depth)
{
  sfColor	reflec;

  reflec = (sfColor){0, 0, 0, 255};
  reflect(scene, obj, impact);
  pixel_calculation(scene, &reflec, depth + 1);
  return (reflec);
}

int     	pixel_calculation(t_scene *scene, sfColor *color, int depth)
{
  sfColor	reflec;
  sfColor	spec;
  t_obj		*obj;
  sfVector3f	impact;
  double	dist;

  reflec = (sfColor){0, 0, 0, 255};
  if (scene->objs == NULL)
    return (0);
  dist = find_obj(scene, &obj);
  moves_objs(scene, obj);
  if (dist < 0 || obj == NULL)
    return (0);
  // impact = pixel_impact(scene, dist - 0.01 * (depth + 1));
  impact = pixel_impact(scene, dist * 0.995);
  spec = update_light(scene, color, obj, &impact);
  if (depth < DEPTH_MAX && obj->flex > 0)
    reflec = update_reflection(scene, obj, &impact, depth);
  add_effect_color(color, &reflec, obj);
  update_spec(color, &spec);
  return (0);
}

static void	calc_chunk(t_core *core, t_queue **t, sfVector3f *eye_save,
			   sfVector3f *dir_save)
{
  t_queue	*task;
  sfVector2i	inc;
  sfColor	color;

  task = *t;
  inc.y = -1;
  core->pos.y = task->pos.y;
  while (++inc.y < task->size.y && core->pos.y < core->win.size.y)
    {
      inc.x = -1;
      core->pos.x = task->pos.x;
      while (++inc.x < task->size.x && core->pos.x < core->win.size.x)
	{
	  core->scene.ori.dir = *dir_save;
	  core->scene.ori.eye = *eye_save;
	  color = (sfColor){0, 0, 0, 255};
	  calc_dir_vector(&core->scene, core->pos);
	  pixel_calculation(&core->scene, &color, 0);
	  put_pixel(&core->win.pix, core->pos.x, core->pos.y, color);
	  ++core->pos.x;
	}
      ++core->pos.y;
    }
  *t = task->next;
  return ;
}

/*
**	Pixel process ->
**
**		Execute chacune des tâches contenue dans core->opti.data.in
**		et affiche leur résultat;
**
*/
int		pixel_process(t_core *core)
{
  sfVector3f	eye_save;
  sfVector3f	dir_save;
  t_queue	*task;
  char		progress[1024 + 1];

  core->scene.ori.dir = (sfVector3f){0, 0, 0};
  eye_save = core->scene.ori.eye;
  dir_save = core->scene.ori.dir;
  task = core->opti.data.in.data;
  while (task && sfRenderWindow_isOpen(core->win.win))
    {
      calc_chunk(core, &task, &eye_save, &dir_save);
      my_event(core);
      sfRenderWindow_clear(core->win.win, sfBlack);
      sfTexture_updateFromPixels(core->win.tex, (sfUint8*)core->win.pix.buff,
				 core->win.size.x, core->win.size.y, 0, 0);
      sfRenderWindow_drawSprite(core->win.win, core->win.spr, NULL);
      progress_task(core, --core->opti.length, progress);
      sfRenderWindow_display(core->win.win);
      my_memset(progress, 0, m_strl(progress));
    }
  display_loop(core);
  return (0);
}
