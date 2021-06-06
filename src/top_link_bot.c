/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_link_bot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:21:41 by heom              #+#    #+#             */
/*   Updated: 2021/06/06 15:22:00 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	top_link_bot(t_item *start)
{
	t_item	*last;
	
	last = stack_last(start);
	start->prev = last;
	last->next = start;
}