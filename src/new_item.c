/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:10:52 by heom              #+#    #+#             */
/*   Updated: 2021/06/06 14:28:57 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

t_item		*new_item(int num)
{
	t_item *new;

	new = (t_item *)malloc(sizeof(t_item));
	if (new == NULL)
		return (NULL);
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}