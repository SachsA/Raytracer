/*
** explode.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "header.h"

static int	prepare(char		**str,
			uint32_t	*segments,
			char		***ret,
			char		split)
{
  *str = epur_str(*str);
  *segments = find_words(*str, split);
  *ret = xcalloc(*segments + 1, sizeof(char*));
  return (0);
}

/*
**	explode : Découpe la "chaîne" str avec split comme "séparateur"
**
**	Arguments :
**		- str   : La chaîne à découper
**		- split : Le délimiteur
**
**	Valeur de retour :
**		Le tableau de char * contenant tout les mots de str.
**
**	Alias :
**		- my_str_to_wordtab -> explode
*/

char		**explode(char *str, int8_t split)
{
  char		**ret;
  uint32_t	segments;
  uint32_t	i;
  uint32_t	next;
  uint32_t	key;

  next = key = i = prepare(&str, &segments, &ret, split);
  if (!ret)
    return (NULL);
  while (key < segments && str[i])
    {
      if (str[i] != split)
	{
	  next = match_next(str, split, i);
	  if (!(ret[key] = substr(str, i, next)))
	    return (NULL);
	  i = next;
	  ++key;
	}
      else
	++i;
    }
  ret[key] = NULL;
  return (ret);
}

/*
**	epur_str : 'Epure' les espace de la chaîne "str"
**
**	Arguments :
**		- str : La chaîne à épurer
**
**	Valeur de retour :
**		La même chaine (non réalloué) sans les espaces superflux
**
**	Exemple :
**		- epur_str("     Ceci       est     un \t exemple     ");
**		  -> "Ceci est un exemple"
**
**	Alias : Pas d'allias
*/

char	*epur_str(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (!str)
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  str[j++] = str[i];
	  if (str[i + 1] == ' ' || str[i + 1] == '\t')
	    str[j++] = ' ';
	}
      ++i;
    }
  str[j] = '\0';
  if (str[j - 1] == ' ')
    str[j - 1] = '\0';
  return (str);
}

/*
**	match_next : Renvoie l'index où se situe la prochaine occurence de "c"
**		     dans "str" à partir de "i"
**
**	Arguments :
**		- str : La chaîne dans laquelle chercher.
**		- c   : Le caractère à chercher.
**		- i   : Le point de départ où chercher.
**
**	Valeur de retour :
**		Renvoie l'index de la case où le caractère est trouvé.
**		Sinon renvoie le dernier index de la chaîne.
**
**	Alias : Pas d'allias
*/

int	match_next(char *str, char c, int i)
{
  while (str[i])
    {
      if (str[i] == c)
	return (i);
      ++i;
    }
  return (i);
}
