/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:53:53 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 14:56:44 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	cell_clear(t_cell **cptr)
{
	t_cell	*itr;
	t_cell	*tmp;

	if (!cptr || !(*cptr))
		return ;
	itr = *cptr;
	while (itr != NULL)
	{
		tmp = itr->next;
		cell_delone(itr);
		itr = tmp;
	}
	*cptr = NULL;
}
