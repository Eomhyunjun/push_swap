/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_a_in_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:32:03 by heom              #+#    #+#             */
/*   Updated: 2021/06/23 19:32:57 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	put_a_in_arr(t_item *a, int *a_arr)
{
	int i;
	t_item *a_start;

	i = 0;
	a_start = a;
	while(1)
	{
		a_arr[i] = a_start->num;
		a_start = a_start->next;
		i++;
		if (a_start == a)
			break;
	}
	a_arr[i] = '\0';
}
