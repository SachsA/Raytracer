/*
** set_fnc_tab_from_ip.c for clusterv2 in /clusterv2/src/args
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun May 21 11:12:05 2017 Thomas Lombard
** Last update Sun May 28 10:38:39 2017 Thomas Lombard
*/

#include <arpa/inet.h>
#include "header.h"

static int		opt_out(t_core *core, void *data)
{
  if (strisprint(data))
    {
      core->oF = data;
      return (e_noErr);
    }
  arg_error(core->args.av, data);
  m_dprintf(2, "'%S' is not a valid filename.\n");
  return (e_badArg);
}

static int		opt_if(t_core *core, void *data)
{
  if (data && strisprint(data) && !access(data, R_OK))
    {
      core->iF = data;
      return (e_noErr);
    }
  arg_error(core->args.av, data);
  m_dprintf(2, "'%S' is not a valid or not exists.\n", data);
  return (e_badArg);
}

void	set_fnc_tab_from_ip(t_fnc fnc[NB_FLAGS], int i)
{
  fnc[i + 0].flag = 'o';
  fnc[i + 0].fnc = opt_out;
  fnc[i + 1].flag = 'o';
  fnc[i + 1].fnc = opt_out;
  fnc[i + 2].flag = 'i';
  fnc[i + 2].fnc = opt_if;
  fnc[i + 3].flag = 'i';
  fnc[i + 3].fnc = opt_if;
  set_fnc_tab_from_if(fnc, i + 4);
}
