/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:48:13 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/03 19:05:04 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	status_with_clear(t_llst *llst, char *str, const int status)
{
	llst_clear(llst);
	free(str);
	return (status);
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
