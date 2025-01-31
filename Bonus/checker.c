/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:23:36 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/27 12:47:31 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_exit(t_list	**a, t_list	**b, int num)
{
	if (num == 1)
	{
		write(2, "OK\n", 3),
		ft_lstclear_bonus(a);
		ft_lstclear_bonus(b);
		exit(0);
	}
	else if (num == 2)
	{
		write(2, "Error\n", 6),
		ft_lstclear_bonus(a);
		ft_lstclear_bonus(b);
		exit(1);
	}
	else if (num == 3)
	{
		write(2, "KO\n", 3),
		ft_lstclear_bonus(a);
		ft_lstclear_bonus(b);
		exit(1);
	}
}

void	ft_check_operations(char	*op, t_list	**a, t_list	**b, char **str)
{
	if (ft_strcmp(op, "sa") == 0)
		sa(a);
	else if (ft_strcmp(op, "sb") == 0)
		sb(b);
	else if (ft_strcmp(op, "ss") == 0)
		ss(a, b);
	else if (ft_strcmp(op, "pa") == 0)
		pa(b, a);
	else if (ft_strcmp(op, "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(op, "ra") == 0)
		ra(a);
	else if (ft_strcmp(op, "rb") == 0)
		rb(b);
	else if (ft_strcmp(op, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(op, "rra") == 0)
		rra(a);
	else if (ft_strcmp(op, "rrb") == 0)
		rrb(b);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr(a, b);
	else
		(free_bonus(str), ft_exit(a, b, 2));
}

int	ft_op(char	*op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(op, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(op, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(op, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(op, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(op, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(op, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(op, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(op, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(op, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(op, "rrr\n") == 0)
		return (1);
	else
		return (911);
}

void	checker(t_list	**a, t_list	**b)
{
	char	*op;
	char	**spl;
	char	*str;
	char	*tmp;
	int		i;

	(1) && (i = 0, str = NULL, op = get_next_line(0));
	while (op)
	{
		if (ft_op (op) == 1)
		{
			tmp = str;
			str = ft_strjoin(str, op);
			free(tmp);
		}
		else if (ft_op (op) == 911)
			(free(op), free(str), ft_exit(a, b, 2));
		free(op);
		op = get_next_line(0);
	}
	spl = ft_split_bonus(str, '\n');
	(free(op), free(str));
	while (spl && spl[i])
		(ft_check_operations(spl[i], a, b, spl), i++);
	free_bonus(spl);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	ft_check_empty_bonus(av);
	fill_stack_bonus(av, &a);
	ft_indexing_bonus(a);
	check_dup_bonus(a);
	checker(&a, &b);
	if (check_sort_bonus(&a) == 0 && ft_lstsize_bonus(b) == 0)
		ft_exit(&a, &b, 1);
	else
		ft_exit(&a, &b, 3);
}
