/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:53:30 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 16:27:31 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

#include "../../libft/mylibft.h"

typedef struct s_cell
{
	char			*key;
	char			*value;
	struct s_cell	*next;
}	t_cell;

typedef struct s_hash_table
{
	size_t	size;
	size_t	count;
	t_cell	**table;
}	t_hash_table;

t_cell			*cell_new(char *key, char *value, t_cell *next);
void			cell_delone(t_cell *cptr);
void			cell_clear(t_cell **cptr);
t_hash_table	*hash_create_table(size_t	size);
void			hash_delete_table(t_hash_table *ht);
size_t			hash_func(t_hash_table *ht, char *key);
t_cell			*hash_search_cell(t_hash_table *ht, char *key, size_t hval);
char			*hash_search_value(t_hash_table *ht, char *key, bool *err);
bool			hash_insert(t_hash_table *ht, char *key, char *value);
bool			hash_delete(t_hash_table *ht, char *key);
bool			hash_is_empty(t_hash_table *ht);
size_t			hash_length(t_hash_table *ht);

//for debug
void	test_hash_func(void);
void	test_cell_func(void);
#endif /* HASH_H */
