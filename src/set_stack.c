/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:52:49 by heom              #+#    #+#             */
/*   Updated: 2021/06/07 14:59:51 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	set_stack(t_item **a, int cnt, char *argv[])
{
	int i;
	int num;

	i = 1;
	while(i <= cnt)
	{
		num = ft_atoi(argv[i]);
		sadd_bot(a, new_item(num));
		i++;
	}
	top_link_bot(*a);
}