/*
** endian.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include <stdint.h>

extern inline uint8_t	swap_endian_8(uint8_t nb)
{
  return (nb);
}

extern inline uint16_t	swap_endian_16(uint16_t nb)
{
  nb = (((nb << 8) & 0xff00) |
	 ((nb >> 8) & 0x00ff));
  return (nb);
}

extern inline uint32_t	swap_endian_32(uint32_t nb)
{
  nb = (((nb >> 24) & 0x000000ff) |
	 ((nb << 24) & 0xff000000) |
	 ((nb >>  8) & 0x0000ff00) |
	 ((nb <<  8) & 0x00ff0000));
  return (nb);
}

extern inline uint64_t	swap_endian_64(uint64_t nb)
{
  nb = (((nb >> 56) & 0x00000000000000ff) |
	 ((nb << 56) & 0xff00000000000000) |
	 ((nb >> 40) & 0x000000000000ff00) |
	 ((nb << 40) & 0x00ff000000000000) |
	 ((nb >> 24) & 0x0000000000ff0000) |
	 ((nb << 24) & 0x0000ff0000000000) |
	 ((nb >>  8) & 0x00000000ff000000) |
	 ((nb <<  8) & 0x000000ff00000000));
  return (nb);
}
