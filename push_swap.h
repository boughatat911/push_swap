/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:49:25 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/13 19:42:49 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* push_swap.h */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
// #include "LIBFT_me/libft.h"
// #include "track_leaks.h"
#define false 0
#define true 1

typedef struct s_list
{
	int				content;
	
	struct s_list	*next;
}					t_list;

char	**ft_split(char const *s, char c);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_free2darray(char **array);
void	ft_check_empty(char **av);
void	fill_stack(char **av, t_list **head);
void	check_dup(t_list *head);
void	parse_it(char **av, t_list **head);
long	ft_astoi(const char *str);


void	sa(t_list	**stack_a);
void	sb(t_list	**stack_b);
void	ss(t_list	**stack_a, t_list	**stack_b);
void	pa(t_list	**stack_a, t_list	**stack_b);
void	pb(t_list	**stack_a, t_list	**stack_b);
void	ra(t_list	**stack_a);
void	rb(t_list	**stack_b);
void	rr(t_list	**stack_a, t_`list	**stack_b);
void	rra(t_list	**stack_a);
void	rrb(t_list	**stack_b);
void	rrr(t_list	**stack_a, t_list	**stack_b);
void	rotate_rra_rrb(t_list	**stack);
void	s_rotate(t_list	**stack_a);


#endif