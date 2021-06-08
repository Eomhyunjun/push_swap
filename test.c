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
	t_item	*b;

	a = 0;
	b = 0;
	sadd_bot(&b, new_item(4444));
	sadd_bot(&b, new_item(55555));
	top_link_bot(b);
	if (argc >= 2)
	{
		if (!is_all_argv_num(argv))
			return (0);
		set_stack(&a, argc - 1, argv);
		ss(&a, &b);
		//rr(&a, &b);
		
		// sort_algo(&a, &b);

		//remove--------------------------
		t_item *a_next = a;
		while (a != 0)
		{
			printf("%d\n", a_next->num);
			if (a != a_next->next)
				a_next = a_next->next;
			else
				break ;
		}
		printf("-----------\n");
		t_item *b_next = b;
		while (b != 0)
		{
			printf("%d\n", b_next->num);
			if (b != b_next->next)
				b_next = b_next->next;
			else
				break ;
		}
	}
	// test_spush();
	return (0);
}