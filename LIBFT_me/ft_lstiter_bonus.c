/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:29:31 by nbougrin          #+#    #+#             */
/*   Updated: 2024/11/11 15:12:59 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*nond;

	if (!f || !lst)
		return ;
	nond = lst;
	while (nond != NULL)
	{
		f(nond->content);
		nond = nond->next;
	}
}
