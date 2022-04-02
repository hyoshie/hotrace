/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:36:11 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 11:48:05 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

size_t	hash_func(t_hash_table *ht, char *key)
{
	size_t	value;

	value = 0;
	while (*key != '\0')
		value = (value << 3) + *key++;
	return (value % ht->size);
}
