#include "push_swap.h"

t_dlst *get_min_dlst_without_compressed(t_dlst *a) {
	long min = (long)INT_MAX + 1;
	t_dlst *dlst = NULL;

	a = a->next;
	while (!a->is_dummy) {
		if (!a->is_compression && (!dlst || min > a->num)) {
			min = a->num;
			dlst = a;
		}
		a = a->next;
	}
	return dlst;
}

void dlst_compression(t_dlst *a) {
	long i = 0;
	while (i < dlst_size(a)) {
		t_dlst *min = get_min_dlst_without_compressed(a);
		min->num = i;
		min->is_compression = true;
		i++;
	}
}
