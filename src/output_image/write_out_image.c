/*
** write_out_image.c for raytracer in /raytracer/src/output_image
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Tue May 23 19:38:31 2017 Thomas Lombard
** Last update Tue May 23 23:31:09 2017 Thomas Lombard
*/

#include <SFML/Graphics/Image.h>
#include "header.h"

int		write_out_image(t_core *c)
{
  sfImage	*image;

  if (!c->oF)
    return (0);
  if (!(image = sfImage_createFromPixels(c->win.size.x, c->win.size.y,
					 (sfUint8 *)c->win.pix.buff)))
    return (1);
  if (!(sfImage_saveToFile(image, c->oF)))
    return (1);
  sfImage_destroy(image);
  return (0);
}
