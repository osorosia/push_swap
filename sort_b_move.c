/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:08:53 by rnishimo          #+#    #+#             */
/*   Updated: 2022/04/24 20:08:55 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_move_1_low(t_dlst *a, t_dlst *b, long *tmp)
{
	if (*tmp > 0)
	{
		rr(a, b, true);
		(*tmp)--;
	}
	else
		rb(a, b, true);
}

void	sort_b_move_1_mid(t_dlst *a, t_dlst *b, long *tmp)
{
	pa(a, b, true);
	(*tmp)++;
}

void	sort_b_move_1_high(t_dlst *a, t_dlst *b, long *tmp)
{
	while (*tmp > 0)
	{
		ra(a, b, true);
		(*tmp)--;
	}
	pa(a, b, true);
}

void	sort_b_move_1(t_dlst *a, t_dlst *b, long min, long size)
{
	long	tmp;
	long	i;

	tmp = 0;
	i = 0;
	while (i < size)
	{
		if (dlst_front_num(b, 0) <= get_border(min, size, 0))
			sort_b_move_1_low(a, b, &tmp);
		else if (dlst_front_num(b, 0) <= get_border(min, size, 1))
			sort_b_move_1_mid(a, b, &tmp);
		else
			sort_b_move_1_high(a, b, &tmp);
		i++;
	}
	while (tmp-- > 0)
		ra(a, b, true);
}
