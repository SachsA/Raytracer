/*
** strpbrk.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "lib/lib.h"

/*
**	strnpbrk -> renvoie un pointeur sur le premier
**	caractère de s2 dans s1 jusqu'à s1[n]
*/

char			*my_strnpbrk(const char *s1, const char *s2, int n)
{
  register char		*str;
  register char		*allowed;

  str = (char*)s1;
  while (s1 && *str && n)
    {
      allowed = (char*)s2;
      while (s2 && *allowed)
	{
	  if (*str == *allowed)
	    return (str);
	  ++allowed;
	}
      ++str;
      --n;
    }
  return (NULL);
}

/*
**	strnpbrk -> renvoie un pointeur sur le premier
**	caractère de s2 dans s1
*/
char			*my_strpbrk(const char *s1, const char *s2)
{
  register char		*str;
  register char		*allowed;

  str = (char*)s1;
  while (str && *str)
    {
      allowed = (char*)s2;
      while (allowed && *allowed)
	{
	  if (*str == *allowed)
	    return (str);
	  ++allowed;
	}
      ++str;
    }
  return (NULL);
}
