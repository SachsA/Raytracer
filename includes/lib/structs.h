/*
** structs.h for test in /home/lombar_e/lib
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Dec 13 17:57:35 2016 Thomas Lombard
** Last update Fri May 26 17:26:14 2017 Theodore Marestin
*/

#ifndef LIB_STRUCT
# define LIB_STRUCT

typedef struct  s_gnl
{
    int     i;
    int     pos;
    char    readed[READ_SIZE];
}               t_gnl;

typedef struct	s_list
{
  struct s_list	*next;
  struct s_list	*prev;
  char		data[0];
}		t_list;

#endif
