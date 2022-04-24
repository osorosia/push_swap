/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:08:42 by rnishimo          #+#    #+#             */
/*   Updated: 2022/04/24 20:08:43 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_dlst *a, t_dlst *b, bool flag)
{
	(void)b;
	if (a->prev->prev->is_dummy)
		return ;
	dlst_add_front(a, a->prev->num);
	dlst_del_back(a);
	if (flag)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_dlst *a, t_dlst *b, bool flag)
{
	(void)a;
	if (b->prev->prev->is_dummy)
		return ;
	dlst_add_front(b, b->prev->num);
	dlst_del_back(b);
	if (flag)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_dlst *a, t_dlst *b, bool flag)
{
	rra(a, b, false);
	rrb(a, b, false);
	if (flag)
		ft_putstr_fd("rrr\n", 1);
}
