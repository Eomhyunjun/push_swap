#ifndef PUSH_H
# define PUSH_H

//--remove
#include <stdio.h>


# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	struct	s_item	*name;
	int				len;
}				t_stack;


typedef struct		s_item
{
	int				num;
	struct s_item	*next;
	struct s_item	*prev;
}					t_item;

void		print_err(char *msg);
void		safe_exit(int code, char * msg);

int			is_all_argv_num(char *argv[]);

/*
**----------
*/

void		set_stack(t_item **a, int cnt, char *argv[]);
void		sadd_bot(t_item **top, t_item *new);
t_item		*stack_last(t_item *lst);
t_item		*new_item(int num);
void		top_link_bot(t_item *start);
/*
**------- operate functions
*/

void		spush(t_item **start, t_item **dest);
void		sswap(t_item **top);
void		sadd_bot(t_item **top, t_item *new);
void		sadd_top(t_item **top, t_item *new);
t_item		*spop_top(t_item **top);

void		sa(t_item **a);
void		sb(t_item **b);
void		ss(t_item **a, t_item **b);

void		pa(t_item **a, t_item **b);
void		pb(t_item **a, t_item **b);

void		ra(t_item **a);
void		rb(t_item **b);
void		rr(t_item **a, t_item **b);
void		rra(t_item **a);
void		rrb(t_item **b);
void		rrr(t_item **a, t_item **b);

/*
**------------------sort functions
*/

void		sort_algo(t_item **a);
void		pre_sort(t_item *a);

void		put_a_in_arr(t_item *a, int *a_arr);
int			stack_size(t_item *a);
void		quick_sort(int *arr, int start, int end);
#endif
