/*
** help.c for raytracer2 in /raytracer2/src/post_render
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun May 28 10:44:19 2017 Thomas Lombard
** Last update Sun May 28 20:49:39 2017 Thomas Lombard
*/

#include "header.h"

bool		keyevent_help(UNUSED t_core *c, UNUSED int mode)
{
  m_printf("X---------------------------------------------------------X\n");
  m_printf("|                 Post Render effects Help                |\n");
  m_printf("X---------------------------------------------------------X\n");
  m_printf("|    Key    |      Effect      |       Description        |\n");
  m_printf("X---------------------------------------------------------X\n");
  m_printf("|     A     | Gray Shade       | Shade of white to black  |\n");
  m_printf("|     R     | Red Shade        | Shade of red to black    |\n");
  m_printf("|     G     | Green Shade      | Shade of green to black  |\n");
  m_printf("|     B     | Blue Shade       | Shade of blue to black   |\n");
  m_printf("|     S     | Sepia Shade      | Sepia shade              |\n");
  m_printf("|     W     | White/Black      | White or Black mode      |\n");
  m_printf("|     P     | Pastel           | Oil painting mode        |\n");
  m_printf("|     I     | Invert color     | Inversed colors          |\n");
  m_printf("|     Z     | Flip XY          | Mirror effect to X and Y |\n");
  m_printf("|     X     | Flip X           | Mirror effect to X       |\n");
  m_printf("|     Y     | Flip Y           | Mirror effect to Y       |\n");
  m_printf("|   Space   | Save Image       | Save image with "
	   "'out/Save_YY-MM-DD HH:MM:SS.png' patern\n");
  m_printf("| BackSpace | Reset Image      | Reset image to "
	   "generation output\n");
  m_printf("|     H     | Help             | Display this help        |\n");
  m_printf("X---------------------------------------------------------X\n");
  return (true);
}
