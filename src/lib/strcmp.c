/*
** strcmp.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

/*
**	my_strcmp : man strcmp
**
**	Arguments :
**		- str : La chaîne à comparer
**		- cmp : La chaîne de référence
**
**	Valeur de retour :
**		- 0 si les chaînes sont identiques
**		- La différence entre les 2 chaines dans le cas contraire
**
**	Alias : Pas d'allias
*/

int	my_strcmp(const char *str, const char *cmp)
{
  if (!str || !cmp)
    return ((!str) ? -1 : 1);
  while (*str == *cmp)
    {
      if (*str == '\0')
	return (0);
      str++;
      cmp++;
    }
  return (*str - *cmp);
}

/*
**	my_strncmp : man strncmp
**
**	Arguments :
**		- str : La chaîne à comparer
**		- cmp : La chaîne de référence
**		- n   : La longueur à comparer
**
**	Valeur de retour :
**		- 0 si les chaînes sont identiques
**		- La différence entre les 2 chaines dans le cas contraire
**
**	Alias : Pas d'allias
*/

int	my_strncmp(const char *str, const char *cmp, int n)
{
  if (!str || !cmp)
    return ((!str) ? -1 : 1);
  while (n > 0)
    {
      if (*str != *cmp)
	return (*str - *cmp);
      else if (*str == '\0')
	return (0);
      str++;
      cmp++;
      n--;
    }
  return (0);
}
