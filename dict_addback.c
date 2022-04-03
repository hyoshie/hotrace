/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_addback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:00:56 by yshimazu          #+#    #+#             */
/*   Updated: 2022/04/03 13:36:29 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

bool	dict_addback(t_dict *head, t_dict *new)
{
	if (!head || !new)
		return (false);
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	return (true);
}
