/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:50:41 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/27 12:50:43 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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
