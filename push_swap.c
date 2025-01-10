/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:49:29 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/10 20:31:26 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void f()
{
    system("leaks a.out");
}
void del(int *content)
{
    if (content)
        free(content);
}
void	free2darray(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

long	ft_astoi(const char *str)
{
	int			sign;
	long		num;

	sign = 1;
	num  = 0;
	if ((*str == '-' || *str == '+') && *(str + 1)) //"++123"
	{
		if (*(str) == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10 )+ (*str - '0');
		if ((num * sign) > 2147483647 || ((num * sign) < -2147483648))
			return (2147483648);
		str++;
	}
	if (*str)
		return(2147483648);
	return (sign * num);
}

void ft_check_empty(char **av)
{
	int i;
	int j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i] && av[j][i] == ' ')
			i++;
		if (av[j][i])
			(write(1, "Error_ft_check_empty\n", 21), exit(1));
		j++;
	}
}

void fill_stack(char **av, t_list **head)
{
	char	**new;
	int i = 1;
	int j;
	long atoi = 0;

	while (av[i])
	{
		j = 0;
		new = ft_split(av[i], ' ');
		while (new[j])
		{
			atoi = ft_astoi(new[j]);
			if (atoi == 2147483648){
				(write(1, "Error_ft_atoi\n", 14),free2darray(new), exit(1));
			}
			ft_lstadd_back(head, ft_lstnew(ft_astoi(new[j++])));
		}
		free2darray(new);
		i++;	
	}
}

void	check_dup(t_list *head)
{
	t_list *news = head;
		while (news)
    	{
			t_list *new_check = news->next;
			while (new_check)
			{
				if(new_check->content == news->content)
					write(2, "Error= likd_list\n", 17) , exit (1);
				new_check = new_check->next;
			}
			news = news->next;
		}
}


void print_node(t_list *head)
{
	t_list *news = head;
		while (news)
		{
			printf("%d\n", news->content);
			news = news->next;
		}
}

void	parse_it(char **av, t_list **head)
{
	// ft_check_empty(av);
	fill_stack(av , head);
	check_dup(*head);
	
}

int main(int ac, char **av)
{
	// atexit(f);
	t_list 	*head;

// -----------ft_check-----------------------
	head = NULL;
	if(ac > 1)
	{
		parse_it(av, &head);
		print_node(head);
		return(0);	
	}
}
