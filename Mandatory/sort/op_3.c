/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:15 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/23 13:10:16 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list	**stack_b, t_list	**stack_a)
{
	t_list	*last_a;
	t_list	*temp;

	temp = *stack_b;
	last_a = *stack_b;
	*stack_b = temp->next;
	ft_lstadd_front(stack_a, last_a);
	write(1, "pa\n", 3);
}

void	pb(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*last_a;
	t_list	*tmp;

	tmp = *stack_a;
	last_a = *stack_a;
	*stack_a = tmp->next;
	ft_lstadd_front(stack_b, last_a);
	write(1, "pb\n", 3);
}

void	ra(t_list	**stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_a, tmp);
	write(1, "ra\n", 3);
}

void	rb(t_list	**stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_b, tmp);
	write(1, "rb\n", 3);
}
