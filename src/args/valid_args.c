/*
** valid_args.c for clusterv2 in /clusterv2/src/args
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun May 21 11:36:40 2017 Thomas Lombard
** Last update Sun May 21 16:43:37 2017 Thomas Lombard
*/

#include "header.h"

int	valid_args(t_core *core)
{
  if (!core->iF)
    return (1);
  if (valid_cluster_mode(core))
    return (1);
  print_args_status(core);
  return (e_noErr);
}
