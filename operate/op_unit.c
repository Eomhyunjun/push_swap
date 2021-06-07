/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_unit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:09:51 by heom              #+#    #+#             */
/*   Updated: 2021/06/07 16:41:42 by heom             ###   ########.fr       */
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

