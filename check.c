/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:08:08 by rnishimo          #+#    #+#             */
/*   Updated: 2022/04/24 20:08:10 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_sorted(t_dlst *a, t_dlst *b)
{
	if (b && dlst_size(b) > 0)
		return (false);
	a = a->next->next;
	while (!a->is_dummy)
	{
		if (a->num < a->prev->num)
			return (false);
		a = a->next;
	}
	return (true);
}

bool	check_duplicate_number(t_dlst *dummy)
{
	t_dlst	*target;
	t_dlst	*comp;

	target = dummy->next;
	while (!target->is_dummy)
	{
		comp = target->next;
		while (!comp->is_dummy)
		{
			if (target->num == comp->num)
				return (true);
			comp = comp->next;
		}
		target = target->next;
	}
	return (false);
}
