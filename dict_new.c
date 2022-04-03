/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:01:27 by yshimazu          #+#    #+#             */
/*   Updated: 2022/04/03 13:36:42 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict	*dict_new(char *key, char *value)
{
	t_dict	*elem;

	elem = (t_dict *)malloc(sizeof(t_dict));
	if (!elem)
		return (NULL);
	elem->key = key;
	elem->value = value;
	elem->prev = elem;
	elem->next = elem;
	return (elem);
}
