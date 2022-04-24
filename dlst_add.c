#include "push_swap.h"

void	dlst_add_numbers(t_dlst *dummy, char **numbers)
{
	long	i;

	i = 0;
	while (numbers[i])
	{
		dlst_add_back(dummy, atoi_or_err(numbers[i]));
		i++;
	}
}

void	dlst_add_back(t_dlst *dummy, long num)
{
	t_dlst	*prev;
	t_dlst	*next;
	t_dlst	*new;

	dummy->size++;
	prev = dummy->prev;
	next = dummy;
	new = dlst_new(prev, next, num);
	prev->next = new;
	next->prev = new;
}

void	dlst_add_front(t_dlst *dummy, long num)
{
	t_dlst	*prev;
	t_dlst	*next;
	t_dlst	*new;

	dummy->size++;
	prev = dummy;
	next = dummy->next;
	new = dlst_new(prev, next, num);
	prev->next = new;
	next->prev = new;
}
