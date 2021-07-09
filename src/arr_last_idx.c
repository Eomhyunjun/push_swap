#include "../push.h"

int		arr_last_idx(int *arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}