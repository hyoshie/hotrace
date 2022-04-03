/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_before.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:06:03 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/03 17:23:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static ssize_t	set_return_ssize_t(ssize_t *cnt, ssize_t read);
static char		*set_return_str(char **str1, char *str2);
static int		reset_for_error(char **line, char **left);
static int		check_strs(ssize_t cnt, char **line, char **left);

int	get_next_line(int fd, char **line)
{
	static char	*left;
	char		buf[BUFFER_SIZE + 1];
	char		*nlptr;
	ssize_t		cnt;
	size_t		line_len;

	*line = left;
	left = NULL;
	line_len = gnl_strlen(*line);
	while (set_return_ssize_t(&cnt, read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		line_len += cnt;
		buf[cnt] = '\0';
		free_set(line, gnl_strjoin(*line, buf, line_len));
		if (*line && set_return_str(&nlptr, gnl_strchr(*line, '\n')))
		{
			*nlptr = '\0';
			left = gnl_strdup(nlptr + 1, line_len - (nlptr - *line));
			free_set(line, gnl_strdup(*line, nlptr - *line));
			return (check_strs(cnt, line, &left));
		}
		if (!*line || cnt == 0)
			return (check_strs(cnt, line, &left));
	}
	return (reset_for_error(line, &left));
}

static ssize_t	set_return_ssize_t(ssize_t *cnt, ssize_t read)
{
	*cnt = read;
	return (*cnt);
}

static char	*set_return_str(char **str1, char *str2)
{
	*str1 = str2;
	return (*str1);
}

static int	reset_for_error(char **line, char **left)
{
	free_set(line, NULL);
	free_set(left, NULL);
	return (-1);
}

static int	check_strs(ssize_t cnt, char **line, char **left)
{
	int	ret;

	ret = cnt;
	if (!*line)
		ret = reset_for_error(line, left);
	else if (cnt > 0 || *left || **line != '\0')
		ret = 1;
	else
		free_set(line, NULL);
	return (ret);
}
