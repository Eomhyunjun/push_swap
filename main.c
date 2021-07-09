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
	all()->sort = arr;
}

void	sort_algo(t_item **a)
{
	pre_sort(*a);
}

int		is_sort_complete(t_item *need_chk_list)
{
	int		now_num;
	int		next_num;
	t_item	*current;
	t_item	*stop;

	current = need_chk_list;
	stop = need_chk_list;
	while(1)
	{
		now_num = all()->a->num;
		next_num = all()->a->next->num;
		if (now_num > next_num)
			return (1);
		current = current->next;
		if (current->next == stop)
			break;
	}
	return (0);
}

void	work_game(void)
{
	int		now_a;
	int		next_a;
	int		now_b;
	int		next_b;

	pb();
	pb();
	while (1)
	{
		now_a = all()->a->num;
		next_a = all()->a->next->num;
		now_b = all()->b->num;
		next_b = all()->b->next->num;
		if (now_a > next_a && now_b > next_b)
			ss();
		if (stack_size(all()->b) >= stack_size(all()->a))
			break;
		pb();
	}
	//removed
	write(1, "---devide_end----\n",20);
	while (1)
	{
		now_a = all()->a->num;
		next_a = all()->a->next->num;
		now_b = all()->b->num;
		next_b = all()->b->next->num;
		if (now_a > next_a && now_b > next_b)
			ss();
		else
		{
			if (now_a > next_a)
				sa();
			if (now_b > next_b)
				sb();
		}
		if (is_sort_complete(all()->a) && is_sort_complete(all()->b))
			break;
		else if (is_sort_complete(all()->a) && !is_sort_complete(all()->b))
			rrb();
		else if (!is_sort_complete(all()->a) && is_sort_complete(all()->b))
			rra();
		else
			rrr();
		// //removed
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
	}
}

int		main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		if (!is_all_argv_num(argv))
			return (0);
		set_stack(&all()->a, argc - 1, argv);
		sort_algo(&all()->a);
		work_game();
	}

	// removed
	t_item *current;
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
	printf("----after_sort-----\n");
	int	i;

	i = 0;
	while (all()->sort[i])
	{
		printf("%d : %d\n", i, all()->sort[i]);
		i++;
	}
	free(all()->sort);
	return (0);
}
