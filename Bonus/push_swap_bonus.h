/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:51:09 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/27 12:51:14 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

void	checker(t_list	**a, t_list	**b);
void	ft_check_operations(char	*op, t_list	**a, t_list	**b, char	**str);
void	ft_check_empty_bonus(char	**av);
void	check_dup_bonus(t_list	*head);
void	fill_stack_bonus(char	**av, t_list	**head);
void	ft_indexing_bonus(t_list	*stack);
void	ft_exit(t_list	**a, t_list	**b, int num);

char	**ft_split_bonus(char const	*s, char c);
int		ft_strcmp(const char	*s1, const char	*s2);
long	ft_atoi_bonus(const char	*str);
int		ft_check_indix_bonus(t_list	*stack, int len);
void	free_bonus(char **array);
int		check_sort_bonus(t_list	**a);
void	ft_indexing_bonus(t_list *stack);
int		ft_op(char	*op);

void	ft_lstadd_back_bonus(t_list **lst, t_list *new);
void	ft_lstclear_bonus(t_list **lst);
t_list	*ft_lstlast_bonus(t_list *lst);
t_list	*ft_lstnew_bonus(int content);
void	ft_lstadd_front_bonus(t_list	**lst, t_list	*new);
int		ft_lstsize_bonus(t_list	*lst);

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

void	s_rotate(t_list	**stack_a);
void	sa(t_list	**stack_a);
void	sb(t_list	**stack_b);
void	ss(t_list	**stack_a, t_list	**stack_b);
void	rr(t_list	**stack_a, t_list	**stack_b);
void	rotate_rra_rrb(t_list	**stack);
void	rra(t_list	**stack_a);
void	rrb(t_list	**stack_b);
void	rrr(t_list	**stack_a, t_list	**stack_b);
void	pa(t_list	**stack_b, t_list	**stack_a);
void	pb(t_list	**stack_a, t_list	**stack_b);
void	ra(t_list	**stack_a);
void	rb(t_list	**stack_b);

#endif
