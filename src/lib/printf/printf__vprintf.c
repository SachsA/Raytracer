/*
** printf__vprintf.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "m_printf.h"

int		m_vprintf(const char	*format,
			  va_list	ap)
{
  t_printf_out	out;

  out.out = e_write;
  out.fd = 1;
  out.wrote = 0;
  out.print_len = -1;
  printf__calc(format, ap, &out);
  return (out.wrote);
}

int		m_vfprintf(FILE	*fs,
			   const char	*format,
			   va_list	ap)
{
  t_printf_out	out;

  out.out = e_fs;
  out.fs = fs;
  out.wrote = 0;
  out.print_len = -1;
  printf__calc(format, ap, &out);
  return (out.wrote);
}

int		m_vdprintf(int		fd,
			   const char	*format,
			   va_list	ap)
{
  t_printf_out	out;

  out.out = e_fd;
  out.fd = fd;
  out.wrote = 0;
  out.print_len = -1;
  printf__calc(format, ap, &out);
  return (out.wrote);
}

int		m_vsprintf(char	*str,
			   const char	*format,
			   va_list	ap)
{
  t_printf_out	out;

  out.out = e_chain;
  out.chain = str;
  out.wrote = 0;
  out.print_len = -1;
  printf__calc(format, ap, &out);
  return (out.wrote);
}

int		m_vsnprintf(char	*str,
			    size_t	size,
			    const char	*format,
			    va_list	ap)
{
  t_printf_out	out;

  out.out = e_chain;
  out.chain = str;
  out.wrote = 0;
  out.print_len = size;
  printf__calc(format, ap, &out);
  return (out.wrote);
}
