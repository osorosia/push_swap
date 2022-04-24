#include "push_swap.h"

void	sort_a_1st_move_low(t_dlst *a, t_dlst *b, long *tmp)
{
	pb(a, b, true);
	(*tmp)++;
}

void	sort_a_1st_move_mid(t_dlst *a, t_dlst *b, long *tmp)
{
	while (*tmp > 0)
	{
		rb(a, b, true);
		(*tmp)--;
	}
	pb(a, b, true);
}

void	sort_a_1st_move_high(t_dlst *a, t_dlst *b, long *tmp)
{
	if (*tmp > 0)
	{
		rr(a, b, true);
		(*tmp)--;
	}
	else
		ra(a, b, true);
}

void	sort_a_1st_move(t_dlst *a, t_dlst *b, long min, long size)
{
	long	i;
	long	tmp;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		if (dlst_front_num(a, 0) <= get_border(min, size, 0))
			sort_a_1st_move_low(a, b, &tmp);
		else if (dlst_front_num(a, 0) <= get_border(min, size, 1))
			sort_a_1st_move_mid(a, b, &tmp);
		else
			sort_a_1st_move_high(a, b, &tmp);
		i++;
	}
	while (tmp-- > 0)
		rb(a, b, true);
}

void	sort_a_1st(t_dlst *a, t_dlst *b, long min, long size)
{
	sort_a_1st_move(a, b, min, size);
	sort_a(a, b, get_min(min, size, 2), get_size(min, size, 2));
	sort_b(a, b, get_min(min, size, 1), get_size(min, size, 1));
	sort_b(a, b, get_min(min, size, 0), get_size(min, size, 0));
}
