/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:58:56 by yshimazu          #+#    #+#             */
/*   Updated: 2022/04/03 11:48:58 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llst.h"

void	llst_insert(t_llst *lst, t_llst *new)
{
	llst_link(new, lst->next);
	llst_link(lst, new);
}
