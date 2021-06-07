#ifndef PUSH_H
# define PUSH_H

//--remove
#include <stdio.h>


# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_all
{
	struct s_item *cont;
}				t_all;


typedef struct		s_item
{
	int				num;
	struct s_item	*next;
	struct s_item	*prev;
}					t_item;

void		print_err(char *msg);

int			is_all_argv_num(char *argv[]);

void		set_stack(t_item **a, int cnt, char *argv[]);
void		sadd_bot(t_item **top, t_item *new);
t_item		*stack_last(t_item *lst);
t_item		*new_item(int num);
void		top_link_bot(t_item *start);

void		spush(t_item *start, t_item *dest);
void		sswap(t_item **top);
void		sadd_bot(t_item **top, t_item *new);
void		sadd_top(t_item **top, t_item *new);
t_item		*spop_top(t_item **top);

void	sa(t_item **a);
void	sb(t_item **b);
void	ss(t_item **a, t_item **b);

void	pa(t_item *a, t_item *b);
void	pb(t_item *a, t_item *b);

void	ra(t_item **a);
void	rb(t_item **b);
void	rr(t_item **a, t_item **b);
void	rra(t_item **a);
void	rrb(t_item **b);
void	rrr(t_item **a, t_item **b);


#endif