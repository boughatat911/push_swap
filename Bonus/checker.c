/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:23:36 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/22 20:25:12 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

void	ft_error(t_list	**a, t_list	**b)
{
	write(1, "Error99\n", 8),
	ft_lstclear_bonus(a);
	ft_lstclear_bonus(b);
	exit(1);
}

void	ft_check_operations(char	*op, t_list	**a, t_list	**b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(op, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(a);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(a, b);
	else
		ft_error(a, b);
}

void	parse_it_bonus(char	**av, t_list	**a, t_list	**b)
{
	char	*op;

	ft_check_empty_bonus(av);
	fill_stack_bonus(av, a);
	ft_indexing_bonus(*a);
	check_dup_bonus(*a);
	op = get_next_line(0);
	while (op)
	{
		ft_check_operations(op, a, b);
		free(op);
		op = get_next_line(0);
	}
	if (check_sort_bonus(a) == 0 && ft_lstsize_bonus(*b) == 0)
	{
		(ft_lstclear_bonus(a), ft_lstclear_bonus(b));
		(write(1, "OK\n", 3), exit(0));
	}
	else
	{
		write(1, "KO\n", 3),
		ft_lstclear_bonus(a);
		ft_lstclear_bonus(b);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	parse_it_bonus(av, &a, &b);
}
