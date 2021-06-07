/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_dn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:49:28 by heom              #+#    #+#             */
/*   Updated: 2021/06/07 15:07:57 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

static void	rot_dn(t_item **top)
{
	(*top) = (*top)->prev;
}

void	rra(t_item **a)
{
	rot_dn(a);
}

void	rrb(t_item **b)
{
	rot_dn(b);
}

void	rrr(t_item **a, t_item **b)
{
	rot_dn(a);
	rot_dn(b);
}