/*
** istype.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "lib/defines.h"

/*
**	istype : Donne le type de "c" dans "flag"
**
**	Arguments :
**		- c    : Le char à comparer
**		- flag : Les comparaisons à effectuer
**
**	Valeur de retour :
**		- Le type de caractère trouvé. 0 autrement.
**
**	Exemple :
**		istype('\n', I_SPECL) => I_NEWLN
**	Alias :
**		- isalpha(val) -> istype(val, I_ALPHA)
**		- isdigit(val) -> istype(val, I_DIGIT)
**		- islower(val) -> istype(val, I_LOWER)
**		- isupper(val) -> istype(val, I_UPPER)
**		- isalnum(val) -> istype(val, I_ALNUM)
**		- isprint(val) -> istype(val, I_PRINT)
*/

int	istype(int c, int flag)
{
  int	ret;

  ret = 0;
  if (flag & I_DIGIT)
    ret += (c >= '0' && c <= '9') ? I_DIGIT : 0;
  if (flag & I_LOWER)
    ret += (c >= 'a' && c <= 'z') ? I_LOWER : 0;
  if (flag & I_UPPER)
    ret += (c >= 'A' && c <= 'Z') ? I_UPPER : 0;
  if (flag & I_PRINT)
    ret += (c >= ' ' && c != 127) ? I_PRINT : 0;
  if (flag & I_ESCAP)
    ret += (c == '\a' || c == '\b') ? I_ESCAP : 0;
  if (flag & I_SPACE)
    ret += (c == '\t' || c == ' ' || c == '\v') ? I_SPACE : 0;
  if (flag & I_NEWLN)
    ret += (c == '\n' || c == '\r' || c == '\f') ? I_NEWLN : 0;
  return (ret);
}

/*
**	stristype : Donne les types de caractères dans "str" de manière
**		    stricte, C à D renvoie 0 si un caractère ne corresponds
**		    pas aux flags
**
**	Arguments :
**		- str  : La chaîne à comparer
**		- flag : Les comparaisons à effectuer
**
**	Valeur de retour :
**		- Les types de caractères trouvés. 0 autrement.
**
**	Exemple :
**		stristype("\n", I_SPECL) => I_NEWLN
**	Alias :
**		- strisalpha(val) -> stristype(val, I_ALPHA)
**		- strisdigit(val) -> stristype(val, I_DIGIT)
**		- strislower(val) -> stristype(val, I_LOWER)
**		- strisupper(val) -> stristype(val, I_UPPER)
**		- strisalnum(val) -> stristype(val, I_ALNUM)
**		- strisprint(val) -> stristype(val, I_PRINT)
*/

int	stristype(char *str, int flag)
{
  int	ret;
  int	m;

  ret = 0;
  if (!str)
    return (0);
  while (str && *str)
    {
      if (!(m = istype(*str, flag)))
	return (0);
      ret += (ret & m) ? 0 : m;
      ++str;
    }
  return (ret);
}
