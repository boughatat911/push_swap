/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:09:27 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/23 13:09:28 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_astoi(const char *str)
{
	long	sign;
	long	num;

	sign = 1;
	num = 0;
	if (!str || *str == '\0')
		return (2147483648);
	if ((*str == '-' || *str == '+') && *(str + 1))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	else if (*str == '-' || *str == '+')
		return (2147483648);
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
			return (2147483648);
		str++;
	}
	if (*str != '\0')
		return (2147483648);
	return (sign * num);
}

void	ft_check_empty(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i] && av[j][i] == ' ')
			i++;
		if (!av[j][i])
			(write(1, "Error\n", 6), exit(1));
		j++;
	}
}

void	fill_stack(char **av, t_list **head)
{
	char	**new;
	int		i;
	int		j;
	long	atoi;

	i = 1;
	atoi = 0;
	while (av[i])
	{
		j = 0;
		new = ft_split(av[i], ' ');
		while (new[j])
		{
			atoi = ft_astoi(new[j]);
			if (atoi == 2147483648)
			{
				ft_lstclear(head);
				(write(1, "Error\n", 6), ft_free2darray(new), exit(1));
			}
			ft_lstadd_back(head, ft_lstnew((atoi)));
			j++;
		}
		ft_free2darray(new);
		i++;
	}
}

void	check_dup(t_list *head)
{
	t_list	*news;
	t_list	*new_check;

	news = head;
	while (news)
	{
		new_check = news->next;
		while (new_check)
		{
			if (new_check->content == news->content)
			{
				ft_lstclear(&head);
				(write(2, "Error\n", 6), exit (1));
			}
			new_check = new_check->next;
		}
		news = news->next;
	}
}

void	parse_it(char **av, t_list **head)
{
	ft_check_empty(av);
	fill_stack(av, head);
	check_dup(*head);
}
