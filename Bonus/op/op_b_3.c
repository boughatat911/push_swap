/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:37:47 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/22 20:38:33 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	pa(t_list	**stack_b, t_list	**stack_a)
{
	t_list	*last_a;
	t_list	*temp;

	if (!stack_b || !(*stack_b))
		return ;
	temp = *stack_b;
	last_a = *stack_b;
	*stack_b = temp->next;
	ft_lstadd_front_bonus(stack_a, last_a);
}

void	pb(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*last_a;
	t_list	*tmp;

	if (!stack_a || !(*stack_a))
		return ;
	tmp = *stack_a;
	last_a = *stack_a;
	*stack_a = tmp->next;
	ft_lstadd_front_bonus(stack_b, last_a);
}

void	ra(t_list	**stack_a)
{
	t_list	*tmp;

	if (!stack_a || !(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back_bonus(stack_a, tmp);
}

void	rb(t_list	**stack_b)
{
	t_list	*tmp;

	if (!stack_b || !(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back_bonus(stack_b, tmp);
}
