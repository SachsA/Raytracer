/*
** printf__printf.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "m_printf.h"

int		m_printf(const char	*format,
			 ...)
{
  t_printf_out	out;
  va_list	ap;

  out.out = e_write;
  out.fd = 1;
  out.wrote = 0;
  out.print_len = -1;
  va_start(ap, format);
  printf__calc(format, ap, &out);
  va_end(ap);
  return (out.wrote);
}

int		m_fprintf(FILE		*fs,
			  const char	*format,
			  ...)
{
  t_printf_out	out;
  va_list	ap;

  out.out = e_fs;
  out.fs = fs;
  out.wrote = 0;
  out.print_len = -1;
  va_start(ap, format);
  printf__calc(format, ap, &out);
  va_end(ap);
  return (out.wrote);
}

int		m_dprintf(int		fd,
			  const char	*format,
			  ...)
{
  t_printf_out	out;
  va_list	ap;

  out.out = e_fd;
  out.fd = fd;
  out.wrote = 0;
  out.print_len = -1;
  va_start(ap, format);
  printf__calc(format, ap, &out);
  va_end(ap);
  return (out.wrote);
}

int		m_sprintf(char		*str,
			  const char	*format,
			  ...)
{
  t_printf_out	out;
  va_list	ap;

  out.out = e_chain;
  out.chain = str;
  out.wrote = 0;
  out.print_len = -1;
  va_start(ap, format);
  printf__calc(format, ap, &out);
  va_end(ap);
  return (out.wrote);
}

int		m_snprintf(char	*str,
			   size_t	size,
			   const char	*format,
			   ...)
{
  t_printf_out	out;
  va_list	ap;

  out.out = e_chain;
  out.chain = str;
  out.wrote = 0;
  out.print_len = size;
  va_start(ap, format);
  printf__calc(format, ap, &out);
  va_end(ap);
  return (out.wrote);
}
