#include "push_swap.h"

t_dlst	*dlst_new_dummy(void)
{
	t_dlst	*dlst;

	dlst = ft_calloc(1, sizeof(t_dlst));
	if (dlst == NULL)
		error("malloc error");
	dlst->prev = dlst;
	dlst->next = dlst;
	dlst->is_dummy = true;
	return (dlst);
}

t_dlst	*dlst_new(t_dlst *prev, t_dlst *next, long num)
{
	t_dlst	*dlst;

	dlst = ft_calloc(1, sizeof(t_dlst));
	if (dlst == NULL)
		error("malloc error");
	dlst->prev = prev;
	dlst->next = next;
	dlst->num = num;
	dlst->is_dummy = false;
	return (dlst);
}
