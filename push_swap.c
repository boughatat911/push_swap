/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:49:29 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/19 06:05:15 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_list *head)
{
	t_list *news = head;
	while (news)
	{
		printf("%d ", news->content);
		news = news->next;
	}
}

int main(int ac, char **av)
{
	t_list 	*head;
	head = NULL;
	if(ac > 1)
	{
		parse_it(av, &head);
		print_node(head);
		
		ft_lstclear(&head);
	}
		return(0);	
}