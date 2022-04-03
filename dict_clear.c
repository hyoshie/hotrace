/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:01:06 by yshimazu          #+#    #+#             */
/*   Updated: 2022/04/03 13:36:24 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	dict_clear(t_dict *head)
{
	t_dict	*p;

	p = head->next;
	while (p != head)
	{
		p = p->next;
		free(p->prev->key);
		free(p->prev->value);
		free (p->prev);
	}
	free (head);
}
