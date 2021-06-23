/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:11:25 by heom              #+#    #+#             */
/*   Updated: 2021/06/23 16:57:49 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	put_a_in_arr(t_item *a, int *a_arr)
{
	int i;
	t_item *a_start;

	i = 0;
	a_start = a;
	while(1)
	{
		a_arr[i] = a_start->num;
		a_start = a_start->next;
		i++;
		if (a_start == a)
			break;
	}
	a_arr[i] = '\0';
}

void	ft_swap(int *l_arr, int *r_arr)
{
	int tmp;

	tmp = *l_arr;
	*l_arr = *r_arr;
	*r_arr = tmp;
}

void	quick_sort(int *arr, int start, int end)
{
	int	s_pnt;
	int	e_pnt;
	int	pivot;

	s_pnt = start;
	e_pnt = end;
	pivot = arr[start];
	if (start >= end)
		return ;
	while (s_pnt < e_pnt)
	{
		while (arr[s_pnt] <= pivot && s_pnt < end)
			s_pnt++;
		while (arr[e_pnt] > pivot && e_pnt > start)
			e_pnt--;
		if (s_pnt >= e_pnt)
			break ;
		ft_swap(&arr[s_pnt], &arr[e_pnt]);
	}
	ft_swap(&arr[e_pnt], &arr[start]);

	// removed
	printf("----hello pivot: %d, %d~%d---\n", pivot, start, end);
	int in = 0;
	while (arr[in])
	{
		printf("%d : %d\n", in , arr[in]);
		in++;
	}
	printf("\n");

	quick_sort(arr, start, e_pnt - 1);
	quick_sort(arr, e_pnt + 1, end);
}

void	pre_sort(t_item *a)
{
	int	*a_arr;
	int	list_size;

	list_size = stack_size(a);
	a_arr = (int *)malloc(sizeof(int) * (list_size + 1));
	if (a_arr == 0)
		exit(0); //need to modify
	put_a_in_arr(a, a_arr);
	quick_sort(a_arr, 0, list_size - 1);

	// removed
	int in = 0;
	printf("최종 -----\n");
	while (a_arr[in])
	{
		printf("%d : %d\n", in , a_arr[in]);
		in++;
	}
	printf("\n");
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
