/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_htable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:10:09 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/01 19:06:49 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static t_status	hash_add(t_dict **htable, char *key, char *value)
{
	const size_t	htable_index = hash_func(key);
	t_dict			*new_dict;

	new_dict = dict_new(key, value);
	if (new_dict == NULL)
		return (ERROR);
	dict_addback(htable[htable_index], new_dict);
	return (SUCCESS);
}

t_status	store_htable_step(t_dict **htable)
{
	char	*line;
	char	*key;
	int		gnl_status;

	while (1)
	{
		gnl_status = get_next_line(STDIN_FILENO, &line);
		if (gnl_status <= 0 || line[0] == '\0')
			break ;
		if (key == NULL)
			key = line;
		else
		{
			// error_handle
			hash_add(htable, key, line);
			key = NULL;
		}
	}
	free(key);
	free(line);
	if (gnl_status <= 0)
		return (ERROR);
	else
		return (SUCCESS);
}
