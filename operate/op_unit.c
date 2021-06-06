/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_unit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:09:51 by heom              #+#    #+#             */
/*   Updated: 2021/06/06 17:34:26 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

t_item	*spop_top(t_item **start)
{
	t_item	*last;
	t_item	*second;
	t_item	*pop;

	pop = *start;
	last = (*start)->prev;
	second = (*start)->next;
	last->next = second;
	second->prev = last;
	*start = second;
	return (pop);
}



void		sadd_top(t_item **top, t_item *new)
{
	if (top == NULL || (*top) == NULL)
	{
		print_err("top has no element");
		return ;
	}
	if (new == NULL)
	{
		print_err("new has no element");
		return ;
	}
	new->next = *top;
	new->prev = (*top)->prev;
	(*top)->prev->next = new;
	(*top)->prev = new;
	(*top) = new;
}

void	spush(t_item *start, t_item *dest)
{
	t_item	*pop_item;

	if (start == 0)
	{
		print_err("start has no element");
		return ;
	}
	pop_item = spop_top(&start);
	sadd_top(&dest, pop_item);
}

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