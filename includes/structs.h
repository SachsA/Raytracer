/*
** structs.h for raytracer2 in /home/lombar_e/rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Sun May 28 09:58:47 2017 Thomas Lombard
*/

#ifndef STRUCTS_H_
# define STRUCTS_H_

# include <SFML/Graphics/Font.h>
# include <SFML/Graphics/Text.h>
# include <SFML/Graphics/Types.h>
# include <SFML/Graphics/Color.h>
# include <SFML/System/Vector2.h>
# include <SFML/System/Vector3.h>
# include <SFML/Window/Event.h>
# include <semaphore.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>

# include "config.h"
# include "lib_bmp.h"

# define NCHUNK(s, c) ((sfVector2i){s.x / c.x, s.y / c.y})

typedef struct		s_texture
{
  char			*filename;
  sfVector2u		size;
  sfImage		*texture;
}			t_texture;

typedef struct		s_texturelist
{
  struct s_texturelist	*next;
  struct s_texturelist	*prev;
  t_texture		*texture;
}			t_texturelist;

typedef struct		s_args
{
  int			ac;
  char			**av;
  char			**ev;
}			t_args;

typedef struct		s_my_framebuffer
{
  sfColor		*buff;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_win
{
  sfVector2i		size;
  sfRenderWindow	*win;
  sfTexture		*tex;
  sfSprite		*spr;
  sfEvent		evt;
  sfFont		*font;
  sfText		*text;
  int			text_print;
  t_my_framebuffer	pix;
  t_my_framebuffer	copy;
}			t_win;

/*
**	----------------------------------------
**	              Objects structs
**	----------------------------------------
*/

typedef struct		s_params
{
  double		a;
  double		b;
  double		c;
}			t_params;

typedef enum		e_type
{
  SPHERE = 0,
  PLAN,
  CONE,
  CYLINDER,
  TRIANGLE,
  TOTAL
}			t_type;

# pragma pack(push, 1)
typedef struct		s_scnhdr
{
  uint32_t		magic_nbr;
  char			tag[RD_TAG_LENGTH];
  char			scene_name[RD_NAME_LENGTH];
  int			nb_objs;
  int			nb_lights;
}			t_scnhdr;

typedef struct		s_obj
{
  struct s_obj		*next;
  struct s_obj		*prev;
  t_type                type;
  float			rad;
  float			angle;
  float			flex;
  float			frac;
  sfVector3f		pos;
  sfVector3f		rot;
  sfVector3f		min;
  sfVector3f		max;
  sfColor		color;
  char			texture_;
  t_texture		*tex;
}			t_obj;

typedef struct		s_light
{
  struct s_light	*next;
  struct s_light	*prev;
  sfVector3f		pos;
  sfColor		color;
}			t_light;
# pragma pack(pop)

typedef struct		s_fnptr
{
  sfVector3f		(*norm)(t_obj*, sfVector3f*);
  float			(*impact)(sfVector3f*, sfVector3f*, t_obj*);
}			t_fnptr;

# pragma pack(push, 1)
typedef struct		s_view
{
  sfVector3f		eye;
  sfVector3f		dir;
}			t_view;
# pragma pack(pop)

typedef struct		s_scene
{
  sfVector2i		render_size;
  t_scnhdr		hdr;
  t_view		ori;
  t_view		view;
  t_obj			*objs;
  t_light		*lights;
  t_fnptr		*fn_tab;
}			t_scene;

typedef struct		s_light_calc
{
  sfVector3f		pos;
  sfVector3f		vector;
  sfVector3f		normal;
  sfColor		light;
  sfColor		spec;
}			t_light_calc;

/*
**	----------------------------------------
**	              Opti structs
**	----------------------------------------
*/
typedef struct		s_mutex
{

  pthread_mutex_t	mtex;
  void			*data;
}			t_mutex;

typedef struct		s_thread_data
{
  t_mutex		in;
  t_mutex		out;
  pthread_cond_t	cond;
  pthread_mutex_t	mtex_cond;
}			t_thread_data;

typedef struct		s_queue
{
  struct s_queue	*next;
  struct s_queue	*prev;
  t_my_framebuffer	buff;
  sfVector2i		pos;
  sfVector2i		size;
  sfColor		color;
  int			id;
}			t_queue;

typedef struct		s_chunk
{
  sfVector2i		size;
  sfVector2i		pos;
}			t_chunk;

typedef struct		s_thread
{
  pthread_t		thread;
  int			end;
}			t_thread;

typedef enum		e_connect_mode
{
  no_cluster,
  server,
  client
}			t_connect_mode;

typedef struct		s_client
{
  int			ready;
  int			socket;
  char			*ip;
}			t_client;

typedef struct		s_cluster
{
  t_connect_mode	mode;
  int			size;
  int			socket;
  int			port;
  char			*ip;
  t_client		node[MAX_CLUSTER];
}			t_cluster;

typedef struct		s_opti
{
  int			nb_thrd;
  int			nb_task;
  int			length;
  t_thread_data		data;
  sfVector2i		chnk_size;
  t_scene		*scn;
  t_cluster		cluster;
  t_thread		*threads;
}			t_opti;

/*
**	----------------------------------------
**	              Main structs
**	----------------------------------------
*/

# define NO_EFFECT	(0)
# define GREY_SHADE	(1 << 0)
# define BLU_SHADE	((1 << 1) | GREY_SHADE)
# define GRN_SHADE	((1 << 2) | GREY_SHADE)
# define RED_SHADE	((1 << 3) | GREY_SHADE)
# define SEP_SHADE	((1 << 4) | GREY_SHADE)
# define BLK_WHITE	((1 << 5) | GREY_SHADE)
# define FLIP_X		(1 << 10)
# define FLIP_Y		(1 << 11)
# define FLIP_XY	(FLIP_X | FLIP_Y)
# define INVERT		(1 << 20)

typedef struct		s_option
{
  int			aliasing;
  int			effect;
}			t_option;

typedef struct		s_core
{
  sfVector2i		pos;
  t_args		args;
  t_win			win;
  t_win			printed;
  t_opti		opti;
  t_scene		scene;
  t_option		option;
  t_texturelist		*textures;
  t_my_framebuffer	*save;
  int			json;
  int			norender;
  char			*scene_name;
  char			*iF;
  char			*oF;
}			t_core;

typedef struct		s_eventkey
{
  sfKeyCode		key;
  bool			(*ptr)(t_core *, int);
  int			param;
}			t_eventkey;

typedef struct	s_fnc
{
  char		flag;
  int		(*fnc)(t_core *, void *);
}		t_fnc;

/*
**	----------------------------------------
**	           Args parser structs
**	----------------------------------------
*/
typedef struct		s_opt_func
{
  char			short_[10];
  char			long_[20];
  int			opt_val;
  int			(*fnc)(struct s_core *, int *);
}			t_opt_funcs;

#endif /* ! STRUCTS_H_ */
