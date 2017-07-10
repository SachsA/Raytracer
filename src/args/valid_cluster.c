/*
** valid_cluster.c for clusterv2 in /clusterv2/src/args
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun May 21 11:38:13 2017 Thomas Lombard
** Last update Sun May 21 14:46:08 2017 Thomas Lombard
*/

#include "header.h"

static int	valid_cluster_server(t_cluster *cluster)
{
  if (cluster->size < 2 || cluster->size > MAX_CLUSTER)
    cluster->size = DEFAULT_CLUSTER_SIZE;
  else if (cluster->port < 1000)
    cluster->port = DEFAULT_PORT;
  return (e_noErr);
}

static int	valid_cluster_client(t_cluster *cluster)
{
  if (!cluster->ip)
    {
      m_dprintf(2, "Error, Bad cluster ip\n");
      return (1);
    }
  else if (cluster->port < 1000)
    cluster->port = DEFAULT_PORT;
  return (e_noErr);
}

int		valid_cluster_mode(t_core *core)
{
  t_cluster	*cluster;

  cluster = &core->opti.cluster;
  if (cluster->mode == no_cluster)
    return (0);
  else if (cluster->mode == server)
    return (valid_cluster_server(cluster));
  else if (cluster->mode == client)
    return (valid_cluster_client(cluster));
  return (e_clusterInvalid);
}
