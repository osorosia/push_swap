NAME = push_swap
CHECKER = checker
SRCS = $(wildcard *.c)
OBJS = $(subst checker.o,, $(SRCS:.c=.o))
OBJS_CHECKER = $(subst main.o,, $(SRCS:.c=.o))
# CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -g
LIBFT = ./libft/libft.a

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) -o $@ $^

$(CHECKER): $(OBJS_CHECKER) $(LIBFT)
	cc $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C ./libft

%.o: %.c ./push_swap.h
	cc $(CFLAGS) -c -o $@ $<

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: $(CHECKER)
