/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:22:59 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/03 13:42:58 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include "utils.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_dict
{
	struct s_dict	*prev;
	char			*key;
	char			*value;
	struct s_dict	*next;
}				t_dict;

bool	dict_addback(t_dict *head, t_dict *new);
void	dict_clear(t_dict *head);
bool	dict_delone(t_dict *elem);
t_dict	*dict_new(char *key, char *value);
t_dict	*dict_search_item(char *key, t_dict *dict);

#endif
