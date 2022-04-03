/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:02:04 by yshimazu          #+#    #+#             */
/*   Updated: 2022/04/03 13:44:54 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	i = 0;
	while ((u_s1[i] != 0 && u_s2[i] != 0))
	{
		if (u_s1[i] != u_s2[i])
			return (u_s1[i] - u_s2[i]);
		i++;
	}
	return (u_s1[i] - u_s2[i]);
}
