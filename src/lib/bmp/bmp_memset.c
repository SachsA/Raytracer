/*
** bmp_memset.c for wolf3d in /home/lombar_e/rendu/Infographie/wolf3d/src/libbmp
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed Jan 04 02:14:45 2017 Thomas Lombard
** Last update Wed Jan 04 09:42:43 2017 Thomas Lombard
*/

#include "bmp_core.h"

void		bmp_memset(void *ptr, char reset, int64_t size)
{
  register char	*pt;

  pt = (char*)ptr;
  --size;
  while (size >= 0)
    {
      pt[size] = reset;
      --size;
    }
}
