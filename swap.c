/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:09:07 by rnishimo          #+#    #+#             */
/*   Updated: 2022/04/24 20:09:08 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_dlst *a, t_dlst *b, bool flag)
{
	t_dlst	*first;
	t_dlst	*second;
	long	tmp;

	(void)b;
	if (a->next->next->is_dummy)
		return ;
	first = a->next;
	second = first->next;
	tmp = first->num;
	first->num = second->num;
	second->num = tmp;
	if (flag)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_dlst *a, t_dlst *b, bool flag)
{
	t_dlst	*first;
	t_dlst	*second;
	long	tmp;

	(void)a;
	if (b->next->next->is_dummy)
		return ;
	first = b->next;
	second = first->next;
	tmp = first->num;
	first->num = second->num;
	second->num = tmp;
	if (flag)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_dlst *a, t_dlst *b, bool flag)
{
	sa(a, b, false);
	sb(a, b, false);
	if (flag)
		ft_putstr_fd("ss\n", 1);
}
