/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:42:48 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 16:55:01 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "hash.h"

void	store_cell(t_hash_table *ht)
{
	char	*key;
	char	*value;

	while (42)
	{
		if (get_next_line(STDIN_FILENO, &key) > 0 && key[0] != '\0' && \
			get_next_line(STDIN_FILENO, &value) > 0 && value[0] != '\0')
			hash_insert(ht, key, value);
		else
			break ;
	}
}

void	search_and_print(t_hash_table *ht)
{
	char	*search_word;
	char	*result;
	bool	is_found;

	while (get_next_line(STDIN_FILENO, &search_word) > 0)
	{
		result = hash_search_value(ht, search_word, &is_found);
		if (is_found)
		{
			ft_putendl_fd(result, STDOUT_FILENO);
		}
		else
		{
			ft_putstr_fd(search_word, STDOUT_FILENO);
			ft_putendl_fd(": Not found.", STDOUT_FILENO);
		}
	}
}

#define HASH_TABLE_SIZE 1024

int	main(void)
{
	t_hash_table	*ht;

	ht = hash_create_table(HASH_TABLE_SIZE);
	store_cell(ht);
	search_and_print(ht);
	return (0);
}
