/*
** header.h for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Sun May 28 10:39:37 2017 Thomas Lombard
*/

#ifndef HEADER_H_
# define HEADER_H_

# include "config.h"
# include "errors.h"
# include "structs.h"
# include "lib/lib.h"

# define NB_OPTS	4

# define OPT_HELP	(1 << 0)
# define OPT_LIVE	(1 << 1)
# define OPT_COMPILE	(1 << 2)

# define OBJ_SZ		(int32_t)(sizeof(t_obj) - sizeof(char *) * 3)
# define LIGHT_SZ	(int32_t)(sizeof(t_light) - sizeof(t_light *) * 2)

/*
**	INIT / KILL
*/
int	core_init(t_core *, int, char **, char **);
int	core_kill(t_core *);

/*
**	OPT_MANAGE
*/
void	arg_error(char *args[], char *arg);
int	get_args(t_core *core);
void	print_args_status(t_core *core);
void	set_fnc_tab(t_fnc fnc[NB_FLAGS]);
void	set_fnc_tab_from_ip(t_fnc fnc[NB_FLAGS], int i);
void	set_fnc_tab_from_if(t_fnc fnc[NB_FLAGS], int i);
int	valid_args(t_core *core);
int	valid_cluster_mode(t_core *core);

/*
**	PARSER
*/
int	parser(t_core *core);
int	get_hdr(int fd, t_scene *scn);
int	get_objs(int fd, t_scene *scn);
int	get_lights(int	fd, t_scene *scn);
int	get_camera(int fd, t_scene *scn);
int	interface(char *filename, t_scene *scn);
int	destruct_scene(t_scene *scn);
void	print_scene(t_scene *scn);
void	force_kill_threads(t_core *core);
void	*calculate(void*);


/*
**	THREADs
*/
int	thread_init(t_core *core);
int	data_construct(t_core *core, t_thread_data *data);
void	destruct_queue(void *);

#endif /* ! HEADER_H_ */
