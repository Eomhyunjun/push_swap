/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sadd_bot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:54:01 by heom              #+#    #+#             */
/*   Updated: 2021/06/06 14:54:12 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	sadd_bot(t_item **top, t_item *new)
{
	t_item *last;
	if (top == NULL || new == NULL)
		return ;
	if (*top == NULL)
	{
		*top = new;
		return ;
	}
	last = stack_last(*top);
	last->next = new;
	(*top)->prev = new;
	new->prev = last;
}