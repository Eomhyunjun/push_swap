
# include "../push.h"
void	dupcheck(int *arr)
{
	int i;

	i = 0;
	while(arr[i + 1])
	{
		if (arr[i] == arr[i + 1])
			safe_exit(1, "Duplicate number.");
		i++;
	}
}