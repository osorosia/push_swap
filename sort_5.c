/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:08:44 by rnishimo          #+#    #+#             */
/*   Updated: 2022/04/24 20:08:45 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_dlst *a, t_dlst *b)
{
	long	max;

	max = get_max_in_dlst(a, INT_MAX);
	while (dlst_back_num(a, 0) < max)
		ra(a, b, true);
	if (!check_sorted(a, NULL))
		sa(a, b, true);
}

void	sort_5(t_dlst *a, t_dlst *b)
{
	long	min1;
	long	min2;

	min1 = get_min_in_dlst(a, INT_MIN);
	min2 = get_min_in_dlst(a, min1 + 1);
	if (dlst_size(a) == 4)
		min2 = min1;
	while (dlst_size(a) > 3)
	{
		if (dlst_front_num(a, 0) <= min2)
			pb(a, b, true);
		else
			ra(a, b, true);
	}
	sort_3(a, b);
	if (dlst_size(b) == 2 && dlst_front_num(b, 0) < dlst_front_num(b, 1))
		sb(a, b, true);
	while (dlst_size(b) > 0)
		pa(a, b, true);
}
