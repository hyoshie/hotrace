/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:20:33 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/03 14:30:13 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdint.h>

size_t	hash_func(const char *s)
{
	static const uint64_t	offset = 14695981039346656037UL;
	static const uint64_t	prime = 1099511628211UL;
	uint64_t				hash;
	uint8_t					byte;

	hash = offset;
	while (*s)
	{
		byte = *s;
		hash ^= byte;
		hash *= prime;
		s++;
	}
	return (hash % HTABLE_SIZE);
}
