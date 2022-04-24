/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:08:39 by rnishimo          #+#    #+#             */
/*   Updated: 2022/04/24 20:08:40 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_dlst *a, t_dlst *b, bool flag)
{
	(void)b;
	if (a->next->next->is_dummy)
		return ;
	dlst_add_back(a, a->next->num);
	dlst_del_front(a);
	if (flag)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_dlst *a, t_dlst *b, bool flag)
{
	(void)a;
	if (b->next->next->is_dummy)
		return ;
	dlst_add_back(b, b->next->num);
	dlst_del_front(b);
	if (flag)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_dlst *a, t_dlst *b, bool flag)
{
	ra(a, b, false);
	rb(a, b, false);
	if (flag)
		ft_putstr_fd("rr\n", 1);
}
