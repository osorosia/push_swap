#include "push_swap.h"

void	error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

long	atoi_or_err(char *str)
{
	long	num;
	long	sign;
	long	i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		error("Error");
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			error("Error");
		num = num * 10 + str[i] - '0';
		if (sign * num < INT_MIN || INT_MAX < sign * num)
			error("Error");
		i++;
	}
	return (sign * num);
}
