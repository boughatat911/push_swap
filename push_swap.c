/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:49:29 by nbougrin          #+#    #+#             */
/*   Updated: 2024/12/31 01:15:44 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/nbougrin/Desktop/push_swap/LIBFT/libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int n;

	i = 0;
	sign = 1;
	n = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			return(printf("Erorr\n"));
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	}
	return (printf("%d\n",n * sign));
}
char input_chek(char *av)
	{
		int i = 0;
		// printf("%s\n",av);
		while (av[i])
		{
			if(!((av[i] >= '0' && av[i] <= '9') || (av[i] == '+' || av[i] == '-')))
			{
				return('b');
			}
			i++;
		}
		// i = 0;
		// i = ft_atoi(av);
		// printf ("%d\n",i);
		return('a');
	}

int main(int ac, char **av)
{
	int i = 1;
	if (ac >= 2)
	{
		char j;
		char *str;
		int i = 1;

		while (av[i])
		{
			j = input_chek(av[i]);
			if (j == 'b')
				return(printf("Erorr\n"));
		// printf ("%d\n",ft_atoi(av[/i]));
			i++;
		}
		if (j != 0)
			return (j);
	}
}
