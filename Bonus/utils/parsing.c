/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:08:51 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/27 12:50:19 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	free_bonus(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

long	ft_atoi_bonus(const char *str)
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

void	ft_check_empty_bonus(char **av)
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

void	fill_stack_bonus(char **av, t_list **head)
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
		new = ft_split_bonus(av[i], ' ');
		while (new[j])
		{
			atoi = ft_atoi_bonus(new[j]);
			if (atoi == 2147483648)
			{
				ft_lstclear_bonus(head);
				(write(2, "Error\n", 6), free_bonus(new), exit(1));
			}
			ft_lstadd_back_bonus(head, ft_lstnew_bonus((atoi)));
			j++;
		}
		free_bonus(new);
		i++;
	}
}

void	check_dup_bonus(t_list *head)
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
				ft_lstclear_bonus(&head);
				(write(2, "Error\n", 6), exit (1));
			}
			new_check = new_check->next;
		}
		news = news->next;
	}
}
