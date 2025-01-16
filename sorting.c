/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:12:39 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/16 16:23:38 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_2(t_list   **stack)
{
    t_list *tmp;

    tmp = *stack;
    tmp = tmp->next;
    if(tmp->content < (*stack)->content)
        sa(stack);
}

void sort_3(t_list  **stack)
{
    int one;
    int two;
    int three;

    one = (*stack)->content;
    two   = (*stack)->next->content;
    three = (*stack)->next->next->content;
    if(one > two && one > three && two > three)
        {
            sa(stack);
            rra(stack);
        }
    else if(one > two && one > three && two < three)
        ra(stack);
    else if(one < two && one > three && two > three) // 2 3 1
        rra(stack);
    else if(one > two && one < three && two < three) // 2 1 3
        sa(stack);
    else if(one < two && one < three && two > three) // 1 3 2
        {
            sa(stack);
            ra(stack);
        }
}
