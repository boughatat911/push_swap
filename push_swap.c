/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:49:29 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/20 21:27:45 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_list *head)
{
	t_list *news = head;
	while (news)
	{
		printf("node : index = %d\t content = %d\n",news->index, news->content);
		news = news->next;
	}
}
int	check_sort(t_list	**a)
{
	int i;
	i = 0;
	t_list *tmp = *a;
	while (tmp)
	{
		if(tmp->index != i)
			return(1);
		i++;
		tmp = tmp->next;
	}
	return(0);	
}
void	sort(t_list **a, t_list **b)
{
	ft_indexing(*a);
	if (check_sort(a) == 0)
		return;
	else if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_3(a);
	else
		algo(a, b);
	// if (ft_lstsize(*a) == 5)
}

int main(int ac, char **av)
{
	t_list 	*a;
	t_list 	*b;
	a = NULL;
	b = NULL;
	if(ac > 1)
	{

		parse_it(av, &a);
		sort(&a, &b);
		// print_node(a)`;
		
		ft_lstclear(&a);
	}
		return(0);	
}
