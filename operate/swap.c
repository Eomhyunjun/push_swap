/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:43:35 by heom              #+#    #+#             */
/*   Updated: 2021/06/07 16:42:02 by heom             ###   ########.fr       */
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

	last->next = second;
	second->prev = last;
	second->next = (*top);
	(*top)->prev = second;
	(*top)->next = third;
	third->prev = (*top);

	(*top) = second;
}

void	sa(t_item **a)
{
	sswap(a);
}

void	sb(t_item **b)
{
	sswap(b);
}

void	ss(t_item **a, t_item **b)
{
	sswap(a);
	sswap(b);
}