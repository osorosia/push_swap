#include "push_swap.h"

void	sort_a_1st(t_dlst *a, t_dlst *b, long min, long size)
{
	long	i;
	long	tmp;

	i = 0;
	tmp = 0;
	while (i < size) {
		// pb
		if (dlst_front_num(a, 0) <= get_border(min, size, 0)) {
			pb(a, b, true);
			// rb(a, b, true);
			tmp++;
		}
		// pb rb
		else if (dlst_front_num(a, 0) <= get_border(min, size, 1)) {
			while (tmp > 0) {
				rb(a, b, true);
				tmp--;
			}
			pb(a, b, true);
		}
		// ra
		else {
			if (tmp > 0) {
				rr(a, b, true);
				tmp--;
			}
			else
				ra(a, b, true);
		}
		i++;
	}

	while (tmp-- > 0)
		rb(a, b, true);
	sort_a(a, b, get_min(min, size, 2), get_size(min, size, 2));
	sort_b(a, b, get_min(min, size, 1), get_size(min, size, 1));
	sort_b(a, b, get_min(min, size, 0), get_size(min, size, 0));
}

void sort_a(t_dlst *a, t_dlst *b, long min, long size) {
	long i;
	long tmp;

	if (size == 2) {
		if (dlst_front_num(a, 0) > dlst_front_num(a, 1))
			sa(a, b, true);
	}
	if (size <= 2)
		return;

	tmp = 0;
	i = 0;
	while (i < size) {
		// pb
		if (dlst_front_num(a, 0) <= get_border(min, size, 0)) {
			while (tmp > 0) {
				rb(a, b, true);
				tmp--;
			}
			pb(a, b, true);
		}
		// pb rb
		else if (dlst_front_num(a, 0) <= get_border(min, size, 1)) {
			pb(a, b, true);
			// rb(a, b, true);
			tmp++;
		}
		// ra
		else {
			if (tmp > 0) {
				rr(a, b, true);
				tmp--;
			}
			else
				ra(a, b, true);
		}
		i++;
	}

	while (tmp-- > 0)
		rb(a, b, true);

	i = 0;
	while (i < get_size(min, size, 1) || i < get_size(min, size, 2)) {
		if (i < get_size(min, size, 1) && i < get_size(min, size, 2))
			rrr(a, b, true);
		else if (i < get_size(min, size, 1))
			rrb(a, b, true);
		else
			rra(a, b, true);
		i++;
	}
	sort_a(a, b, get_min(min, size, 2), get_size(min, size, 2));
	sort_b(a, b, get_min(min, size, 1), get_size(min, size, 1));
	sort_b(a, b, get_min(min, size, 0), get_size(min, size, 0));
}
