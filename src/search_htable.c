/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_htable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:23:50 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/01 18:43:27 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void	hash_search(t_dict **htable, char *key)
{
	const size_t	htable_index = hash_func(key);
	const t_dict	*hit_dict = dict_search_item(key, htable[htable_index]);

	if (hit_dict == NULL)
		ft_putendl_fd("No", STDOUT_FILENO);
	else
		ft_putendl_fd(hit_dict->value, STDOUT_FILENO);
}

t_status	search_htable_step(t_dict **htable)
{
	char	*key;
	int		gnl_status;

	while (1)
	{
		gnl_status = get_next_line(STDIN_FILENO, &key);
		if (gnl_status <= 0)
			break ;
		hash_search(htable, key);
		free(key);
	}
	free(key);
	if (gnl_status == -1)
		return (ERROR);
	else
		return (SUCCESS);
}
