/*
** parser.c for raytracer1 in /raytracer1/src/parser
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Feb 19 11:53:12 2017 Thomas Lombard
** Last update Sun May 28 21:10:25 2017 Thomas Lombard
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "lib/lib.h"
#include "header.h"

static int	check_extension(const char *filepath, const char *extension)
{
  int		ext_len;

  if (!filepath || !*filepath)
    return (-1);
  else if (!extension  || !*extension)
    return (-1);
  ext_len = m_strl(extension);
  if (ext_len > m_strl(filepath))
    return (1);
  if (my_strcmp(&filepath[m_strl(filepath) - ext_len], extension) == 0)
    return (0);
  return (1);
}

static int	already_compiled(char *filename, t_scene *scn)
{
  int		fd;
  int		r;

  m_printf("File recognised... Loading ...\n");
  if ((fd = open(filename, O_RDONLY)) < 0)
    return (e_open);
  if ((r = get_hdr(fd, scn)))
    return (r);
  printf("Magic %X\n", scn->hdr.magic_nbr);
  printf("Light %d\n", scn->hdr.nb_lights);
  printf("Obj   %d\n", scn->hdr.nb_objs);
  printf("Name  %s\n", scn->hdr.scene_name);
  printf("Tag   %s\n", scn->hdr.tag);
  if ((r = get_objs(fd, scn)))
    return (r);
  if ((r = get_lights(fd, scn)))
    return (r);
  if ((r = get_camera(fd, scn)))
    return (r);
  print_scene(scn);
  close(fd);
  return (0);
}

#if defined(__INTERFACE__) || defined(__DEBUG__)
int		parser(t_core *core)
{
  int		r;

  m_printf("====\nParsing ... \n\n");
  if (!check_extension(core->iF, DEFAULT_EXTENSION) &&
      !already_compiled(core->iF, &core->scene));
  else if (!(check_extension(core->iF, DEFAULT_EXTENSION)))
    {
      m_dprintf(2, "The file %s is damaged\n", core->iF);
      return (1);
    }
  else if ((r = interface(core->iF, &core->scene)))
    {
      m_dprintf(2, "The file %s is damaged or not supported\n", core->iF);
      return (r);
    }
  m_printf("\nOK\n");
  return (0);
}
#else
int		parser(t_core *core)
{
  m_printf("====\nParsing ... \n\n");
  if (!check_extension(core->iF, DEFAULT_EXTENSION) &&
      !already_compiled(core->iF, &core->scene));
  else if ((check_extension(core->iF, DEFAULT_EXTENSION)))
    {
      m_dprintf(2, "The file %s is damaged or not supported\n", core->iF);
      return (1);
    }
  m_printf("\nOK\n");
  return (0);
}
#endif
