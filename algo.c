/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:20:25 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/19 04:34:18 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_indix(t_list	**stack, int len)
{
	t_list	*stack_a;
	int 	size;
	int 	i;
	int		k;
	int 	loop;

	i = 0;
	k = 0;
	loop = 0;
	stack_a = *stack;
	size = ft_lstsize(*stack);
	loop = size / 2;
	while (stack_a)
	{
		if ((stack_a->index < len) && (i <= loop))
			k++;
		i++;
		stack_a = stack_a->next;
	}
	if(k > 0)
		return (1);
	return (0);
}

void	algo(t_list	**stack)
{
	t_list *stack_b = NULL;
	t_list *stack_a = *stack;
	int size = ft_lstsize(stack_a);

	while (ft_lstsize(stack_a) > 3)
	{
		// Find smallest number and push to stack B
		while (ft_lstsize(stack_b) < size - 3)
		{
			if (stack_a->index == ft_lstsize(stack_b))
			{
				pb(&stack_a, &stack_b);
			}
			else if (ft_lstlast(stack_a)->index == ft_lstsize(stack_b))
			{
				rra(&stack_a);
				pb(&stack_a, &stack_b);
			}
			else
			{
				// Rotate based on position of smallest remaining number
				if (ft_check_indix(&stack_a, ft_lstsize(stack_b)) == 1)
					ra(&stack_a);
				else
					rra(&stack_a);
			}
		}
	}
	if (stack_a->index > stack_a->next->index && 
		stack_a->index > stack_a->next->next->index)
		ra(&stack_a);
	else if (stack_a->next->index > stack_a->index && 
			 stack_a->next->index > stack_a->next->next->index)
		rra(&stack_a);
	if (stack_a->index > stack_a->next->index)
		sa(&stack_a);
	while (stack_b)
	{
		pa(&stack_b, &stack_a);
	}

	*stack = stack_a;
}