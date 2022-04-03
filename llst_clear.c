/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:57:44 by yshimazu          #+#    #+#             */
/*   Updated: 2022/04/03 16:43:42 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llst.h"

void	llst_clear(t_llst *head)
{
	t_llst	*p;

	p = head->next;
	while (p != head)
	{
		p = p->next;
		free(p->prev);
	}
	free (head);
}
