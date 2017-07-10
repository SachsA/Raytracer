/*
** utils.c for Raytracer 1 in /home/MAREST_T/Tech1-Projects/CGraph_Prog/Raytracer1/raytracer1
** 
** Made by Theodore Marestin
** Login   <MAREST_T@epitech.net>
** 
** Started on  Wed Mar 15 19:19:22 2017 Theodore Marestin
** Last update Sat Mar 18 18:19:44 2017 Theodore Marestin
*/

#include <math.h>
#include <SFML/Graphics.h>

void	init_id_mtx(float *mtx)
{
  int	x;
  int	y;

  y = -1;
  while (++y < 3)
    {
      x = -1;
      while (++x < 3)
	mtx[y * 3 + x] = (x == y);
    }
}

void	init_mtx_rotx(float *rot_x, sfVector3f angles)
{
  init_id_mtx(rot_x);
  rot_x[4] = cosf(-angles.x * M_PI / 180);
  rot_x[5] = -sinf(-angles.x * M_PI / 180);
  rot_x[7] = sinf(-angles.x * M_PI / 180);
  rot_x[8] = cosf(-angles.x * M_PI / 180);
}

void	init_mtx_roty(float *rot_y, sfVector3f angles)
{
  init_id_mtx(rot_y);
  rot_y[0] = cosf(-angles.y * M_PI / 180);
  rot_y[2] = sinf(-angles.y * M_PI / 180);
  rot_y[6] = -sinf(-angles.y * M_PI / 180);
  rot_y[8] = cosf(-angles.y * M_PI / 180);
}

void	init_mtx_rotz(float *rot_z, sfVector3f angles)
{
  init_id_mtx(rot_z);
  rot_z[0] = cosf(-angles.z * M_PI / 180);
  rot_z[1] = -sinf(-angles.z * M_PI / 180);
  rot_z[3] = sinf(-angles.z * M_PI / 180);
  rot_z[4] = cosf(-angles.z * M_PI / 180);
}

void	product_matrix(float *mtx1, const float *mtx2)
{
  float	new_mtx[9];
  int	i;
  int	j;
  int	k;

  i = -1;
  while (++i < 3)
    {
      j = -1;
      while (++j < 3)
	{
	  new_mtx[i * 3 + j] = 0;
	  k = -1;
	  while (++k < 3)
	    new_mtx[i * 3 + j] += mtx1[i * 3 + k] * mtx2[k * 3 + j];
	}
    }
  mtx1[0] = new_mtx[0];
  mtx1[1] = new_mtx[1];
  mtx1[2] = new_mtx[2];
}
