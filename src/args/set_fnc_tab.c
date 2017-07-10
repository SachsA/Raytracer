/*
** set_fnc_tab.c for clusterv2 in /clusterv2/src/args
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun May 21 09:54:13 2017 Thomas Lombard
** Last update Sun May 28 10:41:49 2017 Thomas Lombard
*/

#include <limits.h>
#include <getopt.h>
#include "header.h"

static int	opt_help(t_core *core, UNUSED void *data)
{
  m_printf("SYNOPSIS :\n");
  m_printf("\t%s file.rt\n", core->args.av[0]);
  m_printf("\t%s --thread 4 file.rt\n", core->args.av[0]);
  m_printf("DESCRIPTION :\n");
  m_printf("\t--out-file | --of\n");
  m_printf("\t\tDetermine the raytracer create file after processing.\n");
  m_printf("\t--input-file | --if\n");
  m_printf("\t\tDetermine the input file to use.\n");
  m_printf("\t--threads\n");
  m_printf("\t\tDetermine the number of threads to use.\n");
  return (-1);
}

void	set_fnc_tab(t_fnc fnc[NB_FLAGS])
{
  fnc[0].flag = 'h';
  fnc[0].fnc = opt_help;
  set_fnc_tab_from_ip(fnc, 1);
}
