/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:04:44 by heom              #+#    #+#             */
/*   Updated: 2021/07/07 17:07:21 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_all	*all(void)
{
	static t_all	all;

	return (&all);
}
