/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:08:34 by rnishimo          #+#    #+#             */
/*   Updated: 2022/04/24 20:08:35 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define MAX_NUMBERS_LEN 10000

typedef struct s_dlst	t_dlst;
struct s_dlst
{
	t_dlst	*prev;
	t_dlst	*next;
	bool	is_dummy;
	bool	is_compression;
	long	num;
	long	size;
};

// check.c
bool	check_sorted(t_dlst *a, t_dlst *b);
bool	check_duplicate_number(t_dlst *dummy);

// numbers.c
char	**create_number_strs(int argc, char **argv);
void	free_number_strs(char **numbers);

// swap.c
void	sa(t_dlst *a, t_dlst *b, bool flag);
void	sb(t_dlst *a, t_dlst *b, bool flag);
void	ss(t_dlst *a, t_dlst *b, bool flag);

// push.c
void	pa(t_dlst *a, t_dlst *b, bool flag);
void	pb(t_dlst *a, t_dlst *b, bool flag);

// rotate.c
void	ra(t_dlst *a, t_dlst *b, bool flag);
void	rb(t_dlst *a, t_dlst *b, bool flag);
void	rr(t_dlst *a, t_dlst *b, bool flag);

// rrotate.c
void	rra(t_dlst *a, t_dlst *b, bool flag);
void	rrb(t_dlst *a, t_dlst *b, bool flag);
void	rrr(t_dlst *a, t_dlst *b, bool flag);

// dlst.c
t_dlst	*dlst_new_dummy(void);
t_dlst	*dlst_new(t_dlst *prev, t_dlst *next, long num);
void	dlst_add_numbers(t_dlst *dummy, char **numbers);
void	dlst_add_back(t_dlst *dummy, long num);
void	dlst_add_front(t_dlst *dummy, long num);
void	dlst_del_back(t_dlst *dummy);
void	dlst_del_front(t_dlst *dummy);
long	dlst_size(t_dlst *dummy);
void	dlst_free(t_dlst *dummy);
void	print_dlst(char *dlst_name, t_dlst *dummy);

// utils.c
void	error(char *str);
long	atoi_or_err(char *str);

// sort.c
void	sort(t_dlst *a, t_dlst *b);
void	sort_5(t_dlst *a, t_dlst *b);
void	quick_sort(t_dlst *a, t_dlst *b);
void	sort_a(t_dlst *a, t_dlst *b, long min, long size);
void	sort_b(t_dlst *a, t_dlst *b, long min, long size);
void	sort_a_1st(t_dlst *a, t_dlst *b, long min, long size);

// sort_utils.c
long	get_border(long min, long size, long index);
long	get_size(long min, long size, long index);
long	get_min(long min, long size, long index);

// dlst2.c
long	get_min_in_dlst(t_dlst *dummy, long border);
long	get_max_in_dlst(t_dlst *dummy, long border);
long	dlst_front_num(t_dlst *dummy, long index);
long	dlst_back_num(t_dlst *dummy, long index);
long	dlst_all_size(t_dlst *a, t_dlst *b);

// compression.c
void	dlst_compression(t_dlst *a);

#endif
