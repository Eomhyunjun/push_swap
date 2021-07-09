/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:50:17 by heom              #+#    #+#             */
/*   Updated: 2021/07/09 14:38:26 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	spush(t_item **start, t_item **dest)
{
	t_item	*pop_item;

		pop_item = spop_top(start);
		sadd_top(dest, pop_item);
}

void	pa(void)
{
	spush(&all()->b, &all()->a);
	write(1, "pa\n", 3);
}

void	pb(void)
{
	spush(&all()->a, &all()->b);
	write(1, "pb\n", 3);
}
