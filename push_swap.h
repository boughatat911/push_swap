/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:49:25 by nbougrin          #+#    #+#             */
/*   Updated: 2024/12/26 04:49:26 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int		ft_satoi(const char *str, int *error);
int		input_check(const char *str);
int		check_duplicates(int *array, int size);
void	parse_arguments(int argc, char **argv, int **numbers, int *error);

#endif
