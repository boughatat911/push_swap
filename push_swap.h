/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:49:25 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/10 19:32:18 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* push_swap.h */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

#define false 0
#define true 1





typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;


char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	ft_lstclear(t_list **lst, void (del)(int));
/* Utils */
// int		ft_isspace(char c);
// int		ft_isdigit(char c);
// void	ft_free_stack(t_stack *stack);
// t_stack	*ft_init_stack(int size);
// int		has_duplicates(int *numbers, int size);
// int		count_numbers_in_str(char *str);
// long	ft_atol(char *str, int *i, int *error);

// /* Parsing */
// t_stack	*parse_string(char *str);
// t_stack	*parse_args(int ac, char **av);

#endif