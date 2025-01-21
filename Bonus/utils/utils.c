/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:08:40 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/21 19:38:42 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize_bonus(t_list	*lst)
{
	int		count;
	t_list	*sin;

	if (!lst)
		return (0);
	sin = lst;
	count = 0;
	while (sin)
	{
		count++;
		sin = sin->next;
	}
	return (count);
}

void	ft_indexing_bonus(t_list *stack)
{
	t_list	*tmp;
	t_list	*check;
	int		indix;

	if (!stack)
		return ;
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

int	ft_check_indix_bonus(t_list	*stack, int len)
{
	int	i;

	i = ft_lstsize_bonus(stack) / 2;
	while (i--)
	{
		if (stack->index == len)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_free2darray_bonus(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

int	check_sort_bonus(t_list	**a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index != i)
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}