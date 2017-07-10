/*
** load_16-32bits.c for wolf3d in /home/lombar_e/rendu/Infographie/wolf3d/src/libbmp
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sat Jan 14 17:21:26 2017 Thomas Lombard
** Last update Sat Jan 14 17:23:30 2017 Thomas Lombard
*/

#include "bmp_core.h"

int		fill_16_byte(int *index, t_bitmap *bitmap,
			     t_bit_stream *stream)
{
  uint32_t	color;

  color = *((uint8_t *)stream->inc);
  bitmap->bitmap[*index].r = ((color >> 10) & 0x1f) << 3;
  bitmap->bitmap[*index].g = ((color >> 5) & 0x1f) << 3;
  bitmap->bitmap[*index].b = (color & 0x1f) << 3;
  bitmap->bitmap[*index].a = 255;
  ++*index;
  stream->inc += 2;
  return (0);
}

int		fill_24_byte(int *index, t_bitmap *bitmap,
			     t_bit_stream *stream)
{
  uint32_t	color;

  color = *((uint32_t *)stream->inc);
  bitmap->bitmap[*index].r = (color >> 16) & 0xff;
  bitmap->bitmap[*index].g = (color >> 8) & 0xff;
  bitmap->bitmap[*index].b = color & 0xff;
  bitmap->bitmap[*index].a = 255;
  ++*index;
  stream->inc += 3;
  return (0);
}

int		fill_32_byte(int *index, t_bitmap *bitmap,
			     t_bit_stream *stream)
{
  uint32_t	color;

  color = *((uint8_t *)stream->inc);
  bitmap->bitmap[*index].r = (color >> 16) & 0xff;
  bitmap->bitmap[*index].g = (color >> 8) & 0xff;
  bitmap->bitmap[*index].b = color & 0xff;
  bitmap->bitmap[*index].a = color >> 24;
  ++*index;
  stream->inc += 4;
  return (0);
}
