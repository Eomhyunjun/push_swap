#include "../push.h"

void	devide_num(void)
{
	int		min_num;
	int		max_num;
	int		now_num;
	int		stop_num;

	min_num = all()->sort[0];
	max_num = all()->sort[arr_last_idx(all()->sort) - 1];
	all()->min_num = min_num;
	all()->max_num = max_num;
	stop_num = all()->a->prev->num;
	while (1)
	{
		now_num = all()->a->num;
		if (now_num == min_num || now_num == max_num)
			ra();
		else
			pb();
		if (all()->a->num == stop_num)
			break;
		if (all()->b)
		{
			if (stack_size(all()->a) <= stack_size(all()->b))
				break ;
		}
	}
}