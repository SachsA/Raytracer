/*
** errors.h for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Thu May 25 21:05:26 2017 Thomas Lombard
*/

#ifndef ERRORS_H_
# define ERRORS_H_

typedef enum	e_error
{
  e_noErr,
  e_alloc,
  e_thread,
  e_arg,
  e_badArg,
  e_clusterInvalid,
  e_open,
  e_pipe,
  e_hdrCorrupt1,
  e_hdrCorrupt2,
  e_hdrCorrupt3,
  e_fileCorrupt1,
  e_fileCorrupt2,
  e_fileCorrupt3,
  e_nbErr
}		t_error;

# define P_ERR(m, e) if (1) {m_printf("\n%s -> %d\n====", m, e); return (e);}

#endif /* ! ERRORS_H_ */
