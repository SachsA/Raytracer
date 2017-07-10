/*
** strlen.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Thu May 04 00:14:39 2017 Thomas Lombard
*/

/*
**	my_strlen : man strlen
**
**	Arguments :
**		- str  : La chaîne à mesurer
**
**	Valeur de retour :
**		- La longueur de la chaîne
**
**	Alias :
**		- m_strl(str) -> my_strlen(str)
*/
#pragma GCC optimize("0")
int			my_strlen(const char *str)
{
  register const char	*s;

  s = str;
  while (s && *s)
    s++;
  return (s - str);
}
#pragma GCC optimize("1")
