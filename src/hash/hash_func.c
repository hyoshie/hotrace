/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:36:11 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 17:49:25 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

size_t	hash_func(t_hash_table *ht, char *key)
{
	size_t	hval;

	hval = 2166136261UL;
	while (*key != '\0')
	{
		// hval = (hval << 3) + *key++;
		hval *= 16777619UL;
		hval ^= *((unsigned char *)key++);
	}
	return (hval % ht->size);
}
