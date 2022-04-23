#include "push_swap.h"

void sort_b(t_dlst *a, t_dlst *b, long min, long size);
void sort_a(t_dlst *a, t_dlst *b, long min, long size);





void sort_a_1st(t_dlst *a, t_dlst *b, long min, long size) {
	long i;
	long tmp;

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

void quick_sort(t_dlst *a, t_dlst *b) {
	dlst_compression(a);
	sort_a_1st(a, b, 0, dlst_all_size(a, b));
}
