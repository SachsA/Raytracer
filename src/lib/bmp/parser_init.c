/*
** parser_init.c for wolf3d in /home/lombar_e/rendu/Infographie/wolf3d/src/libbmp
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Tue Jan 03 17:07:15 2017 Thomas Lombard
** Last update Sat Jan 14 16:45:56 2017 Thomas Lombard
*/

#include "bmp_core.h"

static int	get_headers(int fd, t_bmp *core)
{
  int		size;
  if (read(fd, &core->hdr_file, S_FHBMP) != S_FHBMP)
    return (E_FILESYNTAX);
  if (core->hdr_file.signature != SIGN_SUPPORT)
    return (E_FILESYNTAX);
  if (read(fd, &core->hdr_data.headersize, S_UINT) != S_UINT)
    return (E_FILESYNTAX);
  size = core->hdr_data.headersize - S_UINT;
  if (read(fd, &core->hdr_data.width, size) != size)
    return (E_FILESYNTAX);
  return (0);
}

static int	color_table(int fd, t_bmp *core)
{
  int		tabl;

  tabl = 0;
  if (core->hdr_data.bitcount == 1)
    tabl = 2;
  else if (core->hdr_data.bitcount == 4)
    tabl = 16;
  else if (core->hdr_data.bitcount == 8)
    tabl = 256;
  else
    return (0);
  if (!(core->table = bmp_calloc(tabl, sizeof(t_bgra))))
    return (E_FILESYNTAX);
  tabl = S_BRGA * core->hdr_data.clrused;
  if (read(fd, core->table, tabl) != tabl)
    return (E_FILESYNTAX);
  return (0);
}

static int	get_bitmap(t_bmp *core)
{
  t_bitmap	*bitmap;
  t_bit_stream	*stream;

  bitmap = core->bitmap;
  stream = &core->stream;
  bitmap->width = abs(core->hdr_data.width);
  bitmap->height = abs(core->hdr_data.height);
  if (!(bitmap->bitmap = bmp_calloc(bitmap->width * bitmap->height,
				 sizeof(t_rgba))))
    return (E_MALLOC);
  stream->len = ((bitmap->width * core->hdr_data.bitcount / 8) + 3) & ~3;
  if (!(stream->line = bmp_calloc(stream->len, sizeof(int))))
    return (E_MALLOC);
  return (0);
}

int	parser_init(int fd, t_bmp *process)
{
  int	err;

  if ((err = get_headers(fd, process)))
    return (err);
  if ((err = color_table(fd, process)))
    return (err);
  if ((err = get_bitmap(process)))
    return (err);
  return (0);
}
