#include "push_swap.h"

void	sort_b_move_1(t_dlst *a, t_dlst *b, long min, long size);

bool	sort_b_under_2(t_dlst *a, t_dlst *b, long min, long size)
{
	(void)min;
	if (size == 2)
	{
		if (dlst_front_num(b, 0) < dlst_front_num(b, 1))
			sb(a, b, true);
		pa(a, b, true);
		pa(a, b, true);
	}
	if (size == 1)
		pa(a, b, true);
	if (size <= 2)
		return (true);
	return (false);
}

void	sort_b_move_2(t_dlst *a, t_dlst *b, long min, long size)
{
	long	i;

	i = 0;
	while (i < get_size(min, size, 0) || i < get_size(min, size, 1))
	{
		if (i < get_size(min, size, 0) && i < get_size(min, size, 1))
			rrr(a, b, true);
		else if (i < get_size(min, size, 0))
			rrb(a, b, true);
		else
			rra(a, b, true);
		i++;
	}
}

void	sort_b(t_dlst *a, t_dlst *b, long min, long size)
{
	if (sort_b_under_2(a, b, min, size))
		return ;
	sort_b_move_1(a, b, min, size);
	sort_a(a, b, get_min(min, size, 2), get_size(min, size, 2));
	sort_b_move_2(a, b, min, size);
	sort_a(a, b, get_min(min, size, 1), get_size(min, size, 1));
	sort_b(a, b, get_min(min, size, 0), get_size(min, size, 0));
}
