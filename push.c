/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:08:36 by rnishimo          #+#    #+#             */
/*   Updated: 2022/04/24 20:08:37 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_dlst *a, t_dlst *b, bool flag)
{
	if (b->next->is_dummy)
		return ;
	dlst_add_front(a, b->next->num);
	dlst_del_front(b);
	if (flag)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_dlst *a, t_dlst *b, bool flag)
{
	if (a->next->is_dummy)
		return ;
	dlst_add_front(b, a->next->num);
	dlst_del_front(a);
	if (flag)
		ft_putstr_fd("pb\n", 1);
}
