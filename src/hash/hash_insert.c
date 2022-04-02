/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:09:04 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 15:16:33 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

// if does not exist node contains key, add front and return true
// if exists node contains key, rewrite and return false
// if either ht or key is NULL, return false.
// though it is bad, it can not be helped because can not use exit().
bool	hash_insert(t_hash_table *ht, char *key, char *val)
{
	int		hval;
	t_cell	*cptr;

	if (ht == NULL || key == NULL)
		return (false);
	hval = hash_func(ht, key);
	cptr = hash_search_cell(ht, key, hval);
	if (cptr == NULL)
	{
		ht->table[hval] = cell_new(key, val, ht->table[hval]);
		ht->count++;
		return (true);
	}
	else
	{
		free(cptr->value);
		cptr->value = val;
		return (false);
	}
}
