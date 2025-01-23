/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:08:23 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/23 13:08:25 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	rr(t_list	**stack_a, t_list	**stack_b)
{
	ra(stack_a);
	rb(stack_b);
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
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	rotate_rra_rrb(stack_a);
}

void	rrb(t_list	**stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	rotate_rra_rrb(stack_b);
}

void	rrr(t_list	**stack_a, t_list	**stack_b)
{
	rotate_rra_rrb(stack_a);
	rotate_rra_rrb(stack_b);
}
