/*
** set_fnc_tab_from_ip.c for clusterv2 in /clusterv2/src/args
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun May 21 11:12:05 2017 Thomas Lombard
** Last update Sun May 28 10:38:55 2017 Thomas Lombard
*/

#include "header.h"

static int		opt_thread(t_core *core, void *data)
{
  int			thrd;

  if (data)
    thrd = m_getn(data);
  if (data && strisdigit(data) && thrd >= 1 && thrd <= MAX_THREAD)
    {
      core->opti.nb_thrd = thrd;
      return (e_noErr);
    }
  arg_error(core->args.av, data);
  m_dprintf(2, "%s is not a valid thread number. Expected number between %d"
	    " and %d or max\n", data, 1, MAX_THREAD);
  return (e_badArg);
}


void	set_fnc_tab_from_if(t_fnc fnc[NB_FLAGS], int i)
{
  fnc[i + 0].flag = 0;
  fnc[i + 0].fnc = opt_thread;
  fnc[i + 1].flag = 0;
  fnc[i + 1].fnc = 0;
}
