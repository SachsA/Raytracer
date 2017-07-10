/*
** load_1-8bits.c for wolf3d in /home/lombar_e/rendu/Infographie/wolf3d/src/libbmp
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sat Jan 14 17:19:54 2017 Thomas Lombard
** Last update Sat Jan 14 17:23:01 2017 Thomas Lombard
*/

#include "bmp_core.h"

int		fill_1_byte(int *index, t_bitmap *bitmap,
			    t_bit_stream *stream, t_bgra *table)
{
  uint32_t	color;
  int		i;

  color = *((uint8_t *)stream->inc);
  i = -1;
  while (++i < 8)
    {
      bitmap->bitmap[*index].r = table[(color & 0x80) ? 1 : 0].r;
      bitmap->bitmap[*index].g = table[(color & 0x80) ? 1 : 0].g;
      bitmap->bitmap[*index].b = table[(color & 0x80) ? 1 : 0].b;
      bitmap->bitmap[*index].a = table[(color & 0x80) ? 1 : 0].a;
      ++*index;
      color <<= 1;
    }
  ++stream->inc;
  return (7);
}

int		fill_4_byte(int *index, t_bitmap *bitmap,
			    t_bit_stream *stream, t_bgra *table)
{
  uint32_t	color;

  color = *((uint8_t *)stream->inc);
  bitmap->bitmap[*index].r = table[(color >> 4) & 0x0f].r;
  bitmap->bitmap[*index].g = table[(color >> 4) & 0x0f].g;
  bitmap->bitmap[*index].b = table[(color >> 4) & 0x0f].b;
  bitmap->bitmap[*index].a = table[(color >> 4) & 0x0f].a;
  ++*index;
  bitmap->bitmap[*index].r = table[(color & 0x0f)].r;
  bitmap->bitmap[*index].g = table[(color & 0x0f)].g;
  bitmap->bitmap[*index].b = table[(color & 0x0f)].b;
  bitmap->bitmap[*index].a = table[(color & 0x0f)].a;
  ++*index;
  ++stream->inc;
  return (1);
}

int		fill_8_byte(int *index, t_bitmap *bitmap,
			    t_bit_stream *stream, t_bgra *table)
{
  uint32_t	color;

  color = *((uint8_t *)stream->inc);
  bitmap->bitmap[*index].r = table[color].r;
  bitmap->bitmap[*index].g = table[color].g;
  bitmap->bitmap[*index].b = table[color].b;
  bitmap->bitmap[*index].a = table[color].a;
  ++*index;
  ++stream->inc;
  return (0);
}
