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

t_item		*stack_a(void);
t_item		*stack_b(void);


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

void		sa(void);
void		sb(void);
void		ss(void);

void		pa(void);
void		pb(void);

void		ra(void);
void		rb(void);
void		rr(void);
void		rra(void);
void		rrb(void);
void		rrr(void);

/*
**------------------sort functions
*/

void		sort_algo(t_item **a);
void		pre_sort(t_item *a);

void		put_a_in_arr(t_item *a, int *a_arr);
int			stack_size(t_item *a);
void		quick_sort(int *arr, int start, int end);
#endif
