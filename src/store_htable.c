/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_htable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:10:09 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/02 17:30:05 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static t_status	status_with_free(void *p1, void *p2, const t_status status)
{
	free(p1);
	free(p2);
	return (status);
}

static t_status	hash_add(t_dict **htable, char *key, char *value)
{
	const size_t	htable_index = hash_func(key);
	t_dict			*hit_dict;
	t_dict			*new_dict;

	hit_dict = dict_search_item(key, htable[htable_index]);
	if (hit_dict == NULL)
	{
		new_dict = dict_new(key, value);
		if (new_dict == NULL)
			return (ERROR);
		dict_addback(htable[htable_index], new_dict);
	}
	else
	{
		free(key);
		free(hit_dict->value);
		hit_dict->value = value;
	}
	return (SUCCESS);
}

t_status	store_htable(t_dict **htable)
{
	char	*line;
	char	*key;
	int		gnl_status;

	key = NULL;
	while (1)
	{
		gnl_status = get_next_line(STDIN_FILENO, &line);
		if (gnl_status == -1)
			return (status_with_free(key, line, ERROR));
		else if (gnl_status == 0)
			return (status_with_free(key, line, EXIT));
		else if (line[0] == '\0')
			return (status_with_free(key, line, SUCCESS));
		if (key == NULL)
			key = line;
		else
		{
			if (hash_add(htable, key, line) == ERROR)
				return (status_with_free(key, line, ERROR));
			key = NULL;
		}
	}
}
