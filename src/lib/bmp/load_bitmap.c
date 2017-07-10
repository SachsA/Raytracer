/*
** load_bitmap.c for wolf3d in /home/lombar_e/rendu/Infographie/wolf3d/src/libbmp
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Tue Jan 03 23:37:31 2017 Thomas Lombard
** Last update Sat Jan 14 17:18:47 2017 Thomas Lombard
*/

#include "bmp_core.h"

static int	check_bits(int *index, t_bit_stream *bits, t_bmp *process)
{
  if (process->hdr_data.bitcount == 1)
    return (fill_1_byte(index, process->bitmap, bits, process->table));
  else if (process->hdr_data.bitcount == 4)
    return (fill_4_byte(index, process->bitmap, bits, process->table));
  else if (process->hdr_data.bitcount == 8)
    return (fill_8_byte(index, process->bitmap, bits, process->table));
  else if (process->hdr_data.bitcount == 16)
    return (fill_16_byte(index, process->bitmap, bits));
  else if (process->hdr_data.bitcount == 24)
    return (fill_24_byte(index, process->bitmap, bits));
  else if (process->hdr_data.bitcount == 32)
    return (fill_32_byte(index, process->bitmap, bits));
  return (-1);
}

int		parser_bitmap(int fd, t_bmp *process)
{
  t_bit_stream	*stream;
  t_bitmap	*bitmap;
  t_size	inc;
  int		index;

  index = 0;
  bitmap = process->bitmap;
  stream = &process->stream;
  inc.y = 0;
  while (inc.y < bitmap->height)
    {
      if (read(fd, stream->line, stream->len) != stream->len)
	return (1);
      stream->inc = stream->line;
      inc.x = 0;
      while (inc.x < bitmap->width)
	{
	  inc.x += check_bits(&index, stream, process);
	  ++inc.x;
	}
      ++inc.y;
    }
  return (0);
}
