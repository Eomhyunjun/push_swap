/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:50:17 by heom              #+#    #+#             */
/*   Updated: 2021/07/14 08:17:15 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"
#include <stdio.h>

void	spush(t_item **start, t_item **dest)
{
	t_item	*pop_item;

		pop_item = spop_top(start);
		sadd_top(dest, new_item(pop_item->num));
		free(pop_item);
}

void	pa(void)
{
	spush(&all()->b, &all()->a);
	write(1, "pa\n", 3);
	//print_sort_list();
}

void	pb(void)
{
	spush(&all()->a, &all()->b);
	write(1, "pb\n", 3);
	//print_sort_list();
}
