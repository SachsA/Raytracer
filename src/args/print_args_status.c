/*
** print_args_status.c for clusterv2 in /clusterv2/src/args
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun May 21 11:50:38 2017 Thomas Lombard
** Last update Sun May 28 10:33:01 2017 Thomas Lombard
*/

#include "header.h"

static void	print_core(t_core *core)
{
  char		*extension;

  m_printf("----\n\t:::Raytracer:::\n");
  m_printf("Input file : %s\n", core->iF);
  m_printf("Output file : %s\n", (core->oF) ? core->oF : "");
  if (core->oF && (extension = my_strrchr(core->oF, '.')))
    m_printf("Output Extension : %s\n", extension);
  m_printf("Output type :");
  if (core->json)
    m_printf(" Json");
  if (!core->json && core->oF)
    m_printf(" Image");
  if (!core->json && !core->norender)
    m_printf(" Render");
}

static void	print_render(t_core *core)
{
  m_printf("\n-- Rendering options --\n");
  m_printf("Antialiasing : ");
  if (core->option.aliasing)
    m_printf("Enabled -> %dx\n", core->option.aliasing);
  else
    m_printf("Disabled\n");
  m_printf("Effecs : ");
  if (core->option.effect == 0)
    m_printf("Disabled\n");
  if (core->option.effect & GREY_SHADE)
    {
      m_printf("Monochrome -> ");
      if (core->option.effect & SEP_SHADE)
	m_printf("Sepia\n");
      else
	m_printf("Black and white\n");
    }
}

void	print_args_status(t_core *core)
{
  print_core(core);
  print_render(core);
}
