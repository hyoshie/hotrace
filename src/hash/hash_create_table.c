/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_create_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:02:32 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 16:46:05 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

t_hash_table	*hash_create_table(size_t	size)
{
	t_hash_table	*ht;
	size_t			idx;

	ht = (t_hash_table *)malloc(sizeof(t_hash_table));
	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->count = 0;
	ht->table = (t_cell **)malloc(sizeof(t_cell *) * size);
	if (ht->table == NULL)
	{
		free(ht);
		return (NULL);
	}
	idx = 0;
	while (idx < size)
		ht->table[idx++] = NULL;
	return (ht);
}
