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
	t_item	*second;
	t_item	*pop;

	pop = *start;
	last = (*start)->prev;
	second = (*start)->next;
	last->next = second;
	second->prev = last;
	*start = second;
	pop->next = 0;
	pop->prev = 0;
	return (pop);
}



void		sadd_top(t_item **top, t_item *new)
{
	t_item	*last;
	t_item	*second;
		
	if (top == NULL || new == NULL)
		return ;
	if (*top == NULL)
	{
		*top = new;
		top_link_bot(*top);
		return ;
	}
	last = (*top)->prev;
	second = (*top)->next;

	new->next = *top;
	new->prev = (*top)->prev;
	last->next = new;
	second->prev = new;
	(*top) = new;
}
