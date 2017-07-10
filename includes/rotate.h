/*
** rotate.h for Raytracer 1 in /home/MAREST_T/Tech1-Projects/CGraph_Prog/Raytracer1/raytracer1
** 
** Made by Theodore Marestin
** Login   <MAREST_T@epitech.net>
** 
** Started on  Wed Mar 15 19:20:48 2017 Theodore Marestin
** Last update Fri May 12 18:31:21 2017 Theodore Marestin
*/

#ifndef ROTATE_H_
# define ROTATE_H_

# include <SFML/System/Vector3.h>

typedef	struct	s_rotate
{
  float		rot_x[9];
  float		rot_y[9];
  float		rot_z[9];
  float		result[9];
}		t_rotate;

void		init_id_mtx(float *);
void		init_mtx_rotx(float *, sfVector3f);
void		init_mtx_roty(float *, sfVector3f);
void		init_mtx_rotz(float *, sfVector3f);
void		product_matrix(float *, const float *);
sfVector3f	rotate_xyz(sfVector3f, sfVector3f);
sfVector3f	rotate_zyx(sfVector3f, sfVector3f);

#endif /* !ROTATE_H_ */
