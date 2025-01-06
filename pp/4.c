/* push_swap_main.c */
#include "push_swap.h"

static int	count_total_numbers(int ac, char **av)
{
	int		i;
	int		total;
	t_stack	*temp;

	total = 0;
	i = 1;
	while (i < ac)
	{
		temp = parse_string(av[i]);
		if (!temp)
			return (-1);
		total += temp->size;
		ft_free_stack(temp);
		i++;
	}
	return (total);
}

static void	copy_numbers(int *dest, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

static t_stack	*merge_numbers(int ac, char **av, int total)
{
	t_stack	*stack;
	t_stack	*temp;
	int		i;
	int		curr_index;

	stack = ft_init_stack(total);
	if (!stack)
		return (NULL);
	i = 1;
	curr_index = 0;
	while (i < ac)
	{
		temp = parse_string(av[i]);
		if (!temp)
		{
			ft_free_stack(stack);
			return (NULL);
		}
		copy_numbers(stack->numbers + curr_index,
			temp->numbers, temp->size);
		curr_index += temp->size;
		ft_free_stack(temp);
		i++;
	}
	return (stack);
}

t_stack	*parse_args(int ac, char **av)
{
	t_stack	*stack;
	int		total;

	total = count_total_numbers(ac, av);
	if (total <= 0)
		return (NULL);
	stack = merge_numbers(ac, av, total);
	if (!stack)
		return (NULL);
	if (has_duplicates(stack->numbers, stack->size))
	{
		ft_free_stack(stack);
		return (NULL);
	}
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	int		i;

	if (ac < 2)
		return (1);
	stack = parse_args(ac, av);
	if (!stack)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 0;
	while (i < stack->size)
	{
		printf("%d ", stack->numbers[i]);
		i++;
	}
	write(1, "\n", 1);
	ft_free_stack(stack);
	return (0);
}