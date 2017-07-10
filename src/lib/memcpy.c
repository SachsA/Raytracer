/*
** memcpy.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Thu May 04 00:14:28 2017 Thomas Lombard
*/

#include "lib/lib.h"

/*
**	my_memcpy : Copie 'n' octets de 'src' dans 'dest'
**
**	Arguments :
**		- dest   : Le pointeur où écrire
**		- src    : Le pointeur à utiliser
**		- n      : La taille de la zonne à écrire
**
**	Valeur de retour :
**		- Le même pointeur que "dest"
**
**	Alias : Pas d'allias
*/
#pragma GCC optimize("0")
void		*my_memcpy(void *dest, const void *src, size_t n)
{
  const char	*s;
  char		*d;

  d = dest;
  s = (char const *)src;
  while (n--)
    *d++ = *s++;
  return (dest);
}
#pragma GCC optimize("1")
