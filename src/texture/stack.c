/*
** stack.c for raytracer2 in /home/MAREST_T/Tech1-Projects/CGraph_Prog/Raytracer/raytracer2
**
** Made by Theodore Marestin
** Login   <MAREST_T@epitech.net>
**
** Started on  Fri May 26 16:53:11 2017 Theodore Marestin
** Last update Jul May 27 18:47:37 2017
*/

#include <SFML/Graphics.h>
#include "graph.h"
#include "lib/lib.h"
#include "lib/list.h"
#include "texture.h"

/*
**      Equivalent à strcat + strdup -> Récupère le path complet de
**      la texture à charger
*/
static char	*get_filename(const char *filename)
{
  char		*new;
  size_t	i;
  size_t	j;

  new = malloc(sizeof(char) *
	       (my_strlen(filename) + my_strlen(TEXTURES_DIR) + 1));
  if (!new)
    return (NULL);
  i = 0;
  while (TEXTURES_DIR[i] != '\0')
    {
      new[i] = TEXTURES_DIR[i];
      ++i;
    }
  j = 0;
  while (filename[j] != '\0')
    {
      new[i + j] = filename[j];
      ++j;
    }
  new[i + j] = 0;
  return (new);
}

/*
**      Détruit toutes les textures progressivement
*/
void		destroy_textures(t_texturelist *list)
{
  t_texturelist	*tmp;

  while (list != NULL)
    {
      tmp = list->next;
      free(list->texture->filename);
      sfImage_destroy(list->texture->texture);
      free(list->texture);
      free(list);
      list = tmp;
    }
}

/*
**      Charge une nouvelle texture et l'ajoute à la texturelist
**	Ensuite relie la texture à l'objet
**      return false(0) en cas d'erreur sinon return true(1)
*/
static bool	load_texture(t_texturelist **list, const t_obj *obj)
{
  char		*filepath;
  t_texturelist	*new;

  *list = list_pusha(*list, &new, sizeof(*new));
  if (!*list || !new)
    return (false);
  filepath = get_filename(obj->tex->filename);
  if (!filepath)
    return (false);
  new->texture = obj->tex;
  new->texture->texture = sfImage_createFromFile(filepath);
  if (!new->texture->texture)
    return (false);
  new->texture->size = sfImage_getSize(new->texture->texture);
  return (true);
}

/*
**      Check si la texture est déjà chargée, sinon appelle load_texture
**	Si elle est déjà chargée, on relie juste l'objet à la texture
**      return false(0) en cas d'erreur sinon return true(1)
*/
static bool	check_texture(t_texturelist **list, t_obj *obj)
{
  t_texturelist	*tmp;

  tmp = *list;
  while (tmp != NULL && my_strcmp(tmp->texture->filename, obj->tex->filename))
    tmp = tmp->next;
  if (tmp)
    {
      m_printf("(already load) ");
      free(obj->tex->filename);
      free(obj->tex);
      obj->tex = tmp->texture;
      return (true);
    }
  if (!load_texture(list, obj))
    return (false);
  return (true);
}

/*
**      Fonction principale qui charge toutes les textures dans texturelist
**	puis place un lien vers la texture pour chaque objet texturé
**	Ne charge pas de doublons (C'est le même lien sur plusieurs objets)
**      return false(0) en cas d'erreur sinon return true(1)
*/
bool	init_textures(t_texturelist **list, t_obj *obj)
{
  m_printf("Loading textures ...\n\n");
  while (obj != NULL)
    {
      if (obj->tex)
	{
	  m_printf("Load [%s] => ", obj->tex->filename);
	  if (!check_texture(list, obj))
	    {
	      m_printf("\033[31;1mFailed\033[m\n");
	      return (false);
	    }
	  m_printf("\033[32;1mSuccess\033[m\n");
	}
      obj = obj->next;
    }
  m_printf("\nOK\n====\n");
  return (true);
}
