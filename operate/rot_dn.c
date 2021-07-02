/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_dn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:49:28 by heom              #+#    #+#             */
/*   Updated: 2021/07/02 19:15:23 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

static void	rot_dn(t_item **top)
{
	(*top) = (*top)->prev;
}

void	rra(void)
{
	rot_dn(stack_a());
}

void	rrb(void)
{
	rot_dn(stack_b());
}

void	rrr(void)
{
	rot_dn(stack_a());
	rot_dn(stack_b());
}
