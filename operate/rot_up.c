/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:50:09 by heom              #+#    #+#             */
/*   Updated: 2021/06/07 16:35:22 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

static void	rot_up(t_item **top)
{
	(*top) = (*top)->next;
}

void	ra(t_item **a)
{
	rot_up(a);
}

void	rb(t_item **b)
{
	rot_up(b);
}

void	rr(t_item **a, t_item **b)
{
	rot_up(a);
	rot_up(b);
}