#include <stdio.h>
#include "push.h"

void print_stack(t_item *top)
{
	printf("top|");
	t_item *bot = top->next;
	t_item *item = top;
	while(item != bot)
	{
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d", item->num);
	printf("|bot\n");
}

// void test_spush() {
// 	t_item *a;
// 	a->prev = &a;
// 	a->next = &a;
// 	a->num = 10;

// 	t_item b;
// 	b.prev = &b;
// 	b.next = &b;
// 	b.num = 20;

// 	//spush(&b, &a);
// 	sswap(&a);
// 	print_stack(&a);
// }

int		main(int argc, char *argv[])
{
	
	t_item	*a;
	// t_item	*b;

	a = 0;
	// b->num = 3;
	// b->next = 0;
	// b->prev = 0;
	if (argc >= 2)
	{
		if (!is_all_argv_num(argv))
			return (0);
		set_stack(&a, argc - 1, argv);
		ra(&a);
		
		// sort_algo(&a, &b);

		//remove--------------------------
		argc -= 2;
		while (argc-- >= 0)
		{
			printf("%d\n", a->num);
			a = a->next;
		}
	}
	// test_spush();
	return (0);
}