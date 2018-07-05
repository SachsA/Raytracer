/*
** config.h for raytracer2 in /rendu/Infographie/raytracer2
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Wed May 05 13:53:50 2017 Thomas Lombard
** Last update Thu May 25 21:14:57 2017 Thomas Lombard
*/

#ifndef CONFIG_H_
# define CONFIG_H_

# define DEFAULT_WIDTH	1920
# define DEFAULT_HEIGHT	1080
# define DEFAULT_MODE ((sfVideoMode){WIDTH, HEIGHT, 32})
# define DEFAULT_STYLE (sfClose)
# define DEFAULT_NAME "Raytracer2"
# define DEFAULT_EXTENSION ".rt"
# define DEFAULT_MAX_CLUSTER 16
# define DEFAULT_PORT	1234
# define DEFAULT_CLUSTER_SIZE	4
# define DEFAULT_MAX_THREAD	16
# define DEFAULT_THREAD		4
# define DEFAULT_SAMPLE_DIR	"samples"
# define DEFAULT_FONT_NAME	"space-age.spaceage.otf"
# define DEFAULT_NODE ".node/bin/node"
# define WIN_NAME(val) ((val) ? val : DEFAULT_NAME)
# define RD_TAG_LENGTH	20
# define RD_NAME_LENGTH	512

# define MIN_THREAD		2
# define MIN_ANTIALIASING	2
# define MAX_ANTIALIASING	16
# define TEXT_SIZE		(HEIGHT * 0.02)
# define TEXT_TOP		0
# define TEXT_LEFT		WIDTH * 0.86
# define TEXT_ORIGIN		((sfVector2f){0.5, 0.5})

# ifndef NODEJS_PATH
#  define NODEJS_PATH DEFAULT_NODE
# endif /* ! NODEJS_PATH */

/*
**	----------------------------------------------------
**	                   WINDOW CONFIG
**	----------------------------------------------------
*/
# ifndef WIDTH
#  define WIDTH DEFAULT_WIDTH
# endif /* ! WIDTH */

# ifndef HEIGHT
#  define HEIGHT DEFAULT_HEIGHT
# endif /* ! HEIGHT */

# if HEIGHT >= 900 && WIDTH >= 1600
#  define WIN_STYLE (sfFullscreen)
# else
#  define WIN_STYLE DEFAULT_STYLE
# endif /* ! WIN_MODE */

# ifndef WIN_NAME
#  define WIN_NAME DEFAULT_WINNAME
# endif /* ! WIN_NAME */

# ifndef WIN_MODE
#  define WIN_MODE DEFAULT_MODE
# endif /* ! MODE */

/*
**	----------------------------------------------------
**	                   SAMPLES CONFIG
**	----------------------------------------------------
*/
# ifndef SAMPLE_DIR
#  define SAMPLE_DIR DEFAULT_SAMPLE_DIR
# endif /* ! SAMPLE_DIR */

# ifndef FONT_NAME
#  define FONT_NAME DEFAULT_FONT_NAME
# endif /* ! FONT_NAME */

# ifndef FONT
#  define FONT SAMPLE_DIR "/" FONT_NAME
# endif /* ! FONT */

/*
**	----------------------------------------------------
**	                    THREAD CONFIG
**	----------------------------------------------------
*/
# ifndef MAX_THREAD
#  define MAX_THREAD DEFAULT_MAX_THREAD
# endif /* ! MAX_THREAD */

# ifndef THREAD
#  define THREAD DEFAULT_THREAD
# endif /* ! THREAD */

/*
**	----------------------------------------------------
**	                   CLUSTER CONFIG
**	----------------------------------------------------
*/
# ifndef MAX_CLUSTER
#  define MAX_CLUSTER DEFAULT_MAX_CLUSTER
# endif /* ! MAX_CLUSTER */

# ifndef PORT
#  define PORT DEFAULT_PORT
# endif /* ! PORT */

# ifndef CLUSTER_SIZE
#  define CLUSTER_SIZE DEFAULT_CLUSTER_SIZE
# endif /* ! CLUSTER_SIZE */

# define COMPILLER_TAG "CmPlndjsrt2v3"
# define COMPILLER_MAGIC 0xB16B00B5
# define NB_FLAGS	13

# define RED	"\x1b[31m"
# define GRN	"\x1b[32m"
# define YEL	"\x1b[33m"
# define BLU	"\x1b[34m"
# define MAG	"\x1b[35m"
# define CYN	"\x1b[36m"
# define WHI	"\x1b[37m"
# define NRM	"\x1b[38m"

#endif /* ! CONFIG_H_ */
