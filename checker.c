/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:07:53 by rnishimo          #+#    #+#             */
/*   Updated: 2022/04/24 20:08:03 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_op_str(char *op, char *str)
{
	const long	len = ft_strlen(op);

	if (ft_strncmp(op, str, len) != 0)
	{
		return (false);
	}
	if (str[len] != '\0' && str[len] != '\n')
	{
		return (false);
	}
	return (true);
}

bool	check_op(t_dlst *a, t_dlst *b, char *line)
{
	const char		*op_str[] = {
		"rra", "rrb", "rrr", "ra", "rb", "rr",
		"pa", "pb", "sa", "sb", "ss", NULL
	};
	static	void	(*op_fn[])(t_dlst *, t_dlst *, bool) = {
		rra, rrb, rrr, ra, rb, rr,
		pa, pb, sa, sb, ss
	};
	long			i;

	i = 0;
	while (op_str[i])
	{
		if (check_op_str((char *)op_str[i], line))
		{
			op_fn[i](a, b, false);
			return (true);
		}
		i++;
	}
	return (false);
}

void	stdin_loop(t_dlst *a, t_dlst *b)
{
	char	*line;

	while (true)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (!check_op(a, b, line))
			error("Error");
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_dlst	*a;
	t_dlst	*b;
	char	**numbers;

	if (argc < 2)
		exit(0);
	a = dlst_new_dummy();
	b = dlst_new_dummy();
	numbers = create_number_strs(argc, argv);
	dlst_add_numbers(a, numbers);
	free_number_strs(numbers);
	if (check_duplicate_number(a))
		error("Error");
	stdin_loop(a, b);
	if (check_sorted(a, b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	dlst_free(a);
	dlst_free(b);
}
