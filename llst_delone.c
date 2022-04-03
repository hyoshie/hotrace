/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_delone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:10:16 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/03 17:10:44 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llst.h"

bool	llst_delone(t_llst *elem)
{
	t_llst	*front;
	t_llst	*back;

	if (!elem || elem->next == elem)
		return (false);
	front = elem->next;
	back = elem->prev;
	back->next = front;
	front->prev = back;
	free(elem);
	return (true);
}
