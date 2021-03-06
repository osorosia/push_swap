/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:08:31 by rnishimo          #+#    #+#             */
/*   Updated: 2022/04/24 20:17:43 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_number_strs(int argc, char **argv)
{
	char	**numbers;
	char	**strs;
	long	i;
	long	j;
	long	index;

	numbers = ft_calloc(MAX_NUMBERS_LEN + 1, sizeof(char *));
	if (numbers == NULL)
		error("malloc error");
	i = 1;
	index = 0;
	while (i < argc)
	{
		strs = ft_split(argv[i], ' ');
		if (strs == NULL)
			error("malloc error");
		if (strs[0] == NULL)
			error("Error");
		j = 0;
		while (strs[j])
			numbers[index++] = strs[j++];
		free(strs);
		i++;
	}
	return (numbers);
}

void	free_number_strs(char **numbers)
{
	long	i;

	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
}
