#include "push_swap.h"

void dlst_add_numbers(t_dlst *dummy, char **numbers) {
	long i;

	i = 0;
	while (numbers[i]) {
		dlst_add_back(dummy, atoi_or_err(numbers[i]));
		i++;
	}
}

void dlst_add_back(t_dlst *dummy, long num) {
	dummy->size++;
	t_dlst *prev = dummy->prev;
	t_dlst *next = dummy;

	t_dlst *new = dlst_new(prev, next, num);
	prev->next = new;
	next->prev = new;
}

void dlst_add_front(t_dlst *dummy, long num) {
	dummy->size++;
	t_dlst *prev = dummy;
	t_dlst *next = dummy->next;

	t_dlst *new = dlst_new(prev, next, num);
	prev->next = new;
	next->prev = new;
}
