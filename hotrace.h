/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:46:37 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/03 13:42:45 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "dict.h"
# include "get_next_line.h"
# include "utils.h"
# include <unistd.h>
# include <errno.h>
# include <string.h>

# define HTABLE_SIZE 1000000

typedef enum e_status
{
	SUCCESS	= 0,
	ERROR	= 1,
	EXIT	= 2
}			t_status;

t_status	store_htable(t_dict **htable);
t_status	search_htable(t_dict **htable);
size_t		hash_func(const char *str);

#endif /* HOTRACE_H */
