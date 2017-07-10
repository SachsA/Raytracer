/*
** print_error.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include <stdlib.h>
#include "m_printf.h"
#include "errors.h"

/*
**	print_error : Affiche une erreur avec un format particlier sur
**		      la sortie d'erreur avec m_vdprintf.
**		      Plus d'infos : man vdprintf
**
**	Arguments :
**		- error : Le format de l'erreur
**		- ...   : Les varables de l'erreur
**
**	Valeur de retour :
**		- Toujours NULL
**
**	Alias : Pas d'allias
*/

void	*print_error(const char *error, ...)
{
  va_list(ap);

  va_start(ap, error);
  m_vdprintf(2, (char*)error, ap);
  va_end(ap);
  return (NULL);
}
