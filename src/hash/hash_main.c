/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:07:48 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 15:09:15 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

int	main(void)
{
	test_hash_func();
	// hash_create_table(42);
	// test_cell_func();
	return (0);
}

void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void)
{
	if (system("leaks -q a.out > /dev/null"))
		system("leaks -q a.out");
}
