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

test :
		gcc $(CFLAGS) src/*.c operate/*.c libft/*.c test.c -o test


re: fclean all

.PHONY: all, clean, fclean, re, bonus, test
