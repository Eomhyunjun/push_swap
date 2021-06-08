/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:50:17 by heom              #+#    #+#             */
/*   Updated: 2021/06/08 10:51:14 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	spush(t_item **start, t_item **dest)
{
	t_item	*pop_item;
	
		pop_item = spop_top(start);
		sadd_top(dest, pop_item);
}

void	pa(t_item **a, t_item **b)
{
	spush(b, a);
}

void	pb(t_item **a, t_item **b)
{
	spush(a, b);
}