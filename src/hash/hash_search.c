/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:48:51 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 16:53:47 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

t_cell	*hash_search_cell(t_hash_table *ht, char *key, size_t hval)
{
	t_cell	*itr;

	itr = ht->table[hval];
	while (itr != NULL)
	{
		if (ft_strcmp(itr->key, key) == 0)
			return (itr);
		itr = itr->next;
	}
	return (NULL);
}

char	*hash_search_value(t_hash_table *ht, char *key, bool *is_found)
{
	t_cell	*itr;

	itr = hash_search_cell(ht, key, hash_func(ht, key));
	if (itr != NULL)
	{
		*is_found = true;
		return (itr->value);
	}
	else
	{
		*is_found = false;
		return (NULL);
	}
}
