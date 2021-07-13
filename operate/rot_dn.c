/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_dn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:49:28 by heom              #+#    #+#             */
/*   Updated: 2021/07/14 08:17:09 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

static void	rot_dn(t_item **top)
{
	(*top) = (*top)->prev;
}

void	rra(void)
{
	rot_dn(&all()->a);
	write(1, "rra\n", 4);
	//print_sort_list();
}

void	rrb(void)
{
	rot_dn(&all()->b);
	write(1, "rrb\n", 4);
	//print_sort_list();
}

void	rrr(void)
{
	rot_dn(&all()->a);
	rot_dn(&all()->b);
	write(1, "rrr\n", 4);
	//print_sort_list();
}
