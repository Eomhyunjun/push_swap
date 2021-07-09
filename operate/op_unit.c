/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_unit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:09:51 by heom              #+#    #+#             */
/*   Updated: 2021/06/08 10:52:26 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

t_item	*spop_top(t_item **start)
{
	t_item	*last;
	t_item	*ori_first;
	t_item	*pop;

	pop = *start;
	if ((*start)->prev == *start)
		*start = 0;
	else
	{
		last = (*start)->prev;
		ori_first = (*start)->next;
		last->next = ori_first;
		ori_first->prev = last;
		*start = ori_first;
	}
	pop->next = 0;
	pop->prev = 0;
	return (pop);
}



void		sadd_top(t_item **top, t_item *new)
{
	t_item	*last;
	t_item	*ori_first;
		
	if (top == NULL || new == NULL)
		return ;
	if (*top == NULL)
	{
		*top = new;
		top_link_bot(*top);
		return ;
	}
	last = (*top)->prev;
	ori_first = (*top);

	new->next = *top;
	new->prev = last;
	last->next = new;
	ori_first->prev = new;
	(*top) = new;
}
