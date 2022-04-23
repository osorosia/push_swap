NAME         = push_swap
CHECKER      = checker

SRCS         = $(wildcard *.c)

OBJS_DIR     = objs
OBJS         = $(addprefix $(OBJS_DIR)/, $(subst checker.o,, $(SRCS:.c=.o)))
OBJS_CHECKER = $(addprefix $(OBJS_DIR)/, $(subst main.o,, $(SRCS:.c=.o)))

# CFLAGS = -Wall -Wextra -Werror -g
CFLAGS       = -g
LIBFT        = ./libft/libft.a

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
	rm -rf $(OBJS_DIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: $(CHECKER)

# -------------------------------------------

.PHONY: visual
visual: all
	if [ ! -d ./push_swap_visualizer ]; then git clone -q https://github.com/o-reo/push_swap_visualizer.git -b v1-python; fi
	cp ./push_swap_visualizer/pyviz.py ./
	python3 pyviz.py `ruby -e "puts (0..100).to_a.shuffle.join(' ')"`
