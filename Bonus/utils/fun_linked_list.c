/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_linked_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:57:15 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/22 15:30:24 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_lstadd_back_bonus(t_list **lst, t_list *new)
{
	t_list	*final;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	final = ft_lstlast_bonus(*lst);
	final->next = new;
	return ;
}

void	ft_lstclear_bonus(t_list **lst)
{
	t_list	*n;

	if (!lst)
		return ;
	while (*lst)
	{
		n = (*lst)->next;
		free(*lst);
		*lst = n;
	}
	*lst = NULL;
}

t_list	*ft_lstlast_bonus(t_list *lst)
{
	t_list	*new;

	new = lst;
	if (!new)
		return (NULL);
	while (new->next != NULL)
	{
		new = new->next;
	}
	return (new);
}

t_list	*ft_lstnew_bonus(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front_bonus(t_list	**lst, t_list	*new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
