/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:23:36 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/26 16:14:37 by nbougrin         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap_bonus.h"

void	ft_error(t_list	**a, t_list	**b)
{
	
	ft_lstclear_bonus(a);
	ft_lstclear_bonus(b);
	exit(1);
}

void	ft_check_operations(char	*op, t_list	**a, t_list	**b)
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
		rb(a);
	else if (ft_strcmp(op, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(op, "rra") == 0)
		rra(a);
	else if (ft_strcmp(op, "rrb") == 0)
		rrb(b);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr(a, b);
	else
		(write(1, "Error\n", 6), ft_error(a, b));
}
int	ft_op(char	*op)
{
	if (ft_strcmp(op, "sa") == 0)
		return (1);
	else if (ft_strcmp(op, "sb") == 0)
		return (1);
	else if (ft_strcmp(op, "ss") == 0)
		return (1);
	else if (ft_strcmp(op, "pa") == 0)
		return (1);
	else if (ft_strcmp(op, "pb") == 0)
		return (1);
	else if (ft_strcmp(op, "ra") == 0)
		return (1);
	else if (ft_strcmp(op, "rb") == 0)
		return (1);
	else if (ft_strcmp(op, "rr") == 0)
		return (1);
	else if (ft_strcmp(op, "rra") == 0)
		return (1);
	else if (ft_strcmp(op, "rrb") == 0)
		return (1);
	else if (ft_strcmp(op, "rrr") == 0)
		return (1);
	return (0);
	
}

int	parse_it_bonus(char	**av, t_list	**a, t_list	**b)
{
	char	*op;
	char	*str;
	char	**spl;
	int		i;
	
	i = 0;
	str = NULL;
	(ft_check_empty_bonus(av), fill_stack_bonus(av, a));
	(ft_indexing_bonus(*a), check_dup_bonus(*a));
	op = get_next_line(0);
	while (op)
	{
		if(ft_op(op) == 1)
			str =  ft_strjoin(str, op);
		else
			(write(1, "Error\n", 6), ft_error(a, b));
		op = get_next_line(0);
	}
	spl = ft_split_bonus(str,'\n');
	while (spl[i])
		ft_check_operations(spl[i], a, b);
	if (check_sort_bonus(a) == 0 && ft_lstsize_bonus(*b) == 0)
		return (ft_free2darray_bonus(spl), 0);
	else
		return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	int i = parse_it_bonus(av, &a, &b);
	
	if(i == 0)
	{
		write(1, "OK\n", 3);
		ft_lstclear_bonus(&a);
		ft_lstclear_bonus(&b);
		exit(0);
	}
	else
	{
		write(1, "KO\n", 3);
		ft_lstclear_bonus(&a);
		ft_lstclear_bonus(&b);
		exit(1);
	}
}
