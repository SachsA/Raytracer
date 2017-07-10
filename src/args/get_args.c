/*
** get_args.c for clusterv2 in /clusterv2/src/args
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun May 21 11:32:24 2017 Thomas Lombard
** Last update Sun May 28 10:40:58 2017 Thomas Lombard
*/

#include <getopt.h>
#include "header.h"

static struct option	opt[] =
{
  {"help", no_argument, NULL, 'h'},
  {"out-file", required_argument, NULL, 'o'},
  {"of", required_argument, NULL, 'o'},
  {"if", required_argument, NULL, 'f'},
  {"input-file", required_argument, NULL, 'f'},
  {"threads", required_argument, NULL, 't'},
};

static int	check_arg(t_core *core, int idx, t_fnc *fnc, char c)
{
  int		i;

  i = -1;
  if (c == '?')
    {
      arg_error(core->args.av, core->args.av[optind - 1]);
      m_printf("Unrecognised option %s\n", core->args.av[optind - 1]);
      return (1);
    }
  else
    {
      while (fnc[++i].fnc && fnc[i].flag != c);
      if (i < NB_FLAGS && fnc[i].flag && fnc[i].flag == c)
	i = fnc[i].fnc(core, optarg);
      else if (idx < NB_FLAGS && fnc[idx].fnc)
	i = fnc[idx].fnc(core, optarg);
      if (i)
	return (1);
    }
  return (0);
}

int		get_args(t_core *core)
{
  char		c;
  int		idx;
  t_fnc		fnc[NB_FLAGS];

  set_fnc_tab(fnc);
  opterr = 0;
  while ((c = getopt_long(core->args.ac, core->args.av,
			  "hm:s:p:o:", opt, &idx)) > -1)
    {
      if (check_arg(core, idx, fnc, c))
	return (1);
    }
  if (!core->iF && !(core->iF = core->args.av[optind]))
    fnc[0].fnc(core, NULL);
  return (valid_args(core));
}
