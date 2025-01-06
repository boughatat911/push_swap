/* push_swap_parse.c */
#include "push_swap.h"

int	count_numbers_in_str(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i])
		{
			count++;
			if (str[i] == '+' || str[i] == '-')
				i++;
			if (!ft_isdigit(str[i]))
				return (-1);
			while (ft_isdigit(str[i]))
				i++;
			if (str[i] && !ft_isspace(str[i]))
				return (-1);
		}
	}
	return (count);
}

static int	handle_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

long	ft_atol(char *str, int *i, int *error)
{
	long	num;
	int		sign;

	num = 0;
	*error = 0;
	sign = handle_sign(str, i);
	if (!ft_isdigit(str[*i]))
	{
		*error = 1;
		return (0);
	}
	while (ft_isdigit(str[*i]))
	{
		num = num * 10 + (str[*i] - '0');
		if ((sign == 1 && num > 2147483647)
			|| (sign == -1 && num > 2147483648))
		{
			*error = 1;
			return (0);
		}
		(*i)++;
	}
	return (num * sign);
}