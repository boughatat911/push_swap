/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:49:25 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/06 11:16:42 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* push_swap.h */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*numbers;
	int	size;
}	t_stack;

/* Utils */
int		ft_isspace(char c);
int		ft_isdigit(char c);
void	ft_free_stack(t_stack *stack);
t_stack	*ft_init_stack(int size);
int		has_duplicates(int *numbers, int size);
int		count_numbers_in_str(char *str);
long	ft_atol(char *str, int *i, int *error);

/* Parsing */
t_stack	*parse_string(char *str);
t_stack	*parse_args(int ac, char **av);

#endif