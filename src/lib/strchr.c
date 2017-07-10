/*
** strchr.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "lib/lib.h"

/*
**	my_strchr : Cherche la première occurence de 'c' dans 'str',
**		    et renvoie son pointeur. Plus d'infos : man strchr
**
**	Arguments :
**		- str : La chaîne dans laquelle chercher
**		- c   : Le caractère à chercher
**
**	Valeur de retour :
**		- Le pointeur vers le caractère trouvée.
**		  NULL dans le cas contraire
**
**	Alias : Pas d'allias
*/
char	*my_strchr(const char *str, int c)
{
  if (!str || !*str)
    return (NULL);
  while (*str && *str != (char)c)
    ++str;
  if (*str == (char)c)
    return ((char *)str);
  return (NULL);
}

/*
**	my_strrchr : Cherche la dernière occurence de 'c' dans 'str',
**		     et renvoie son pointeur. Plus d'infos : man strrchr
**
**	Arguments :
**		- str : La chaîne dans laquelle chercher
**		- c   : Le caractère à chercher
**
**	Valeur de retour :
**		- Le pointeur vers le caractère trouvée.
**		  NULL dans le cas contraire
**
**	Alias : Pas d'allias
*/
char		*my_strrchr(const char *str, int c)
{
  register char *s;

  if (!str || !*str)
    return (NULL);
  s = (char *)str + m_strl(str) - 1;
  while (s >= str && *s != (char)c)
    ++s;
  if (*s == (char)c)
    return ((char *)s);
  return (NULL);
}
