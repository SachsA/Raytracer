/*
** readers_file.c for raytracer1 in /raytracer1/src/parser
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Tue Feb 21 15:37:19 2017 Thomas Lombard
** Last update Sun May 28 11:15:14 2017 Thomas Lombard
*/

#include "header.h"

int	get_hdr(int fd, t_scene *scn)
{
  if (read(fd, &scn->hdr, sizeof(t_scnhdr)) != sizeof(t_scnhdr))
    return (e_hdrCorrupt1);
  if (scn->hdr.magic_nbr != COMPILLER_MAGIC)
    return (e_hdrCorrupt2);
  if (my_strcmp(scn->hdr.tag, COMPILLER_TAG) != 0)
    return (e_hdrCorrupt3);
  return (e_noErr);
}

int	get_objs(int fd, t_scene *scn)
{
  int	i;
  char	texture[1024 + 1];
  t_obj	*tmp;

  i = -1;
  scn->objs = NULL;
  my_memset(texture, 0, 1024 + 1);
  while (++i < scn->hdr.nb_objs)
    {
      if (!(scn->objs = list_pusha(scn->objs, &tmp, sizeof(t_obj))))
	return (e_alloc);
      if (read(fd, &tmp->type, OBJ_SZ) != OBJ_SZ)
	return (e_fileCorrupt1);
      if (tmp->texture_ == 1)
	{
	  read(fd, texture, 1024);
	  if (!(tmp->tex = xcalloc(1, sizeof(t_texture))) ||
	      !(tmp->tex->filename = xstrdup(texture)))
	    return (e_alloc);
	  my_memset(texture, 0, 1024 + 1);
	}
    }
  return (e_noErr);
}

int		get_lights(int fd, t_scene *scn)
{
  int		i;
  t_light	*tmp;
  int		val;

  i = -1;
  scn->lights = NULL;
  while (++i < scn->hdr.nb_lights)
    {
      if (!(scn->lights = list_pusha(scn->lights, &tmp, sizeof(t_light))))
	return (e_alloc);
      if ((val = read(fd, &tmp->pos, LIGHT_SZ)) != LIGHT_SZ)
	return (e_fileCorrupt2);
    }
  return (e_noErr);
}

int		get_camera(int fd, t_scene *scn)
{
  if (read(fd, &scn->ori, sizeof(t_view)) != sizeof(t_view))
    return (e_fileCorrupt3);
  return (e_noErr);
}
