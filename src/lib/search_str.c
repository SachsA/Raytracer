/*
** search_str.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

/*
**	find_words : Compte le nombre de mots dans "str"
**
**	Arguments :
**		- str   : La chaîne sur laquelle compter
**		- split : Le séparateur de mots
**
**	Valeur de retour :
**		- Le nombre de mots
**
**	Alias : Pas d'allias
*/

int	find_words(char *str, char split)
{
  int	i;
  int	ret;

  i = 1;
  ret = 1;
  if (!str)
    return (0);
  while (str[i])
    {
      if (str[i] == split);
      else if (str[i] != split && str[i-1] == split)
	ret++;
      i++;
    }
  return (ret);
}
