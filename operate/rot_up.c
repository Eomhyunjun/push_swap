/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:50:09 by heom              #+#    #+#             */
/*   Updated: 2021/07/02 19:15:01 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

static void	rot_up(t_item **top)
{
	(*top) = (*top)->next;
}

void	ra(void)
{
	rot_up(stack_a());
}

void	rb(void)
{
	rot_up(stack_b());
}

void	rr(void)
{
	rot_up(stack_a());
	rot_up(stack_b());
}
