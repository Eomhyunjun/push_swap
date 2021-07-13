#include "../push.h"

int		is_sort_complete(t_item *need_chk_list)
{
	int		now_num;
	int		next_num;
	t_item	*current;
	t_item	*stop;

	current = need_chk_list;
	stop = need_chk_list;
	while(current)
	{
		now_num = current->num;
		next_num = current->next->num;
		if (now_num > next_num)
			return (0);
		current = current->next;
		if (current->next == stop)
			break;
	}
	return (1);
}