#include "push_swap.h"

void	quick_sort(t_dlst *a, t_dlst *b)
{
	dlst_compression(a);
	sort_a_1st(a, b, 0, dlst_all_size(a, b));
}

void	sort(t_dlst *a, t_dlst *b)
{
	if (dlst_size(a) <= 5)
		sort_5(a, b);
	else
		quick_sort(a, b);
}
