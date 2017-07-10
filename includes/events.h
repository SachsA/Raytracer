/*
** events.h for raytracer2 in /home/MAREST_T/Tech1-Projects/CGraph_Prog/Raytracer/raytracer2
**
** Made by Theodore Marestin
** Login   <MAREST_T@epitech.net>
**
** Started on  Sat May 27 09:00:44 2017 Theodore Marestin
** Last update Sun May 28 17:36:57 2017 Theodore Marestin
*/

#ifndef EVENTS_H_
# define EVENTS_H_

# include <stdbool.h>

# define PASTEL_LEVEL	20
# define PASTEL_RADIUS	5
# define TO_BLU(c)	(c->g = 0, c->r = 0)
# define TO_GRN(c)	(c->b = 0, c->r = 0)
# define TO_RED(c)	(c->g = 0, c->b = 0)

bool	keyevent_shade(t_core *, int);
bool	keyevent_flip(t_core *core, int n);
bool	keyevent_back(t_core *, int);
bool	keyevent_sepia(t_core *, int);
bool	keyevent_invert(t_core *, int);
bool	keyevent_save(t_core *, int);
bool	keyevent_white(t_core *, UNUSED int);
bool	keyevent_pastel(t_core *, UNUSED int);
bool	keyevent_help(UNUSED t_core *c, UNUSED int mode);

#endif /* !EVENTS_H_ */
