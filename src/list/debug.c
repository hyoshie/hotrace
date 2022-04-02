/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:06:07 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/01 15:10:54 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/hotrace.h"
#include "../libft/mylibft.h"

void	print_list(t_list *begin)
{
	while (begin != NULL)
	{
		ft_putendl_fd((char *)begin->content, 1);
		begin = begin->next;
	}
}

void	print_dict(t_dict *begin)
{
	t_dict	*itr;

	itr = begin->next;
	while (itr != begin)
	{
		ft_putstr_fd("key  : ", 1);
		ft_putendl_fd((char *)itr->key, 1);
		ft_putstr_fd("value: ", 1);
		ft_putendl_fd((char *)itr->value, 1);
		itr = itr->next;
	}
}
