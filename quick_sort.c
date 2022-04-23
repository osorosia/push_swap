#include "push_swap.h"

void	quick_sort(t_dlst *a, t_dlst *b)
{
	dlst_compression(a);
	sort_a_1st(a, b, 0, dlst_all_size(a, b));
}
