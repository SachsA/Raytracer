/*
** list.h for chained in /src/lib/list
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Mon Apr 24 14:22:08 2017 Thomas Lombard
** Last update Fri May 26 15:28:59 2017 Theodore Marestin
*/

#ifndef LIST_H_
# define LIST_H_

# include <stddef.h>
# include <stdint.h>
# include "lib/structs.h"

void	*xcalloc(uint64_t nmemb, uint64_t nsize);
void	my_memset(void *ptr, char reset, int64_t size);

void	*list_pusha(void *, void *, size_t);
void	*list_push(void *, void *);

void	*list_get_first(void *);
void	*list_get_last(void *);
void	*list_get_selector(void *, void *, int (*)(void *, void *));

void	*list_detach_selector(void *, void *, int (*)(void *, void *));
void	*list_detach_last(void *l);
void	*list_detach_first(void *l);
void	*list_detach(void *n);

size_t	list_length(void *);

void	*list_remove(void *, void *);
void	*list_remove_method(void *, void *, void (*)(void *));
void	list_destruct(void *);
void	list_destruct_method(void *, void (*)(void *));

#endif /* ! LIST_H_ */
