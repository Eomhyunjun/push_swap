/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:11:25 by heom              #+#    #+#             */
/*   Updated: 2021/06/23 19:48:06 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	dupcheck(int *arr)
{
	int i;

	i = 0;
	while(arr[i + 1])
	{
		if (arr[i] == arr[i + 1])
			safe_exit(1, "Duplicate number.");
		i++;
	}
}

void	pre_sort(t_item *a)
{
	int	*arr;
	int	list_size;

	list_size = stack_size(a);
	arr = (int *)malloc(sizeof(int) * (list_size + 1));
	if (arr == 0)
		safe_exit(1, "can't malloc stact");
	put_a_in_arr(a, arr);
	quick_sort(arr, 0, list_size - 1);
	dupcheck(arr);
}

void	sort_algo(t_item **a)
{
	pre_sort(*a);
}

int		main(int argc, char *argv[])
{
	t_item	*a;
	t_item	*b;

	a = 0;
	b = 0;
	if (argc >= 2)
	{
		if (!is_all_argv_num(argv))
			return (0);
		set_stack(&a, argc - 1, argv);
		sort_algo(&a);
	}
	return (0);
}

	// // removed
	// printf("----hello pivot: %d, %d~%d---\n", pivot, start, end);
	// int in = 0;
	// while (arr[in])
	// {
	// 	printf("%d : %d\n", in , arr[in]);
	// 	in++;
	// }
	// printf("\n");


	// removed
	// int in = 0;
	// printf("최종 -----\n");
	// while (arr[in])
	// {
	// 	printf("%d : %d\n", in , arr[in]);
	// 	in++;
	// }
	// printf("\n");

