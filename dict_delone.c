/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_delone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:01:15 by yshimazu          #+#    #+#             */
/*   Updated: 2022/04/03 13:36:37 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

bool	dict_delone(t_dict *elem)
{
	t_dict	*front;
	t_dict	*back;

	if (!elem || elem->next == elem)
		return (false);
	front = elem->next;
	back = elem->prev;
	back->next = front;
	front->prev = back;
	free(elem->key);
	free(elem->value);
	free(elem);
	return (true);
}
