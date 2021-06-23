/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:23:33 by heom              #+#    #+#             */
/*   Updated: 2021/06/23 19:25:38 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	print_err(char *msg)
{
	int	num;

	num = ft_strlen(msg);
	write(2,"Error\n",6);
	write(2, msg, num);
	write(2, "\n", 1);
}

void	safe_exit(int code, char * msg)
{
	if (msg && msg[0])
		print_err(msg);
	exit(code);
}
