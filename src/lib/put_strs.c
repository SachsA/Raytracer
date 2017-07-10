/*
** put_strs.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "lib/lib.h"

/*
**	my_putstr : Affiche la chaîne de caractères "str" sur la sortie 1
**
**	Arguments :
**		- str  : La chaîne à afficher
**
**	Valeur de retour :
**		- write(2)
**
**	Alias :
**		- m_puts(str) -> my_putstr(str)
*/

ssize_t		my_putstr(const char *str)
{
  return (write(1, str, my_strlen(str)));
}

/*
**	my_putchar : Affiche le caractère "c" sur la sortie 1
**
**	Arguments :
**		- c  : La caractère à afficher
**
**	Valeur de retour :
**		- write(2)
**
**	Alias :
**		- m_putc(c) -> my_putchar(c)
*/

ssize_t		my_putchar(const char c)
{
  return (write(1, &c, 1));
}

/*
**	my_puterror : Affiche la chaîne de caractères "err" sur la sortie 2
**
**	Arguments :
**		- err  : La chaîne à afficher
**
**	Valeur de retour :
**		- write(2)
**
**	Alias :
**		- m_pute(err) -> my_puterror(err)
*/

ssize_t		my_puterror(const char *err)
{
  return (write(2, err, my_strlen(err)));
}
