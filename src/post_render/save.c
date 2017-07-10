/*
** save.c for raytracer2 in /raytracer2/src/post_render
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun May 28 10:05:10 2017 Thomas Lombard
** Last update Sun May 28 10:25:41 2017 Thomas Lombard
*/

#include <SFML/Graphics/Image.h>
#include <time.h>
#include "header.h"

bool		keyevent_save(t_core *c, UNUSED int mode)
{
  char		out[1024 + 1];
  sfImage	*image;
  time_t	t;
  struct tm	tm;

  if (access("out", F_OK))
    mkdir("out", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  my_memset(out, 0, 1025);
  t = time(NULL);
  tm = *localtime(&t);
  m_snprintf(out, 1025, "out/Save_%d-%d-%d %d:%d:%d.png",
	     tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
	     tm.tm_min, tm.tm_sec);
  if (!(image = sfImage_createFromPixels(c->win.size.x, c->win.size.y,
					 (sfUint8 *)c->win.pix.buff)))
    return (1);
  if (!(sfImage_saveToFile(image, out)))
    return (1);
  sfImage_destroy(image);
  m_printf("Image saved %s\n", out);
  return (0);
}
