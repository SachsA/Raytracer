/*
** interface.c for raytracer1 in /raytracer1/src/parser
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Tue Feb 21 16:08:56 2017 Thomas Lombard
** Last update Sun Jun 25 12:25:39 2017 Thomas Lombard
*/

#include <sys/types.h>
#include <sys/wait.h>

#include "header.h"

static void	exec_node(int	p[2],
			  char	*filename)
{
  dup2(p[1], 1);
  execl(NODEJS_PATH, "nodejs", "sofy.js",
	filename, "-l", "no", NULL);
  perror("execl");
  exit(2);
}

static int	parse_interfaced(int fd, t_scene *scn)
{
  int		r;

  if ((r = get_hdr(fd, scn)))
    return (r);
  m_printf("live mode hdr_ok\n");
  if ((r = get_objs(fd, scn)))
    return (r);
  m_printf("live mode obj_ok\n");
  if ((r = get_lights(fd, scn)))
    return (r);
  m_printf("live mode lght_ok\n");
  if ((r = get_camera(fd, scn)))
    return (r);
  m_printf("live mode cam_ok\n");
  close(fd);
  return (0);
}

int		interface(char *filename, t_scene *scn)
{
  int		p[2];
  pid_t		pid;
  int		status;

  m_printf("File not compiled... Loading with Sofy\n");
  if (pipe(p) < 0)
    return (-1);
  if ((pid = fork()) < 0)
    return (-1);
  if (pid == 0)
    exec_node(p, filename);
  else
    {
      waitpid(pid, &status, 0);
      if (WEXITSTATUS(status) != 0)
	return (-2);
      else
	parse_interfaced(p[0], scn);
    }
  print_scene(scn);
  return (0);
}
