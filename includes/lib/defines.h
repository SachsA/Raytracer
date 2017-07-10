/*
** defines.h for test in /home/lombar_e/lib
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Dec 13 17:57:35 2016 Thomas Lombard
** Last update Jul May 27 19:28:49 2017
*/

#ifndef DEFINES_H_
# define DEFINES_H_

# include <limits.h>

# define READ_SIZE 512
# define UNUSED __attribute__((unused))

# define I_DIGIT	1
# define I_LOWER	1 << 1
# define I_UPPER	1 << 2
# define I_ESCAP	1 << 3
# define I_SPACE	1 << 4
# define I_NEWLN	1 << 5
# define I_PRINT	1 << 6
# define I_SPECL	I_ESCAP | I_NEWLN | I_NEWLN
# define I_ALPHA	I_LOWER | I_UPPER
# define I_ALNUM	I_LOWER | I_UPPER | I_DIGIT
# define I_ALL		INT_MAX
# define DEPTH_MAX	4
# define DIST_TO_PLANE	1000
# define DIR(x)		((x) < 0) ? 1 : -1

#endif
