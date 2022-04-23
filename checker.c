#include "push_swap.h"

bool check_operation(char *op, char *str) {
    const long len = ft_strlen(op);

    if (ft_strncmp(op, str, len) != 0)
        return false;
	if (str[len] != '\0' && str[len] != '\n')
        return false;
    return true;
}

void stdin_loop(t_dlst *a, t_dlst *b) {
    char	*line;

	while (true)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (check_operation("rra", line)) rra(a, b, false);
		else if (check_operation("rrb", line)) rrb(a, b, false);
		else if (check_operation("rrr", line)) rrr(a, b, false);
		else if (check_operation("ra", line)) ra(a, b, false);
		else if (check_operation("rb", line)) rb(a, b, false);
		else if (check_operation("rr", line)) rr(a, b, false);
		else if (check_operation("pa", line)) pa(a, b, false);
		else if (check_operation("pb", line)) pb(a, b, false);
		else if (check_operation("sa", line)) sa(a, b, false);
		else if (check_operation("sb", line)) sb(a, b, false);
		else if (check_operation("ss", line)) ss(a, b, false);
		else error("Error");
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

    if (check_sorted(a, b))
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);

    dlst_free(a);
    dlst_free(b);
}
