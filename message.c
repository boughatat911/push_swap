#include "push_swap.h"

void	sort_2(t_stack **a)
{
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

void	sort_3(t_stack **a)
{
	int	t[3];

	t[0] = (*a)->num;
	t[1] = (*a)->next->num;
	t[2] = (*a)->next->next->num;
	if (t[0] > t[1] && t[0] < t[2] && t[1] < t[2])
		sa(a);
	else if (t[0] > t[1] && t[0] > t[2] && t[1] > t[2])
	{
		sa(a);
		rra(a);
	}
	else if (t[0] > t[1] && t[0] > t[2] && t[1] < t[2])
		ra(a);
	else if (t[0] < t[1] && t[0] < t[2] && t[1] > t[2])
	{
		sa(a);
		ra(a);
	}
	else if (t[0] < t[1] && t[0] > t[2] && t[1] > t[2])
		rra(a);
}

void	sort_5(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			pb(a, b);
		else if (index_half(a, 0) == 1 || index_half(a, 1) == 1)
			ra(a);
		else if (index_half(a, 0) == 2 || index_half(a, 1) == 2)
			rra(a);
	}
	sort_3(a);
	(pa(a, b), pa(a, b));
	if (check_sorted(*a) == 0)
		sa(a);
}

void	a_to_3(t_stack **a, t_stack **b)
{
	int	pv1;
	int	pv2;

	pv2 = 0;
	while (ft_lstsize(*a) > 3)
	{
		pv1 = (ft_lstsize(*a) / 6) + pv2;
		pv2 = (ft_lstsize(*a) / 3) + pv2;
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
		sort_3(a);
	}
}

void	b_to_a(t_stack **a, t_stack **b)
{
	int	last;

	last = ft_lstlast(*a)->index;
	while (ft_lstsize(*b) > 0)
	{
		if ((*b)->index == (*a)->index - 1)
			pa(a, b);
		else if ((*a)->index - 1 == ft_lstlast(*b)->index)
			(rrb(b), pa(a, b));
		else if (ft_lstlast(*a)->index == last)
			(pa(a, b), ra(a));
		else if (ft_lstlast(*a)->index < (*b)->index)
			(pa(a, b), ra(a));
		else if (*b && ft_lstlast(*a)->index < ft_lstlast(*b)->index)
			(rrb(b), pa(a, b), ra(a));
		else if (*b && ft_lstlast(*a)->index == ((*a)->index - 1))
			rra(a);
		else if (index_half(b, (*a)->index - 1) == 1)
			rb(b);
		else if (index_half(b, (*a)->index - 1) == 2)
			rrb(b);
	}
	while (ft_lstlast(*a)->index != last)
		rra(a);
}
