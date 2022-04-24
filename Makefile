NAME         = push_swap
CHECKER      = checker

SRCS         = \
check.c \
checker.c \
dlst_add.c \
dlst_compression.c \
dlst_del.c \
dlst_new.c \
dlst_num.c \
dlst_utils.c \
main.c \
numbers.c \
push.c \
rotate.c \
rrotate.c \
sort_5.c \
sort_a_1st.c \
sort_a.c \
sort_a_move.c \
sort_b.c \
sort_b_move.c \
sort.c \
sort_utils.c \
swap.c \
utils.c \

HEADER       = push_swap.h

OBJS_DIR     = objs
OBJS         = $(addprefix $(OBJS_DIR)/, $(subst checker.o,, $(SRCS:.c=.o)))
OBJS_CHECKER = $(addprefix $(OBJS_DIR)/, $(subst main.o,, $(SRCS:.c=.o)))

# CFLAGS       = -g
CFLAGS       = -Wall -Wextra -Werror -g
LIBFT        = ./libft/libft.a

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) -o $@ $^

$(CHECKER): $(OBJS_CHECKER) $(LIBFT)
	cc $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C ./libft

$(OBJS_DIR)/%.o: %.c $(HEADER)
	mkdir $(OBJS_DIR) 2>/dev/null; cc $(CFLAGS) -c -o $@ $<

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: $(CHECKER)

# -------------------------------------------

.PHONY: norm
norm:
	python3 -m norminette $(SRCS) $(HEADER) | grep Error | cat

.PHONY: test
test: fclean all bonus
	cp ./checker_linux ./.test/checker
	chmod 777 ./.test/checker
	cd ./.test \
	&& bash test.sh \
	&& bash test_error.sh \
	&& bash test_checker.sh \
	&& bash test_checker_error.sh \
	&& bash test_checker_stdin.sh \
	&& echo test OK!

.PHONY: mac
mac: fclean all bonus
	cp ./checker_Mac ./.test/checker
	chmod 777 ./.test/checker
	cd ./.test \
	&& bash test.sh \
	&& bash test_error.sh \
	&& bash test_checker.sh \
	&& bash test_checker_error.sh \
	&& bash test_checker_stdin.sh \
	&& echo test OK!

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
	&& python3 push_swap_tester.py -l 2 \
	&& python3 push_swap_tester.py -l 3 \
	&& python3 push_swap_tester.py -l 4 \
	&& python3 push_swap_tester.py -l 5

.PHONY: big
big: fclean all bonus clone
	# cp checker_linux checker
	cd ./push_swap_tester \
	&& python3 push_swap_tester.py -l 100 \
	&& python3 push_swap_tester.py -l 500
