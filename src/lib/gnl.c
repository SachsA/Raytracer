/*
** gnl.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "lib/lib.h"

static char	*set_line(char *ret_line, int j, t_gnl *gnl)
{
  char		*ret;
  int		len;

  if (ret_line != 0)
    len = my_strlen(ret_line);
  else
    len = 0;
  if (!(ret = xcalloc((len + j + 1), sizeof(*ret))))
    return (NULL);
  if (ret_line != 0)
    my_strncpy(ret, ret_line, len);
  else
    my_strncpy(ret, "", len);
  ret[len + j] = 0;
  my_strncpy(ret + len, (*gnl).readed + (*gnl).i, j);
  if (ret_line)
    free(ret_line);
  (*gnl).i += (j + 1);
  return (ret);
}

/*
**	get_next_line : Lis une ligne de "fd" et la renvoie
**
**	Arguments :
**		- fd : Le file descripteur à lire
**
**	Valeur de retour :
**		La ligne lue (NULL en cas d'erreur)
**
**	Alias :
**		- gnl(fd) -> get_next_line(fd)
*/
char		*get_next_line(const int fd)
{
  static t_gnl	gnl = {0, 0, ""};
  int		j;
  char		*line;

  line = 0;
  j = 0;
  while (1 == 1)
    {
      if (gnl.pos <= gnl.i)
        {
	  gnl.i = 0;
	  if (!(gnl.pos = read(fd, gnl.readed, READ_SIZE)))
	    return (line);
	  if (gnl.pos == -1)
	    return (NULL);
	  j = 0;
        }
      if (gnl.readed[gnl.i + j] == '\n')
        return (line = set_line(line, j, &gnl));
      if (gnl.i + j == gnl.pos - 1)
        if (!(line = set_line(line, j + 1, &gnl)))
	  return (NULL);
      j++;
    }
}
