/*
** printf__getters.c for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Wed May 05 13:53:50 2017 Thomas Lombard
*/

#include "m_printf.h"

long	printf__get_int64_t(va_list		ap,
			    t_printf_param	param)
{
  long	ret;

  if (param.conv == PRINTF_CONV_L)
    ret = va_arg(ap, long);
#ifdef __LONG_LONG_OK
  else if (param.conv == PRINTF_CONV_LL)
    ret = (long) va_arg(ap, long long);
#endif
  else if (param.conv == PRINTF_CONV_H)
    ret = (long) va_arg(ap, int);
  else if (param.conv == PRINTF_CONV_HH)
    ret = (long) va_arg(ap, int);
  else
    ret = (long) va_arg(ap, int);
  return (ret);
}

unsigned long	printf__get_uint64_t(va_list		ap,
				    t_printf_param	param)
{
  unsigned long	ret;

  if (param.conv == PRINTF_CONV_L)
    ret = va_arg(ap, unsigned long);
#ifdef __LONG_LONG_OK
  else if (param.conv == PRINTF_CONV_LL)
    ret = (unsigned long) va_arg(ap, unsigned long long);
#endif
  else if (param.conv == PRINTF_CONV_H)
    ret = (unsigned long) va_arg(ap, unsigned int);
  else if (param.conv == PRINTF_CONV_HH)
    ret = (unsigned long) va_arg(ap, unsigned int);
  else
    ret = (unsigned long) va_arg(ap, unsigned int);
  return (ret);
}
