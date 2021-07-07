/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_dn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:49:28 by heom              #+#    #+#             */
/*   Updated: 2021/07/07 17:11:23 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

static void	rot_dn(t_item **top)
{
	(*top) = (*top)->prev;
}

void	rra(void)
{
	rot_dn(all()->a);
	write(1, "rra\n", 3);
}

void	rrb(void)
{
	rot_dn(all()->b);
	write(1, "rrb\n", 3);
}

void	rrr(void)
{
	rot_dn(all()->a);
	rot_dn(all()->b);
	write(1, "rrr\n", 3);
}
