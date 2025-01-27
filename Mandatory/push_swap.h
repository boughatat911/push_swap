/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:51:30 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/27 12:51:33 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

void	algo_part_2(t_list	**a, t_list	**b, int max);
void	sort(t_list	**a, t_list	**b);
void	sort_2(t_list	**stack);
void	sort_3(t_list	**stack);
void	ft_indexing(t_list	*stack);
int		ft_lstsize(t_list	*lst);
void	algo(t_list	**a, t_list	**b);
void	check_index(t_list	**stack);
void	sort(t_list	**a, t_list	**b);
int		check_sort(t_list	**a);
void	sort_5(t_list	**stack);
void	sort_5_5(t_list	*stack_a, t_list	*stack_b, t_list	**stack);

int		ft_check_indix(t_list	*stack, int len);
t_list	*ft_lstlast(t_list	*lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list	**lst, t_list	*new);
void	ft_lstadd_front(t_list	**lst, t_list	*new);
void	ft_lstclear(t_list	**lst);

char	**ft_split(char const *s, char c);
void	ft_check_empty(char	**av);
void	ft_free2darray(char	**array);
void	fill_stack(char	**av, t_list	**head);
void	check_dup(t_list	*head);
void	parse_it(char	**av, t_list	**head);
long	ft_astoi(const char *str);

void	sa(t_list	**stack_a);
void	sb(t_list	**stack_b);
void	ss(t_list	**stack_a, t_list	**stack_b);
void	pa(t_list	**stack_a, t_list	**stack_b);
void	pb(t_list	**stack_a, t_list	**stack_b);
void	ra(t_list	**stack_a);
void	rb(t_list	**stack_b);
void	rr(t_list	**stack_a, t_list	**stack_b);
void	rra(t_list	**stack_a);
void	rrb(t_list	**stack_b);
void	rrr(t_list	**stack_a, t_list	**stack_b);
void	rotate_rra_rrb(t_list	**stack);
void	s_rotate(t_list	**stack_a);

#endif
