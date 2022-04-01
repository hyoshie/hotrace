/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:20:33 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/01 17:21:24 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

size_t	hash_func(const char *str)
{
	int		i;
	size_t	htable_index;

	i = 0;
	htable_index = 0;
	while (str[i])
	{
		htable_index = (htable_index + str[i]) % HTABLE_SIZE;
		i++;
	}
	return (htable_index);
}
