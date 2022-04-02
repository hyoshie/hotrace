/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:24:09 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 16:47:02 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

bool	hash_delete(t_hash_table *ht, char *key)
{
	size_t	hval;
	t_cell	*cptr;
	t_cell	*del;

	hval = hash_func(ht, key);
	cptr = ht->table[hval];
	if (cptr == NULL)
		return (false);
	if (ft_strcmp(cptr->key, key) == 0)
	{
		ht->table[hval] = cptr->next;
		ht->count--;
		cell_delone(cptr);
	}
	else
	{
		while (cptr != NULL)
		{
			if (ft_strcmp(cptr->next->key, key) == 0)
			{
				del = cptr->next;
				cptr->next = cptr->next->next;
				ht->count--;
				cell_delone(del);
			}
			cptr = cptr->next;
		}
	}
	return (true);
}
