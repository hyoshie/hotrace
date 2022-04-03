/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:09:39 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/23 09:09:39 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "llst.h"

int		get_next_line(int fd, char **line);
void	my_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
int		split_line(char **line, t_llst *head, char *nl_ptr);

#endif
