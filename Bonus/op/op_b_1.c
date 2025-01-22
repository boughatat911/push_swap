/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:05:36 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/22 20:20:36 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	s_rotate(t_list	**stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = (*stack_a);
	tmp2 = (*stack_a)->next;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	tmp2->next = tmp;
}

void	sa(t_list	**stack_a)
{
	s_rotate(stack_a);
}

void	sb(t_list	**stack_b)
{
	s_rotate(stack_b);
}

void	ss(t_list	**stack_a, t_list	**stack_b)
{
	s_rotate(stack_a);
	s_rotate(stack_b);
}
