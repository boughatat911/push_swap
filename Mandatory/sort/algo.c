/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:20:25 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/21 15:23:20 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_list	**a, t_list	**b)
{
	ft_indexing(*a);
	if (check_sort(a) == 0)
		return ;
	else if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_3(a);
	else if (ft_lstsize(*a) == 5)
		sort_5(a);
	else
		algo(a, b);
}

void	algo(t_list	**a, t_list **b)
{
	int	pv1;
	int	pv2;
	int	max;

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
	max = ft_lstlast(*a)->index;
	algo_part_2(a, b, max);
}

void	algo_part_2(t_list	**a, t_list	**b, int max)
{
	int	look;

	while (ft_lstsize(*b))
	{
		look = (*a)->index -1;
		if ((*b)->index == look)
			pa(b, a);
		else if (ft_lstlast(*b)->index == look)
			(rrb(b), pa(b, a));
		else if (ft_lstlast(*a)->index == max)
			(pa(b, a), ra(a));
		else if ((*b)->index > ft_lstlast(*a)->index)
			(pa(b, a), ra(a));
		else if (ft_lstlast(*b)->index > ft_lstlast(*a)->index)
			(rrb(b), pa(b, a), ra(a));
		else if (ft_lstlast(*a)->index == look)
			rra(a);
		else if (ft_check_indix(*b, look) == 1)
			rb(b);
		else if (ft_check_indix(*b, look) == 0)
			rrb(b);
	}
	while (check_sort(a))
		rra (a);
}
