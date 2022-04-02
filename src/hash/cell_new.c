/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:44:29 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 14:48:26 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

t_cell	*cell_new(char *key, char *value, t_cell *next)
{
	t_cell	*cptr;

	cptr = (t_cell *)malloc(sizeof(t_cell));
	if (cptr == NULL)
		return (NULL);
	cptr->key = ft_strdup(key);
	if (cptr->key == NULL)
	{
		free(cptr);
		return (NULL);
	}
	cptr->value = ft_strdup(value);
	if (cptr->value == NULL)
	{
		free(cptr->key);
		free(cptr);
		return (NULL);
	}
	cptr->next = next;
	return (cptr);
}
