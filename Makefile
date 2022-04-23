NAME = push_swap
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
# CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -g
LIBFT = ./libft/libft.a

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c ./push_swap.h
	cc $(CFLAGS) -c -o $@ $<

$(LIBFT):
	make -C ./libft

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
