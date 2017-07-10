/*
** graph.h for raytracer2 in /Infographie/raytracer2/includes
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed Apr 05 17:34:52 2017 Thomas Lombard
** Last update Sun May 28 09:13:46 2017 Thomas Lombard
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# include <SFML/Graphics.h>
# include <SFML/System.h>
# include <stdio.h>

# ifndef DEFINES_H_
#  include "lib/defines.h"
# endif
# include "config.h"
# include "errors.h"
# include "structs.h"

int	init_window(t_win *, const char *);
int	kill_window(t_win *);

/*
**	-------------------------------------
**	              BASICS
**	-------------------------------------
**	-> pixels/pixel.c
*/
void	put_pixel(t_my_framebuffer *, int, int, sfColor);
void	my_window_update(t_core*);
int	my_event(t_core*);

/*
**	-> pixels/pixel.c
*/
void	pix_blit_(t_my_framebuffer *, t_my_framebuffer *,
		  sfVector2i, sfVector2i);
void	simple_calc(t_core *core);
int	pixel_calculation(t_scene*, sfColor*, int);
int	normalize_vector3f(sfVector3f*);
int	post_render(t_core *core);
int	pixel_process(t_core*);

int	thread_processing(t_core *core);

/*
** SHAPES
*/
sfVector3f	get_normal_triangle(t_obj*, sfVector3f*);
sfVector3f	get_normal_cylinder(t_obj*, sfVector3f*);
sfVector3f	get_normal_sphere(t_obj*, sfVector3f*);
sfVector3f	get_normal_plane(t_obj*, sfVector3f*);
sfVector3f	get_normal_cone(t_obj*, sfVector3f*);
sfVector3f	pixel_impact(t_scene*, double);
double		find_obj(t_scene*, t_obj**);
float		intersect_triangle(sfVector3f*, sfVector3f*, t_obj*);
float		intersect_cylinder(sfVector3f*, sfVector3f*, t_obj*);
float		intersect_sphere(sfVector3f*, sfVector3f*, t_obj*);
float		intersect_plane(sfVector3f*, sfVector3f*, t_obj*);
float		intersect_cone(sfVector3f*, sfVector3f*, t_obj*);
float		delta_pos(float, t_params*);
float		delta_null(t_params*);
int		moves_objs(t_scene*, t_obj*);

/*
** VECTORS
*/
sfVector3f	reflect_vector(t_scene*, sfVector3f*, t_obj*, sfVector3f*);
sfVector3f	rotate_pov(sfVector3f*, sfVector3f*, sfVector3f*);
sfVector3f	calc_vector3f(sfVector3f*, sfVector3f*, int);
sfVector3f	obj_translate(sfVector3f, sfVector3f);
sfVector3f	translate(sfVector3f, sfVector3f);
sfVector3f	inv_vector3f(sfVector3f*);
int		reflect(t_scene*, t_obj*, sfVector3f*);
void		calc_dir_vector(t_scene *restrict, sfVector2i);
sfVector3f	use_vec_sous(sfVector3f, sfVector3f);
sfVector3f	use_cross_product(sfVector3f, sfVector3f);
double		use_dot_product(sfVector3f, sfVector3f);
double		use_inner_product(sfVector3f, sfVector3f);
void		progress_task(t_core*, int, char*);

/*
** LIGHTS
*/
sfColor		update_light(t_scene*, sfColor*, t_obj*, sfVector3f*);
double		cosinus_calc(sfVector3f*, sfVector3f*);
int		find_shadow(t_scene*, sfVector3f*, sfVector3f*, t_obj*);
int		add_effect_color(sfColor*, sfColor*, t_obj*);
int		add_color(t_scene *, sfColor *, sfColor *, double);
int		moves_shadow(sfVector3f*, sfVector3f*, sfVector3f*,
			     sfVector3f*);
int		add_spec_color(t_scene*, t_obj*, t_light*, t_light_calc*);
int		update_spec(sfColor*, sfColor*);

/*
** TEMPORARY FUNCTION
*/
void	fill_list(void *d);

/*
**	output_image
*/
int	write_out_image(t_core *c);

void	post_render_copy(t_win *win, int mode);
int	post_render_generate(t_core *core);
int	display_loop(t_core *core);

#endif /* !GRAPH_H_ */
