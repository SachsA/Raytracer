/*
** strcpy.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

/*
**	my_strcpy : man strcpy
**
**	Arguments :
**		- dest : La chaîne dans laquelle copier
**		- str  : La chaîne à copier
**
**	Valeur de retour :
**		- dest
**
**	Alias : Pas d'allias
*/

char	*my_strcpy(char *dest, const char *str)
{
  register char *const	d = dest;

  while (dest && str && *str)
    *dest++ = *str++;
  *dest = 0;
  return (d);
}

/*
**	my_strncpy : man strncpy
**
**	Arguments :
**		- dest : La chaîne dans laquelle copier
**		- str  : La chaîne à copier
**		- n    : Le nombre de caractères à copier
**
**	Valeur de retour :
**		- dest
**
**	Alias : Pas d'allias
*/

char	*my_strncpy(char *dest, const char *str, int n)
{
  register char *const	d = dest;

  while (dest && str && n > 0 && *str && n--)
    *dest++ = *str++;
  while (n > 0 && n--)
    *dest++ = 0;
  return (d);
}
