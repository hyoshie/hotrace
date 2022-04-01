/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:42:48 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/01 14:34:38 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/hotrace.h"
#include "../libft/mylibft.h"


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

void	print_list(t_list *begin)
{
	while (begin != NULL)
	{
		ft_putendl_fd((char *)begin->content, 1);
		begin  = begin->next;
	}
}

int	main(void)
{
	t_list	*kvl_lines;
	t_list	*key_to_search;
	// t_dict	*kvl;

	read_stdin(&kvl_lines, &key_to_search);
	// kvl = store_kvl(key_to_search);
	// print_value(kvl, key_to_search);
	ft_putendl_fd("Hello!!", 1);
	print_list(kvl_lines);
	print_list(key_to_search);
	return (0);
}
