/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_compression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:08:11 by rnishimo          #+#    #+#             */
/*   Updated: 2022/04/24 20:08:12 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*get_min_dlst_without_compressed(t_dlst *a)
{
	long	min;
	t_dlst	*dlst;

	min = (long)INT_MAX + 1;
	dlst = NULL;
	a = a->next;
	while (!a->is_dummy)
	{
		if (!a->is_compression && (!dlst || min > a->num))
		{
			min = a->num;
			dlst = a;
		}
		a = a->next;
	}
	return (dlst);
}

void	dlst_compression(t_dlst *a)
{
	long	i;
	t_dlst	*min;

	i = 0;
	while (i < dlst_size(a))
	{
		min = get_min_dlst_without_compressed(a);
		min->num = i;
		min->is_compression = true;
		i++;
	}
}
