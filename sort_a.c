#include "push_swap.h"

void	sort_a_move_1(t_dlst *a, t_dlst *b, long min, long size);

void	sort_a_move_2(t_dlst *a, t_dlst *b, long min, long size)
{
	long	i;

	i = 0;
	while (i < get_size(min, size, 1) || i < get_size(min, size, 2))
	{
		if (i < get_size(min, size, 1) && i < get_size(min, size, 2))
			rrr(a, b, true);
		else if (i < get_size(min, size, 1))
			rrb(a, b, true);
		else
			rra(a, b, true);
		i++;
	}
}

bool	sort_a_under_2(t_dlst *a, t_dlst *b, long min, long size)
{
	(void)min;
	if (size == 2)
	{
		if (dlst_front_num(a, 0) > dlst_front_num(a, 1))
			sa(a, b, true);
	}
	return (size <= 2);
}

void	sort_a(t_dlst *a, t_dlst *b, long min, long size)
{
	if (sort_a_under_2(a, b, min, size))
		return ;
	sort_a_move_1(a, b, min, size);
	sort_a_move_2(a, b, min, size);
	sort_a(a, b, get_min(min, size, 2), get_size(min, size, 2));
	sort_b(a, b, get_min(min, size, 1), get_size(min, size, 1));
	sort_b(a, b, get_min(min, size, 0), get_size(min, size, 0));
}
