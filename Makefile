NAME         = push_swap
CHECKER      = checker

SRCS         = $(wildcard *.c)

OBJS_DIR     = objs
OBJS         = $(addprefix $(OBJS_DIR)/, $(subst checker.o,, $(SRCS:.c=.o)))
OBJS_CHECKER = $(addprefix $(OBJS_DIR)/, $(subst main.o,, $(SRCS:.c=.o)))

CFLAGS = -Wall -Wextra -Werror -g
# CFLAGS       = -g
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
	rm -f $(CHECKER)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: $(CHECKER)

# -------------------------------------------

norm:
	python3 -m norminette $(SRCS) | grep Error | cat

.PHONY: clone
clone:
	if [ ! -d ./push_swap_visualizer ]; then git clone -q https://github.com/o-reo/push_swap_visualizer.git -b v1-python; fi
	if [ ! -d ./push_swap_tester ]; then git clone -q https://github.com/nafuka11/push_swap_tester.git; fi

.PHONY: visual
visual: all clone
	cp ./push_swap_visualizer/pyviz.py ./
	python3 pyviz.py `ruby -e "puts (0..100).to_a.shuffle.join(' ')"`

.PHONY: small
small: fclean all bonus clone
	# cp checker_linux checker
	cd ./push_swap_tester \
	&& python3 push_swap_tester.py -l 1 \
	&& echo 'req   : 0' \
	&& python3 push_swap_tester.py -l 2 \
	&& echo 'req   : 1' \
	&& python3 push_swap_tester.py -l 3 \
	&& echo 'req   : 2~3' \
	&& python3 push_swap_tester.py -l 4 \
	&& echo 'req   : ~?' \
	&& python3 push_swap_tester.py -l 5 \
	&& echo 'req   : ~12'

.PHONY: big
big: fclean all bonus clone
	# cp checker_linux checker
	cd ./push_swap_tester \
	&& python3 push_swap_tester.py -l 100 \
	&& echo 'req   : ~700' \
	&& python3 push_swap_tester.py -l 500 \
	&& echo 'req   : ~5500'
