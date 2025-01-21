/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:20:25 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/20 22:36:11 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/push_swap.h"

int	ft_check_indix(t_list	*stack, int len)
{
	int		i;

	i = ft_lstsize(stack) / 2;
	while (i--)
	{
		if (stack->index == len)
			return (1);
		stack = stack->next;
	}
	return (0);
}

// void	algo(t_list	**stack)
// {
// 	t_list *stack_b = NULL;
// 	t_list *stack_a = *stack;
// 	int size = ft_lstsize(stack_a);

// 	while (ft_lstsize(stack_a) > 3)
// 	{
// 		while (ft_lstsize(stack_b) < size - 3)
// 		{
// 			if (stack_a->index == ft_lstsize(stack_b))
// 				pb(&stack_a, &stack_b);
// 			else if (ft_lstlast(stack_a)->index == ft_lstsize(stack_b))
// 			{
// 				rra(&stack_a);
// 				pb(&stack_a, &stack_b);
// 			}
// 			else
// 			{
// 				if (ft_check_indix(&stack_a, ft_lstsize(stack_b)) == 1)
// 					ra(&stack_a);
// 				else
// 					rra(&stack_a);
// 			}
// 		}
// 	}
// 	if (stack_a->index > stack_a->next->index && 
// 		stack_a->index > stack_a->next->next->index)
// 		ra(&stack_a);
// 	else if (stack_a->next->index > stack_a->index && 
// 			 stack_a->next->index > stack_a->next->next->index)
// 		rra(&stack_a);
// 	if (stack_a->index > stack_a->next->index)
// 		sa(&stack_a);
// 	while (stack_b)
// 		pa(&stack_b, &stack_a);
// 	*stack = stack_a;
// }

void	algo(t_list	**a, t_list **b)
{
	int	pv1;
	int	pv2;
	// t_list *b;
//	t_list *tmp = *a;
	
	//ft_indexing(*a);
//	printf("\n==================\n");
//	while(tmp)
//	{
	//	printf("index : %d || content : %d\n",tmp->index,tmp->content);
	//	tmp = tmp->next;
//	}//
	//printf("\n==================\n");

	pv2 = 0;
	while (ft_lstsize(*a) > 3)
	{
		pv1 = (ft_lstsize(*a) / 6) + pv2;
		pv2 += (ft_lstsize(*a) / 3);
		while (ft_lstsize(*b) < pv2 && ft_lstsize(*a) > 3)
		{
			if (ft_lstsize(*b) > 1 && (*b)->index < pv1 && (*a)->index >= pv2)
				rr(a, b);
			else if (ft_lstsize(*b) > 1 && (*b)->index < pv1)
				rb(b);
			if ((*a)->index >= pv2)
				ra(a);
			else if ((*a)->index < pv2)
				pb(a, b);
		}
	}
	sort_3(a);
	    int max = ft_lstlast(*a)->index; // 10
    while (ft_lstsize(*b))
    {
        int look = (*a)->index -1;
        if ((*b)->index == look) // 7
            pa(b, a);
        else if (ft_lstlast(*b)->index == look)
        {
            rrb(b);
            pa(b, a);
        }
        else if (ft_lstlast(*a)->index == max)
            (pa(b, a), ra(a));
        else if((*b)->index > ft_lstlast(*a)->index) //--
        {
            pa(b,a);
            ra(a);
        }
        else if(ft_lstlast(*b)->index > ft_lstlast(*a)->index) //--
        {
            rrb(b);
            pa(b,a);
            ra(a);
        }
        else if(ft_lstlast(*a)->index == look) //--
            rra(a);
        else if (ft_check_indix(*b, look) == 1)
            rb(b);
        else if (ft_check_indix(*b, look) == 0)
            rrb(b);
    }
}