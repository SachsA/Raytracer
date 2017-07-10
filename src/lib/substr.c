/*
** substr.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "lib/lib.h"

/*
**	substr : Duplique une chaîne entre deux points :
**		    - start < 0 : Commence à start caractères de la fin
**		    - start >= 0 : Commence à str[start]
**		    - end < 0 : Finis à end caractères de la fin
**		    - end > 0 : Finis à str[start + end]
**
**	Arguments :
**		- str   : La chaîne à dupliquer
**		- start : Le point de départ
**		- end   : Le point de fin
**
**	Valeur de retour :
**		- Une chaîne allouée contenant le segment entre start et end
**
**	Alias : Pas d'allias
*/

char	*substr(const char *str, int start, int end)
{
  char	*ret;
  int	len;

  end += (end == 0) ? my_strlen(str) : (end < 0) ? my_strlen(str) : 0;
  start += (start < 0) ? my_strlen(str) : 0;
  if (end < 0 || start < 0)
    return (NULL);
  if ((len = end - start) < 0)
    return (NULL);
  if (!(ret = xcalloc(end - start + 1, 1)))
    return (NULL);
  while (len)
    {
      len--;
      ret[len] = str[start + len];
    }
  return (ret);
}
