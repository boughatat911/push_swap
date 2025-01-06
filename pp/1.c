/* push_swap_utils.c */
#include "push_swap.h"

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

void	ft_free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->numbers)
			free(stack->numbers);
		free(stack);
	}
}

t_stack	*ft_init_stack(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->numbers = malloc(sizeof(int) * size);
	if (!stack->numbers)
	{
		free(stack);
		return (NULL);
	}
	stack->size = size;
	return (stack);
}

int	has_duplicates(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}