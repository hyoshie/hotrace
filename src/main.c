/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:42:48 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 17:29:43 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static int	status_with_errout(char *errmsg, const int status)
{
	ft_putendl_fd(errmsg, STDERR_FILENO);
	return (status);
}

static void	clear_htable(t_dict **htable, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dict_clear(htable[i]);
		i++;
	}
	free(htable);
}

static t_dict	**init_htable(void)
{
	size_t	i;
	t_dict	**htable;

	htable = (t_dict **)malloc(sizeof(t_dict *) * HTABLE_SIZE);
	if (htable == NULL)
		return (NULL);
	i = 0;
	while (i < HTABLE_SIZE)
	{
		htable[i] = dict_new(NULL, NULL);
		if (htable[i] == NULL)
		{
			clear_htable(htable, i);
			return (NULL);
		}
		i++;
	}
	return (htable);
}

int	main(void)
{
	t_dict		**htable;
	t_status	status;

	htable = init_htable();
	if (htable == NULL)
		return (status_with_errout(strerror(errno), 1));
	status = store_htable(htable);
	if (status == SUCCESS)
		status = search_htable(htable);
	clear_htable(htable, HTABLE_SIZE);
	if (status == ERROR)
		return (status_with_errout(strerror(errno), 1));
	return (0);
}
