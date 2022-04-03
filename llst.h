/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:22:59 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/03 18:16:47 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLST_H
# define LLST_H

# include <stdlib.h>
# include <stdbool.h>

// # define BUFFER_SIZE 1025
# define BUFFER_SIZE 6

typedef struct s_llst
{
	char			buf[BUFFER_SIZE];
	size_t			len;
	struct s_llst	*prev;
	struct s_llst	*next;
}				t_llst;

void	llst_addback(t_llst *head, t_llst *new);
void	llst_clear(t_llst *head);
void	llst_insert(t_llst *lst, t_llst *new);
void	llst_link(t_llst *now, t_llst *next);
t_llst	*llst_new(size_t len);
bool	llst_isempty(t_llst *lst);
t_llst	*llst_last(t_llst *lst);
bool	llst_delone(t_llst *elem);

#endif
