/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:42:48 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/01 19:06:29 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static int	status_with_errout(char *errmsg, const int status)
{
	ft_putendl_fd(errmsg, STDERR_FILENO);
	return (status);
}

static t_dict	**init_htable(void)
{
	size_t 	i;
	t_dict	**htable;

	htable = (t_dict **)malloc(sizeof(t_dict *) * HTABLE_SIZE);
	if (htable == NULL)
		return (NULL);
	i = 0;
	while (i < HTABLE_SIZE)
	{
		htable[i] = NULL;
		i++;
	}
	return (htable);
}

static void	clear_htable(t_dict **htable)
{
	size_t	i;

	i = 0;
	while (i < HTABLE_SIZE)
	{
		dict_clear(htable[i]);
		i++;
	}
}

int	main(void)
{
	t_dict	**htable;

	htable = init_htable();
	if (htable == NULL)
		return (status_with_errout(strerror(errno), 1));
	if (store_htable_step(htable) == ERROR
		|| search_htable_step(htable) == ERROR)
	{
		clear_htable(htable);
		return (status_with_errout(strerror(errno), 1));
	}
	clear_htable(htable);
	return (0);
}
