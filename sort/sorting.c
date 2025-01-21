/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:12:39 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/20 22:07:55 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/push_swap.h"

void    ft_indexing(t_list *stack)
{
    t_list  *tmp;
    t_list  *check;
    int     indix;

    if (!stack)
        return;

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

void    sort_2(t_list   **stack)
{
    t_list *tmp;

    tmp = *stack;
    tmp = tmp->next;
    if(tmp->content < (*stack)->content)
        sa(stack);
}

void sort_3(t_list **stack)
{
    if (!stack || !*stack)
        return;

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

void sort_5(t_list **stack)
{
    t_list *stack_b;
    t_list *stack_a;
	int i;

	i = 0;
	stack_a = *stack;
	while (!(stack_a->index == 0))
		(stack_a = stack_a->next,i++);
	stack_a = *stack;
	while (i > 0 )
		(ra(&stack_a),i--);
	pb(&stack_a, &stack_b);
	i = 0;	 
	*stack = stack_a;
	while (!(stack_a->index == 1))
		(stack_a = stack_a->next,i++);
	stack_a = *stack;
	while (i > 0 )
		(ra(&stack_a),i--);
	pb(&stack_a, &stack_b);
	sort_3(&stack_a);
	pa(&stack_b, &stack_a);
	pa(&stack_b, &stack_a);
	sort_2(&stack_a);
	*stack = stack_a;
}
// void	sort(t_list	**stack)
// {
// 	int size;

// 	ft_indexing(*stack);
// 	size = 0;
// 	size = ft_lstsize(*stack);
// 	if(size == 2)
// 		sort_2(stack);
// 	else if(size == 3)
// 		sort_3(stack);
// 	else if(size == 5)
// 		sort_5(stack);
// 	else
// 		algo(stack);
// }