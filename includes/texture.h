/*
** texture.h for raytracer2 in /home/MAREST_T/Tech1-Projects/CGraph_Prog/Raytracer/raytracer2
** 
** Made by Theodore Marestin
** Login   <MAREST_T@epitech.net>
** 
** Started on  Thu May 25 17:18:47 2017 Theodore Marestin
** Last update Fri May 26 18:01:17 2017 Theodore Marestin
*/

#ifndef TEXTURE_H_
# define TEXTURE_H_

# include <stdbool.h>
# include "structs.h"

# define TEXTURES_DIR		"samples/textures/"
# define GETCOORDS(T, X, Y)	((T)->bitmap[(T)->width * (Y) + (X)])

bool	init_textures(t_texturelist **, t_obj *);
bool	update_texture(const t_obj *, sfColor *, sfVector3f);
void	destroy_textures(t_texturelist *);

#endif /* !TEXTURE_H_ */
