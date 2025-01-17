/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:12:39 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/17 22:09:22 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_nodes(t_list *stack)
{
    int count;
    t_list *tmp;
    
    count = 0;
    tmp = stack;
    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }
    return (count);
}

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
    if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
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
// }


