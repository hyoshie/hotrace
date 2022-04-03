/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:51:52 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/03 19:08:23 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_line_len(t_llst *head)
{
	t_llst	*current;
	size_t	sum;

	current = head->next;
	sum = 0;
	while (current != llst_last(head))
	{
		sum += current->len;
		current = current->next;
	}
	return (sum);
}

static size_t	get_last_valid_buf_len(t_llst *head, char *nl_ptr)
{
	if (nl_ptr)
		return (nl_ptr - llst_last(head)->buf);
	else
		return (llst_last(head)->len);
}

static void	copy_last_buf(t_llst *head, char *nl_ptr, const size_t last_buf_len)
{
	if (nl_ptr)
	{
		llst_last(head)->len = llst_last(head)->len - last_buf_len - 1;
		my_strlcpy(llst_last(head)->buf, nl_ptr + 1, llst_last(head)->len + 1);
	}
	else
		llst_clear(head);
}

int	split_line(char **line, t_llst *head, char *nl_ptr)
{
	const size_t	sum = get_line_len(head);
	const size_t	last_buf_len = get_last_valid_buf_len(head, nl_ptr);
	t_llst			*current;
	int				line_i;
	t_llst			*tmp;

	*line = (char *)malloc(sum + last_buf_len + 1);
	if (*line == NULL)
		return (-1);
	current = head->next;
	line_i = 0;
	while (current != llst_last(head))
	{
		my_strlcpy(&(*line)[line_i], current->buf, current->len + 1);
		line_i += current->len;
		tmp = current;
		current = current->next;
		llst_delone(tmp);
	}
	my_strlcpy(&(*line)[line_i], llst_last(head)->buf, last_buf_len + 1);
	copy_last_buf(head, nl_ptr, last_buf_len);
	return (1);
}
