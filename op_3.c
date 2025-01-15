/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:37:47 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/13 19:39:04 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*new;
	t_list	*last_b;
	t_list	*temp;

	temp = *stack_b;
	last_b->content = (*stack_b)->content;
	ft_lstadd_front(stack_a, last_b);
	*stack_b = temp->next;
	free(temp);
	write(1, "pa\n", 3);
}

void	pb(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*new;
	t_list	*last_a;
	t_list	*temp;

	temp = *stack_a;
	last_a->content = (*stack_a)->content;
	ft_lstadd_front(stack_b, last_a);
	*stack_a = temp->next;
	free(temp);
	write(1, "pb\n", 3);
}

void	ra(t_list	**stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_a, tmp);
	write(1, "rb\n", 3);
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
