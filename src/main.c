/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:42:48 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/01 15:11:19 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	read_stdin(t_list **kvl_lines, t_list **key_to_search)
{
	char	*line;

	*kvl_lines = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0 && *line != '\0')
	{
		ft_lstadd_back(kvl_lines, ft_lstnew(line));
	}
	*key_to_search = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		ft_lstadd_back(key_to_search, ft_lstnew(line));
	}
}

t_dict	*store_kvl(t_list *kvl_lines)
{
	t_dict	*kvl_dammy;
	t_dict	*new;

	if (kvl_lines == NULL || kvl_lines->next == NULL)
		return (NULL);
	kvl_dammy = dict_new(NULL, NULL);
	while (kvl_lines != NULL && kvl_lines->next != NULL)
	{
		new = dict_new(kvl_lines->content, kvl_lines->next->content);
		dict_addback(kvl_dammy, new);
		kvl_lines = kvl_lines->next->next;
	}
	return (kvl_dammy);
}

void	print_value(t_dict *kvl_dammy, t_list *key_to_search)
{
	char	*target_value;

	if (kvl_dammy == NULL || key_to_search == NULL)
		return ;
	while (key_to_search != NULL)
	{
		target_value = dict_get_value(key_to_search->content, kvl_dammy);
		if (target_value != NULL)
		{
			ft_putendl_fd(target_value, STDOUT_FILENO);
		}
		else
		{
			ft_putstr_fd(key_to_search->content, STDOUT_FILENO);//STDERR_FILENO?
			ft_putendl_fd(": Not found.", STDOUT_FILENO);//STDERR_FILENO?
		}
		key_to_search = key_to_search->next;
	}
}

int	main(void)
{
	t_list	*kvl_lines;
	t_list	*key_to_search;
	t_dict	*kvl_dammy;

	read_stdin(&kvl_lines, &key_to_search);
	kvl_dammy = store_kvl(kvl_lines);
	print_value(kvl_dammy, key_to_search);
	return (0);
}
