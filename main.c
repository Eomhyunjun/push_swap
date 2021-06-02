/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:11:25 by heom              #+#    #+#             */
/*   Updated: 2021/06/02 20:59:09 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct		s_cont
{
	int				num;
	struct s_cont	*next;
	struct s_cont	*prev;
}					t_cont;

int		is_all_argv_num(char *argv[])
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

void	set_list(t_list *stack_a, t_list *stack_b)
{
	//a에 인자로 받은 값 전달
	//b에는 형식만 전달
}

int		main(int argc, char *argv[])
{
	t_list	stack_a;
	t_list	stack_b;

	if (argc >= 2)
	{
		if (!is_all_argv_num(argv))
			return (0);
		set_list(&stack_a, &stack_b);
	}
	return (0);
}