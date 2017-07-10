/*
** memset.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Thu May 04 00:14:14 2017 Thomas Lombard
*/

#include <stdint.h>

/*
**	my_memset : Set la zonne mémoire "ptr" à la valeur de "reset"
**		    jusqu'à ptr[size]. Plus de détails -> man memset
**
**	Arguments :
**		- ptr    : Le pointeur à set
**		- reset  : La valeur à set
**		- size   : La taille de la zonne mémoire
**
**	Valeur de retour :
**		- Le même pointeur que "ptr"
**
**	Alias : Pas d'allias
*/
#pragma GCC optimize("0")
void		*my_memset(void *ptr, char reset, int64_t size)
{
  register char	*pt;

  pt = (char*)ptr;
  --size;
  while (size >= 0)
    {
      pt[size] = reset;
      --size;
    }
  return (ptr);
}
#pragma GCC optimize("1")
