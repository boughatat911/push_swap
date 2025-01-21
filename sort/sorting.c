/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:12:39 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/21 12:43:55 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/push_swap.h"

void	ft_indexing(t_list *stack)
{
	t_list	*tmp;
	t_list	*check;
	int		indix;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp)
	{
		indix = 0;
		check = stack;
		while (check)
		{
			if (check->content < tmp->content)
				indix++;
			check = check->next;
		}
		tmp->index = indix;
		tmp = tmp->next;
	}
}

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
	if (!stack || !*stack)
		return ;
	int one = (*stack)->content;
	int two = (*stack)->next->content;
	int three = (*stack)->next->next->content;

	if (one > two && two > three)
	{
		sa(stack);
		rra(stack);
	}
	else if (one > two && one > three && two < three)
		ra(stack); 
	else if (one < two && one > three && two > three)
		rra(stack);
	else if (one > two && one < three && two < three)
		sa(stack);
	else if (one < two && one < three && two > three)
	{
		sa(stack);
		ra(stack);
	}
}

int	ft_check_indix(t_list	*stack, int len)
{
	int	i;

	i = ft_lstsize(stack) / 2;
	while (i--)
	{
		if (stack->index == len)
			return (1);
		stack = stack->next;
	}
	return (0);
}
int	check_sort(t_list	**a)
{
	int i;
	i = 0;
	t_list *tmp = *a;
	while (tmp)
	{
		if(tmp->index != i)
			return(1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	sort(t_list	**a, t_list	**b)
{
	ft_indexing(*a);
	if (check_sort(a) == 0)
		return ;
	else if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_3(a);
	else
		algo(a, b);
}
