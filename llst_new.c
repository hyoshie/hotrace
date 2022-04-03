/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:56:13 by yshimazu          #+#    #+#             */
/*   Updated: 2022/04/03 16:44:03 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llst.h"

t_llst	*llst_new(size_t len)
{
	t_llst	*elem;

	elem = (t_llst *)malloc(sizeof(t_llst));
	if (!elem)
		return (NULL);
	elem->len = len;
	elem->prev = elem;
	elem->next = elem;
	return (elem);
}
