/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:48:13 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/03 18:26:57 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line2.h"

size_t	get_line_len(t_llst *head)
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

size_t	get_last_valid_buf_len(t_llst *head, char *nl_ptr)
{
	if (nl_ptr)
		return (nl_ptr - llst_last(head)->buf);
	else
		return (llst_last(head)->len);
}

static int split_line(char **line, t_llst *head, char *nl_ptr)
{
	const size_t	sum = get_line_len(head);
	const size_t	last_buf_len = get_last_valid_buf_len(head, nl_ptr);
	t_llst			*current;
	int				line_i;

	*line = (char *)malloc(sum + last_buf_len + 1);
	if (*line == NULL)
		return (-1);
	current = head->next;
	line_i = 0;
	while (current != llst_last(head))
	{
		my_strlcpy(&(*line)[line_i], current->buf, current->len + 1);
		line_i += current->len;
		llst_delone(current);
		current = current->next;
	}
	my_strlcpy(&(*line)[line_i], llst_last(head)->buf, last_buf_len + 1);
	if (nl_ptr)
	{
		llst_last(head)->len = llst_last(head)->len - last_buf_len - 1;
		my_strlcpy(llst_last(head)->buf, nl_ptr + 1, llst_last(head)->len + 1);
	}
	else
		llst_clear(head);
	return (1);
}

static int	read_until_include_nl(int fd, t_llst *head, char **nl_ptr)
{
	ssize_t	readsize;
	t_llst	*new_llst;

	while (1)
	{
		new_llst = llst_new(0);
		if (new_llst == NULL)
			return (-1);
		readsize = read(fd, new_llst->buf, BUFFER_SIZE - 1);
		if (readsize <= 0)
			break ;
		new_llst->buf[readsize] = '\0';
		new_llst->len = readsize;
		llst_addback(head, new_llst);
		*nl_ptr = ft_strchr(new_llst->buf, '\n');
		if (*nl_ptr)
			return (1);
	}
	free(new_llst);
	return (readsize);
}
#include <stdio.h>
int	get_next_line(int fd, char **line)
{
	static t_llst	*llst;
	char			*nl_ptr;

	if (fd < 0 || fd >= 256 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (llst == NULL)
	{
		llst = llst_new(0);
		if (llst == NULL)
			return (-1);
	}
	if (!llst_isempty(llst))
		nl_ptr = ft_strchr(llst_last(llst)->buf, '\n');
	else
		nl_ptr = NULL;
	if (nl_ptr == NULL)
	{
		if (read_until_include_nl(fd, llst, &nl_ptr) == -1)
			return (status_with_clear(llst, NULL, -1));
	}
	if (split_line(line, llst, nl_ptr) == -1)
		return (status_with_clear(llst, NULL, -1));
	return (nl_ptr != NULL);
}
