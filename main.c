/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:11:25 by heom              #+#    #+#             */
/*   Updated: 2021/07/14 08:18:07 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	print_sort_list(void)
{
	t_item *current;
	char buf[1024];

	current = all()->a;
	printf("----a-----\n");
	while (current)
	{
		printf("%d\n", current->num);
		current = current->next;
		if (current == all()->a)
			break ;
	}
	current = all()->b;
	printf("----b-----\n");
	while (current)
	{
		printf("%d\n", current->num);
		current = current->next;
		if (current == all()->b)
			break ;
	}
	read(0, &buf, 1024);
}

void	find_min_max_num(t_item *current, int *min_num, int *max_num)
{
	t_item	*stop;
	
	stop = current;
	while (1)
	{
		if (*max_num < current->num)
			*max_num = current->num;
		if (*min_num > current->num)
			*min_num = current->num;
		current = current->next;
		if (current == stop)
			break ;
	}
}

int		find_dest_pivot(t_item *current, int cur_pivot)
{
	t_item	*stop;
	int		min_num;
	int		max_num;
	int 	nxt_pivot;

	stop = current;
	min_num = current->num;
	max_num = current->num;
	find_min_max_num (current, &min_num, &max_num);
	if (cur_pivot == max_num)
		return (min_num);
	t_item *nxt_pivot_current = current->next;
	while (1)
	{
		if (nxt_pivot_current->num > current->num)
		{
			nxt_pivot = nxt_pivot_current->num;
			break ;
		}
		nxt_pivot_current = nxt_pivot_current->next;
	}
	while (1)
	{
		if (current->num > cur_pivot && current->num < nxt_pivot)
			nxt_pivot = current->num;
		current = current->next;
		if (current == stop)
			break ;
	}
	return (nxt_pivot);
}

int		find_start_pivot(t_item *current, int cur_pivot)
{
	t_item	*stop;
	int		min_num;
	int		max_num;
	int 	nxt_pivot;

	stop = current;
	min_num = current->num;
	max_num = current->num;
	find_min_max_num (current, &min_num, &max_num);
	if (cur_pivot == min_num)
		return (max_num);
	t_item *nxt_pivot_current = current->next;
	while (1)
	{
		if (nxt_pivot_current->num < current->num)
		{
			nxt_pivot = nxt_pivot_current->num;
			break ;
		}
		nxt_pivot_current = nxt_pivot_current->next;
	}
	while (1)
	{
		if (current->num < cur_pivot && current->num > nxt_pivot)
			nxt_pivot = current->num;
		current = current->next;
		if (current == stop)
			break ;
	}
	return (nxt_pivot);
}

void	sort_stack(void)
{
	int		start_pivot_a;
	int		start_pivot_b;
	int		dest_pivot_a;
	int		dest_pivot_b;
	
	int i;
	i = 0;
	start_pivot_a = all()->a->num;
	start_pivot_b = all()->b->num;
	dest_pivot_a = find_dest_pivot(all()->a, start_pivot_a);
	dest_pivot_b = find_dest_pivot(all()->b, start_pivot_b);
	while (1)
	{
		//printf("s_a : %d, d_a : %d, s_b %d, d_b %d\n", start_pivot_a, dest_pivot_a, start_pivot_b, dest_pivot_b);
		if (!is_sort_complete(all()->a) && !is_sort_complete(all()->b))
		{
			while (1)
			{
				if (all()->a->num != start_pivot_a && all()->b->num != start_pivot_b)
					rrr();
				else if (all()->a->num != start_pivot_a)
					rra();
				else if (all()->b->num != start_pivot_b)
					rrb();
				if (all()->a->num == start_pivot_a && all()->b->num == start_pivot_b)
					break ;
			}
			while (1)
			{
				if (all()->a->next->num != dest_pivot_a && all()->b->next->num != dest_pivot_b)
				{
					ss();
					rr();
				}
				else if (all()->a->next->num != dest_pivot_a)
				{
					sa();
					ra();
				}
				else if (all()->b->next->num != dest_pivot_b)
				{
					sb();
					rb();
				}
				if (all()->a->next->num == dest_pivot_a && all()->b->next->num == dest_pivot_b)
					break ;
			}
			dest_pivot_a = start_pivot_a;
			dest_pivot_b = start_pivot_b;
			start_pivot_a = find_start_pivot(all()->a ,start_pivot_a);
			start_pivot_b = find_start_pivot(all()->b ,start_pivot_b);
		}
		else if (!is_sort_complete(all()->a))
		{
			while (all()->a->num != start_pivot_a)
				rra();
			while (all()->a->next->num != dest_pivot_a)
			{
				sa();
				ra();
			}
			dest_pivot_a = start_pivot_a;
			start_pivot_a = find_start_pivot(all()->a ,start_pivot_a);
		}
		else if (all()->b && !is_sort_complete(all()->b))
		{
			while (all()->b->num != start_pivot_b)
				rrb();
			while (all()->b->next->num != dest_pivot_b)
			{
				sb();
				rb();
			}
			dest_pivot_b = start_pivot_b;
			start_pivot_b = find_start_pivot(all()->b ,start_pivot_b);
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
	//printf("devide end------\n");
	sort_stack();
	//printf("sort_stack end------\n");
	push_b_to_a();
	//printf("push_b_to_a end------\n");
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
		//sort_stack();
		//printf("pivot_a : %d, nxt_pivot a : %d\n", all()->a->num, find_dest_pivot(all()->a, all()->a->num));
		
	}
	// // removed

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
