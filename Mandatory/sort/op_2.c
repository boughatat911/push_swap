/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:51:57 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/27 12:51:59 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *stack_a;
	*stack_a = tmp_a->next;
	tmp_a->next = NULL;
	ft_lstadd_back(stack_a, tmp_a);
	tmp_b = *stack_b;
	*stack_b = tmp_b->next;
	tmp_b->next = NULL;
	ft_lstadd_back(stack_b, tmp_b);
	write(1, "rr\n", 3);
}

void	rotate_rra_rrb(t_list	**stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_list	**stack_a)
{
	rotate_rra_rrb(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list	**stack_b)
{
	rotate_rra_rrb(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list	**stack_a, t_list	**stack_b)
{
	rotate_rra_rrb(stack_a);
	rotate_rra_rrb(stack_b);
	write(1, "rrr\n", 4);
}
