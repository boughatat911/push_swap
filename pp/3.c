/* push_swap_parse.c */
#include "push_swap.h"

static int	handle_sign(const char *str, int *i)
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

int	ft_check_num(const char *str, int *i, long *num)
{
	int	sign;

	*num = 0;
	sign = handle_sign(str, i);
	if (!ft_isdigit(str[*i]))
		return (0);
	while (ft_isdigit(str[*i]))
	{
		*num = *num * 10 + (str[*i] - '0');
		if ((sign == 1 && *num > 2147483647)
			|| (sign == -1 && *num > 2147483648))
			return (0);
		(*i)++;
	}
	*num *= sign;
	return (1);
}

static t_stack	*parse_numbers(char *str, int count)
{
	t_stack	*stack;
	int		i;
	int		num_index;
	long	num;

	if (!(stack = ft_init_stack(count)))
		return (NULL);
	i = 0;
	num_index = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i])
		{
			if (!ft_check_num(str, &i, &num))
			{
				ft_free_stack(stack);
				return (NULL);
			}
			stack->numbers[num_index++] = (int)num;
		}
	}
	return (stack);
}

t_stack	*parse_string(char *str)
{
	t_stack	*stack;
	int		count;

	count = count_numbers_in_str(str);
	if (count <= 0)
		return (NULL);
	stack = parse_numbers(str, count);
	if (!stack)
		return (NULL);
	if (has_duplicates(stack->numbers, stack->size))
	{
		ft_free_stack(stack);
		return (NULL);
	}
	return (stack);
}