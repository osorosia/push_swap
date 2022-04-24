#include "push_swap.h"

void	dlst_del_back(t_dlst *dummy)
{
	t_dlst	*target;
	t_dlst	*prev;
	t_dlst	*next;

	target = dummy->prev;
	prev = target->prev;
	next = target->next;
	if (dummy->next->is_dummy)
		return ;
	dummy->size--;
	free(target);
	prev->next = next;
	next->prev = prev;
}

void	dlst_del_front(t_dlst *dummy)
{
	t_dlst	*target;
	t_dlst	*prev;
	t_dlst	*next;

	target = dummy->next;
	prev = target->prev;
	next = target->next;
	if (dummy->next->is_dummy)
		return ;
	dummy->size--;
	free(target);
	prev->next = next;
	next->prev = prev;
}
