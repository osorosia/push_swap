#include "push_swap.h"

long dlst_front_num(t_dlst *dummy, long index) {
	if (dlst_size(dummy) < index + 1)
		error("error: dlst_front_num()");
	dummy = dummy->next; 
	while (index > 0) {
		dummy = dummy->next;
		index--;
	}
	return dummy->num;
}

long dlst_back_num(t_dlst *dummy, long index) {
	if (dlst_size(dummy) < index + 1)
		error("error: dlst_back_num()");
	dummy = dummy->prev;
	while (index > 0) {
		dummy = dummy->prev;
		index--;
	}
	return dummy->num;
}

long get_min_in_dlst(t_dlst *dummy, long border) {
	long min = (long)INT_MAX + 1;

	dummy = dummy->next;
	while (!dummy->is_dummy) {
		if (dummy->num >= border && dummy->num < min)
			min = dummy->num;
		dummy = dummy->next;
	}
	return min;
}

long get_max_in_dlst(t_dlst *dummy, long border) {
	long max = (long)INT_MIN - 1;

	dummy = dummy->next;
	while (!dummy->is_dummy) {
		if (dummy->num <= border && dummy->num > max)
			max = dummy->num;
		dummy = dummy->next;
	}
	return max;
}
