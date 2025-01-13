/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:49:25 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/11 20:12:43 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* push_swap.h */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
// #include "track_leaks.h"
#define false 0
#define true 1

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

char	**ft_split(char const *s, char c);
char	**ft_split(char const *s, char c);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_free2darray(char **array);
void	ft_check_empty(char **av);
void	fill_stack(char **av, t_list **head);
void	check_dup(t_list *head);
void	parse_it(char **av, t_list **head);
long	ft_astoi(const char *str);

#endif