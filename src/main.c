/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:42:48 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/01 16:24:33 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_dict	*store_kvl_data(void)
{
	char	*key;
	char	*value;
	t_dict	*kvl_dammy;

	kvl_dammy = dict_new(NULL, NULL);
	while (42)
	{
		if (get_next_line(STDIN_FILENO, &key) > 0 && key[0] != '\0' && \
			get_next_line(STDIN_FILENO, &value) > 0 && value[0] != '\0')
			dict_addback(kvl_dammy, dict_new(key, value));
		else
			break ;
	}
	return (kvl_dammy);
}

void	search_and_print(t_dict *kvl_dammy)
{
	char	*search_word;
	char	*result;

	while (get_next_line(STDIN_FILENO, &search_word) > 0)
	{
		result = dict_get_value(search_word, kvl_dammy);
		if (result != NULL)
		{
			ft_putendl_fd(result, STDOUT_FILENO);
		}
		else
		{
			ft_putstr_fd(search_word, STDOUT_FILENO);//STDERR_FILENO?
			ft_putendl_fd(": Not found.", STDOUT_FILENO);//STDERR_FILENO?
		}
	}
}

int	main(void)
{
	t_dict	*kvl_dammy;

	kvl_dammy = store_kvl_data();
	search_and_print(kvl_dammy);
	return (0);
}
