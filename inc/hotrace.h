/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:46:37 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/01 19:02:01 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "mylibft.h"
# include <unistd.h>
# include <errno.h>
# include <string.h>

# define HTABLE_SIZE 1000

typedef enum e_statuss
{
	SUCCESS	= 0,
	ERROR	= 1
}			t_status;

t_status	store_htable_step(t_dict **htable);
t_status	search_htable_step(t_dict **htable);
size_t		hash_func(const char *str);

#endif /* HOTRACE_H */
