/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:12:39 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/21 15:24:00 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2(t_list	**stack)
{
	t_list	*tmp;

	tmp = *stack;
	tmp = tmp->next;
	if (tmp->content < (*stack)->content)
		sa(stack);
}

void	sort_3(t_list	**stack)
{
	int	one;
	int	two;
	int	three;

	if (!stack || !*stack)
		return ;
	one = (*stack)->content;
	two = (*stack)->next->content;
	three = (*stack)->next->next->content;
	if (one > two && two > three)
	{
		sa(stack);
		rra(stack);
	}
	else if (one > two && one > three && two < three)
		ra (stack);
	else if (one < two && one > three && two > three)
		rra (stack);
	else if (one > two && one < three && two < three)
		sa (stack);
	else if (one < two && one < three && two > three)
		(sa(stack), ra(stack));
}

int	check_sort(t_list	**a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index != i)
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	sort_5(t_list **stack)
{
	t_list	*stack_b;
	t_list	*stack_a;
	int		i;

	i = 0;
	stack_a = *stack;
	while (!(stack_a->index == 0))
	{
		stack_a = stack_a->next;
		i++;
	}
	stack_a = *stack;
	if (i < 3)
	{
		while (i > 0)
			(ra(&stack_a), i--);
	}
	else
	{
		while (i < 5)
			(rra(&stack_a), i++);
	}
	pb(&stack_a, &stack_b);
	sort_5_5(stack_a, stack_b, stack);
}

void	sort_5_5(t_list	*stack_a, t_list	*stack_b, t_list	**stack)
{
	int	i;

	i = 0;
	*stack = stack_a;
	while (!(stack_a->index == 1))
	{
		stack_a = stack_a->next;
		i++;
	}
	stack_a = *stack;
	while (i > 0)
		(ra(&stack_a), i--);
	pb(&stack_a, &stack_b);
	sort_3(&stack_a);
	pa(&stack_b, &stack_a);
	pa(&stack_b, &stack_a);
	sort_2(&stack_a);
	*stack = stack_a;
}
