#include "push_swap.h"

void dlst_del_back(t_dlst *dummy) {
	if (dummy->next->is_dummy)
		return;
	dummy->size--;
	t_dlst *target = dummy->prev;
	t_dlst *prev = target->prev;
	t_dlst *next = target->next;
	free(target);
	prev->next = next;
	next->prev = prev;
}

void dlst_del_front(t_dlst *dummy) {
	if (dummy->next->is_dummy)
		return;
	dummy->size--;
	t_dlst *target = dummy->next;
	t_dlst *prev = target->prev;
	t_dlst *next = target->next;
	free(target);
	prev->next = next;
	next->prev = prev;
}
