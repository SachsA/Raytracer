/*
** main.c for raytracer2 in /home/MAREST_T/Tech1-Projects/CGraph_Prog/Raytracer/raytracer2
** 
** Made by Theodore Marestin
** Login   <MAREST_T@epitech.net>
** 
** Started on  Thu May 25 17:20:21 2017 Theodore Marestin
** Last update Sun May 28 13:58:52 2017 Theodore Marestin
*/

#include <SFML/Graphics/Image.h>
#include <math.h>
#include "graph.h"
#include "texture.h"

static inline float	dot_product(sfVector3f a, sfVector3f b)
{
  return (a.x * b.x + a.y * b.y + a.z * b.z);
}

static sfVector3f	cross_product(sfVector3f a, sfVector3f b)
{
  sfVector3f		new;

  new.x = a.y * b.z - a.z * b.y;
  new.y = a.z * b.x - a.x * b.z;
  new.z = a.x * b.y - a.y * b.x;
  return (new);
}

static void	set_texsphere(sfColor *color, sfVector3f pos, const t_obj *obj)
{
  float		phi;
  float		theta;
  float		u;
  float		v;
  sfVector3f	Ve;
  sfVector3f	Vn;
  sfVector3f	Vp;

  Vn.x = obj->pos.x;
  Vn.y = obj->pos.y + obj->rad;
  Vn.z = obj->pos.z;
  Ve.x = obj->pos.x;
  Ve.y = obj->pos.y;
  Ve.z = obj->pos.z + obj->rad;
  Vn = get_normal_sphere((t_obj *) obj, &Vn);
  Ve = get_normal_sphere((t_obj *) obj, &Ve);
  Vp = get_normal_sphere((t_obj *) obj, &pos);
  phi = acos(-dot_product(Vn, Vp));
  theta = (acos(dot_product(Vp, Ve) / sin(phi))) / (2 * M_PI);
  u = (dot_product(cross_product(Vn, Ve), Vp) > 0) ? 1 - theta : theta;
  v = (phi / M_PI) * obj->tex->size.y;
  *color = sfImage_getPixel(obj->tex->texture, u * obj->tex->size.x, v);
}

static void	set_texplan(sfColor *color, sfVector3f pos, const t_obj *obj)
{
  unsigned int	u;
  unsigned int	v;

  u = abs((unsigned int) pos.x % obj->tex->size.x);
  v = abs((unsigned int) pos.y % obj->tex->size.y);
  *color = sfImage_getPixel(obj->tex->texture, u, v);
}

/*
**	Check si on doit appliquer une texture sur l'objet
**	- return false (0) s'il n'y pas de texture sur l'objet
**	- return true (1) si il y a une texture à appliquer et appelle
**	set_texture pour modifier le obj->color avec les couleurs de la
**	texture pour le pixel en cours de calcul
*/
bool	update_texture(const t_obj *obj, sfColor *color, sfVector3f impact)
{
  if (!obj->tex)
    return (false);
  if (obj->type == SPHERE)
    set_texsphere(color, impact, obj);
  else if (obj->type == PLAN)
    set_texplan(color, impact, obj);
  else
    return (false);
  return (true);
}
