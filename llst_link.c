/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:58:18 by yshimazu          #+#    #+#             */
/*   Updated: 2022/04/03 11:49:09 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llst.h"

void	llst_link(t_llst *now, t_llst *next)
{
	now->next = next;
	next->prev = now;
}
