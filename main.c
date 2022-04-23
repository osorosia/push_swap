#include "push_swap.h"

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
	if (!check_sorted(a, b))
		sort(a, b);
	dlst_free(a);
	dlst_free(b);
}
