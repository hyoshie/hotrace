/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:43:18 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/02 16:34:57 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	test_hash_func(void)
{
	t_hash_table	*ht;

	ht = hash_create_table(42);
	printf("[hvl:\"42tokyo\"]%zu\n", hash_func(ht, "42tokyo"));
	printf("[hvl:\"hoge\"]%zu\n", hash_func(ht, "hoge"));
	printf("[hvl:\"hogee\"]%zu\n", hash_func(ht, "hogee"));
	hash_delete_table(ht);
}

void	test_cell_func(void)
{
	t_cell	*begin;
	t_cell	*itr;

	begin = cell_new("1", "42tokyo ", NULL);
	begin->next = cell_new("2", "is ", NULL);
	begin->next->next = cell_new("3", "good ", NULL);
	begin->next->next->next = cell_new("4", "place!!", NULL);

	itr = begin;
	while (itr != NULL)
	{
		printf("%s : %s\n", itr->key, itr->value);
		itr = itr->next;
	}
	cell_clear(&begin);
}

// void	test_simple(void)
// {
// 	char buff[8][12];
// 	t_hash_table *ht = hash_create_table(5);
// 	bool err;
// 	printf("-- %d, %zu --\n", hash_is_empty(ht), hash_length(ht));
// 	printf("----- insert -----\n");
// 	for (int i = 0; i < 8; i++) {
// 	  buff[i]  = ;
// 	  printf("%s, %d\n", buff[i], hash_insert(ht, buff[i], "VALUE"));
// 	}
// 	printf("-- %d, %zu --\n", hash_is_empty(ht), hash_length(ht));
// 	printf("------ search ------\n");
// 	for (int i = 0; i < 8; i++)
// 	  printf("%s, %d\n", buff[i], hash_search_value(ht, buff[i], &err));
// 	printf("------ delete ------\n");
// 	for (int i = 0; i < 8; i++) {
// 	  printf("%s %d\n", buff[i], hash_delete(ht, buff[i]));
// 	  int x = search_hash(ht, buff[i], &err);
// 	  printf("%s, %d, %d\n", buff[i], x, err);
// 	}
// 	printf("-- %d, %zu --\n", hash_is_empty(ht), hash_length(ht));
// 	printf("----- delete hash -----\n");
// 	hash_delete_table(ht);
// }
