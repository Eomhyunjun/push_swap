NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

MAIN = main \

SRC =	\
		is_all_argv_num \
		set_stack \
		sadd_bot \
		stack_last \
		new_item \
		top_link_bot \
		safe_exit \

OPERATE = \
		op_unit \
		push \
		rot_dn \
		rot_up \
		swap \

SORT = \
		stack_size \
		put_a_in_arr \
		quick_sort \

MAND_FIL = \
			$(addsuffix .c, $(MAIN)) \
			$(addsuffix .c, $(addprefix src/, $(SRC))) \
			$(addsuffix .c, $(addprefix operate/, $(OPERATE))) \
			$(addsuffix .c, $(addprefix sort/, $(SORT))) \

MAND_OBJS = $(MAND_FIL:.c=.o)


$(MAND_OBJS): %.o : %.c
		gcc $(CFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(MAND_OBJS)
		make -C libft/ all
		cp libft/libft.a $@
		gcc -o $@ $@ $^

clean :
		$(RM) $(MAND_OBJS)
		make -C libft/ clean

fclean : clean
		$(RM) $(NAME)
		make -C libft/ fclean


re: fclean all

.PHONY: all, clean, fclean, re, bonus
