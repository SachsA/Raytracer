/*
** arg_error.c for clusterv2 in /clusterv2/src/args
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun May 21 10:33:03 2017 Thomas Lombard
** Last update Sun May 21 11:47:00 2017 Thomas Lombard
*/

#include "header.h"

static int	print_opt_string(char *args[])
{
  int		i;

  i = -1;
  while (args[++i])
    {
      m_pute(args[i]);
      if (args[i + 1])
	m_pute(" ");
    }
  m_pute("\n");
  return (e_noErr);
}

static int	set_cursor(char *av[], char *str)
{
  int		i;
  int		j;

  i = -1;
  while (av[++i] < str)
    {
      j = -1;
      while (av[i][++j])
	m_pute(" ");
      m_pute(" ");
    }
  m_pute("\033[32m^");
  i = 0;
  while (str[++i] && str[i + 1])
    m_pute(".");
  m_pute("^\033[m\n");
  return (e_noErr);
}

void		arg_error(char *args[], char *arg)
{
  m_dprintf(2, "On your format string :\n");
  print_opt_string(args);
  set_cursor(args, arg);
}
