/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_delete_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:05:01 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 15:12:43 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	hash_delete_table(t_hash_table *ht)
{
	size_t	idx;

	idx = 0;
	while (idx < ht->size)
	{
		cell_clear(&ht->table[idx++]);
	}
	free(ht->table);
	free(ht);
}
