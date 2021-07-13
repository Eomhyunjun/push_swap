/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:50:09 by heom              #+#    #+#             */
/*   Updated: 2021/07/14 08:17:03 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

static void	rot_up(t_item **top)
{
	(*top) = (*top)->next;
}

void	ra(void)
{
	rot_up(&all()->a);
	write(1, "ra\n", 3);
	//print_sort_list();
}

void	rb(void)
{
	rot_up(&all()->b);
	write(1, "rb\n", 3);
	//print_sort_list();
}

void	rr(void)
{
	rot_up(&all()->a);
	rot_up(&all()->b);
	write(1, "rr\n", 3);
	//print_sort_list();
}
