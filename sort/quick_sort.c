/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:29:00 by heom              #+#    #+#             */
/*   Updated: 2021/07/09 15:11:16 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	ft_swap(int *l_arr, int *r_arr)
{
	int tmp;

	tmp = *l_arr;
	*l_arr = *r_arr;
	*r_arr = tmp;
}

void	quick_sort(int *arr, int start, int end)
{
	int	s_pnt;
	int	e_pnt;
	int	pivot;

	s_pnt = start;
	e_pnt = end;
	pivot = arr[start];
	if (start >= end)
		return ;
	while (s_pnt < e_pnt)
	{
		while (arr[s_pnt] <= pivot && s_pnt < end)
			s_pnt++;
		while (arr[e_pnt] > pivot && e_pnt > start)
			e_pnt--;
		if (s_pnt >= e_pnt)
			break ;
		ft_swap(&arr[s_pnt], &arr[e_pnt]);
	}
	ft_swap(&arr[start], &arr[e_pnt]);
	quick_sort(arr, start, e_pnt - 1);
	quick_sort(arr, e_pnt + 1, end);
}
