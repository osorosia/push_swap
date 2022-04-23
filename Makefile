NAME = push_swap
CHECKER = checker
SRCS = $(wildcard *.c)
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(subst checker.o,, $(SRCS:.c=.o)))
OBJS_CHECKER = $(addprefix $(OBJS_DIR)/, $(subst main.o,, $(SRCS:.c=.o)))
# CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -g
LIBFT = ./libft/libft.a

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) -o $@ $^

$(CHECKER): $(OBJS_CHECKER) $(LIBFT)
	cc $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C ./libft

$(OBJS_DIR)/%.o: %.c ./push_swap.h
	mkdir $(OBJS_DIR) 2>/dev/null; cc $(CFLAGS) -c -o $@ $<

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
