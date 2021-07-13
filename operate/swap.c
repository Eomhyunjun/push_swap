/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:43:35 by heom              #+#    #+#             */
/*   Updated: 2021/07/14 08:17:21 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void		sswap(t_item **top)
{
	t_item *second;
	t_item *third;
	t_item *last;

	second = (*top)->next;
	third = second->next;
	last = (*top)->prev;
	if (second == last)
	{
		second = (*top);
		(*top) = last;
		return ;
	}
	last->next = second;
	second->prev = last;
	second->next = (*top);
	(*top)->prev = second;
	(*top)->next = third;
	third->prev = (*top);

	(*top) = second;
}

void	sa(void)
{
	sswap(&all()->a);
	write(1, "sa\n", 3);
	//print_sort_list();
}

void	sb(void)
{
	sswap(&all()->b);
	write(1, "sb\n", 3);
	//print_sort_list();
}

void	ss(void)
{
	sswap(&all()->a);
	if (all()->b == NULL)
	{
		print_err("b does not exist");
		return ;
	}
	sswap(&all()->b);
	write(1, "ss\n", 3);
	//print_sort_list();
}