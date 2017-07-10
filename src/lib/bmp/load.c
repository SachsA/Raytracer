/*
** load.c for wolf3d in /home/lombar_e/rendu/Infographie/wolf3d/src/libbmp
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Tue Jan 03 11:15:17 2017 Thomas Lombard
** Last update Fri May 26 05:21:35 2017 Theodore Marestin
*/

#include <stdio.h>
#include <string.h>
#include "bmp_core.h"

t_bitmap	*load_bmp_file(const char *filename)
{
  t_bmp		bmp;
  int		fd;

  bmp_memset(&bmp, 0, sizeof(t_bmp));
  bmp.bitmap = bmp_calloc(1, sizeof(t_bitmap));
  if (!filename ||!*filename)
    return (NULL);
  if ((fd = open(filename, O_RDONLY)) < 0)
    return (NULL);
  if (parser_init(fd, &bmp))
    return (NULL);
  if (bmp.hdr_data.compression != 0)
    return (NULL);
  if (parser_bitmap(fd, &bmp))
    return (NULL);
  if (close(fd))
    return (NULL);
  return (bmp.bitmap);
}
