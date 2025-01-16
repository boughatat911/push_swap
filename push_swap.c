/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:49:29 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/16 18:58:36 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void f()
{
    system("leaks a.out");
}
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
	// atexit(f);
	t_list 	*head;
	head = NULL;
	if(ac > 1)
	{
		parse_it(av, &head);
        indexing(head);
		print_node(head);
		ft_lstclear(&head);
	}
		return(0);	
}