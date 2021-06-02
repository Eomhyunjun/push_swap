NAME = push_swap

CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c \

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
