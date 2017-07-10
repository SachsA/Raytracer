/*
** strcat.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "lib/lib.h"

/*
**	my_strcat : man strcat
**
**	Arguments :
**		- str : La chaîne contenante
**		- cat : La chaîne à concaténer
**
**	Valeur de retour :
**		- str
**
**	Alias : Pas d'allias
*/

extern inline char	*my_strcat(char		*str,
				   const char	*cat)
{
  str[my_strlen(str) + my_strlen(cat)] = 0;
  my_strcpy(&str[my_strlen(str)], cat);
  return (str);
}

/*
**	my_strncat : man strncat
**
**	Arguments :
**		- str : La chaîne contenante
**		- cat : La chaîne à concaténer
**
**	Valeur de retour :
**		- str
**
**	Alias : Pas d'allias
*/

extern inline char	*my_strncat(char		*str,
				    const char		*cat,
				    size_t		n)
{
  str[my_strlen(str) + n] = 0;
  my_strncpy(&str[my_strlen(str)], cat, n);
  return (str);
}

/*
**	concat : concatène toutes les chaînes données en paramètre jusquà NULL
**
**	Arguments :
**		- str : La première chaîne
**		- ... : Les autres chaînes
**
**	Valeur de retour :
**		- Une chaîne allouée contenant toutes les chaines
**
**	Alias : Pas d'allias
*/

char		*concat(char *str, ...)
{
  va_list	ap;
  va_list	cpy;
  int		len;
  char		*bf;
  char		*ret;

  va_start(ap, str);
  va_copy(cpy, ap);
  len = m_strl(str);
  while ((bf = va_arg(cpy, char *)))
    len += m_strl(bf);
  ret = xcalloc(len + 1, sizeof(char));
  va_end(cpy);
  my_strcat(ret, str);
  while ((bf = va_arg(ap, char *)))
    my_strcat(ret, bf);
  va_end(ap);
  return (ret);
}
