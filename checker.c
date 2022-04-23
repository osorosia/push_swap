#include "push_swap.h"

bool check_op_str(char *op, char *str) {
    const long len = ft_strlen(op);

    if (ft_strncmp(op, str, len) != 0)
        return false;
	if (str[len] != '\0' && str[len] != '\n')
        return false;
    return true;
}

bool check_op(t_dlst *a, t_dlst *b, char *line) {
    bool flag = false;

	if (check_op_str("rra", line) && (flag = true))
        rra(a, b, false);
    else if (check_op_str("rrb", line) && (flag = true))
        rrb(a, b, false);
    else if (check_op_str("rrr", line) && (flag = true))
        rrr(a, b, false);
    else if (check_op_str("ra", line) && (flag = true))
        ra(a, b, false);
    else if (check_op_str("rb", line) && (flag = true))
        rb(a, b, false);
    else if (check_op_str("rr", line) && (flag = true))
        rr(a, b, false);
    else if (check_op_str("pa", line) && (flag = true))
        pa(a, b, false);
    else if (check_op_str("pb", line) && (flag = true))
        pb(a, b, false);
    else if (check_op_str("sa", line) && (flag = true))
        sa(a, b, false);
    else if (check_op_str("sb", line) && (flag = true))
        sb(a, b, false);
    else if (check_op_str("ss", line) && (flag = true))
        ss(a, b, false);
    return flag;
}

void stdin_loop(t_dlst *a, t_dlst *b) {
    char	*line;

	while (true)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (!check_op(a, b, line))
            error("Error");
		free(line);
	}
}

int main(int argc, char **argv) {
    t_dlst *a;
    t_dlst *b;
    char **numbers;
    
    if (argc < 2)
        exit(0);
    a = dlst_new_dummy();
    b = dlst_new_dummy();
    numbers = create_number_strs(argc, argv);
    dlst_add_numbers(a, numbers);
    free_number_strs(numbers);

    if (check_duplicate_number(a))
        error("Error");

    stdin_loop(a, b);

    // print_dlst("a", a);
    // print_dlst("b", b);

    if (check_sorted(a, b))
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);

    dlst_free(a);
    dlst_free(b);
}
