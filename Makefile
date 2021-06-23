NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCS = main.c \
		src/is_all_argv_num.c \
		src/set_stack.c \
		src/sadd_bot.c \
		src/stack_last.c \
		src/new_item.c \
		src/top_link_bot.c \
		src/print_err.c \
		operate/op_unit.c \
		operate/push.c \
		operate/rot_dn.c \
		operate/rot_up.c \
		operate/swap.c \
		sort/stack_size.c \



OBJS = $(SRCS:.c=.o)

.c.o : $(SRCS)
		gcc $(CFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJS)
		make -C libft/ all
		cp libft/libft.a $@
		gcc -o $@ $@ $^

clean :
		$(RM) $(OBJS)
		make -C libft/ clean

fclean : clean
		$(RM) $(NAME)
		make -C libft/ fclean


re: fclean all

.PHONY: all, clean, fclean, re, bonus
