/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:11:25 by heom              #+#    #+#             */
/*   Updated: 2021/07/09 16:43:47 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		find_next_pivot(t_item *current, int cur_pivot)
{
	t_item	*stop;
	int		max_num;
	int		min_num;
	int 	nxt_pivot;

	stop = current;
	nxt_pivot = current->next->num;
	max_num = current->num;
	min_num = current->num;
	while (1)
	{
		if (max_num < current->num)
			max_num = current->num;
		if (min_num > current->num)
			min_num = current->num;
		if (current->num > cur_pivot && current->num < nxt_pivot)
			nxt_pivot = current->num;
		current = current->next;
		if (current == stop)
			break ;
	}
	if (cur_pivot == max_num)
		nxt_pivot = min_num;
	return (nxt_pivot);
}

void	sort_stack(void)
{
	int		pivot_a;
	int		pivot_b;
	int		nxt_pi_a;
	int		nxt_pi_b;
	
	int i;
	i = 0;
	pivot_a = all()->a->num;
	pivot_b = all()->b->num;
	while (1)
	{
		nxt_pi_a = find_next_pivot(all()->a, pivot_a);
		nxt_pi_b = find_next_pivot(all()->b, pivot_b);
		if (!is_sort_complete(all()->a) && !is_sort_complete(all()->b))
		{
			while (1)
			{
				if (all()->a->next->num != nxt_pi_a && all()->b->next->num != nxt_pi_b)
				{
					ss();
					rr();
				}
				if (all()->a->next->num != nxt_pi_a)
				{
					sa();
					ra();
				}
				else if (all()->b->next->num != nxt_pi_b)
				{
					sb();
					rb();
				}
				if (all()->a->next->num == nxt_pi_a && all()->b->next->num == nxt_pi_b)
					break ;
			}
			pivot_a = nxt_pi_a;
			pivot_b = nxt_pi_b;
			while (1)
			{
				if (all()->a->num != pivot_a && all()->b->num != pivot_b)
					rr();
				if (all()->a->num != pivot_a)
					ra();
				else if (all()->b->num != pivot_b)
					rb();
				if (all()->a->num == pivot_a && all()->b->num == pivot_b)
					break ;
			}
		}
		else if (!is_sort_complete(all()->a))
		{
			while (all()->a->next->num != nxt_pi_a)
			{
				sa();
				ra();
			}
			pivot_a = nxt_pi_a;
			while (all()->a->num != pivot_a)
				ra();
		}
		else if (!is_sort_complete(all()->b))
		{
			while (all()->b->next->num != nxt_pi_b)
			{
				sb();
				rb();
			}
			pivot_b = nxt_pi_b;
			while (all()->b->num != pivot_b)
				rb();
		}
		if (is_sort_complete(all()->a) && is_sort_complete(all()->b))
			break ;
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
	all()->sort = arr;
}

void	push_b_to_a()
{
	int	now_a;
	int	now_b;
	int	prev_a;
	while (1)
	{
		now_a = all()->a->num;
		prev_a = all()->a->prev->num;
		now_b = all()->b->num;
		if (now_a > now_b && prev_a < now_b)
			pa();
		else
			ra();
		if (all()->b == NULL)
			break ;
	}
}

void	fix_a_fist_stack()
{
	while (1)
	{
		rra();
		if (all()->a->num == all()->min_num)
			break ;
	}
}

void	sort_algo(t_item **a)
{
	pre_sort(*a);
	devide_num();
	// printf("devide end------\n");
	sort_stack();
	// printf("sort_stack end------\n");
	push_b_to_a();
	// printf("push_b_to_a end------\n");
	fix_a_fist_stack();
}

int		main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		if (!is_all_argv_num(argv))
			return (0);
		set_stack(&all()->a, argc - 1, argv);
		sort_algo(&all()->a);
		//printf("pivot_a : %d, nxt_pivot a : %d\n", all()->a->num, find_next_pivot(all()->a, all()->a->num));
		
	}
	// // removed
	// t_item *current;
	// current = all()->a;
	// printf("----a-----\n");
	// while (current)
	// {
	// 	printf("%d\n", current->num);
	// 	current = current->next;
	// 	if (current == all()->a)
	// 		break ;
	// }

	// current = all()->b;
	// printf("----b-----\n");
	// while (current)
	// {
	// 	printf("%d\n", current->num);
	// 	current = current->next;
	// 	if (current == all()->b)
	// 		break ;
	// }
	// printf("----after_sort-----\n");
	// int	i;

	// i = 0;
	// while (all()->sort[i])
	// {
	// 	printf("%d : %d\n", i, all()->sort[i]);
	// 	i++;
	// }
	free(all()->sort);
	return (0);
}
