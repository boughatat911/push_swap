/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:49:29 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/06 19:34:26 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/mnt/homes/nbougrin/Desktop/push_swap/LIBFT/libft.h"


int	ft_check(char *str)
{
		int i;
		int y;
		char *nb;
		int k =0;

		i = 0;
		y = 0;
		nb = str;
		while (nb[k])
			k++;
			k--;
			if(nb[k] == '+' || nb[k] == '-')
				return(0);
				k = 0;
		while (*str)
		{
			if (!((*str == '+' || *str == '-') || (*str >= '0' && *str <= '9')))
				return(0);
			if(*str == '+')
			{
				if(k > 0)
				return(0);
				i++;
			}
			else if(*str == '-')
			{
				if(k > 0)
				return(0);
				y++;	
			}
			str++;
			k++;
		}
		if(i > 1 || y > 1)
			return(0);
		return(1);
}

int		ft_astoi(const char *str)
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
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (((n * sign) > 2147483647) ||((n * sign) < -2147483648))
	{
		return(write(1, "Error\n", 6));
		exit(0);
	}
	return (n * sign);
}
int main(int ac, char **av)
{
	int i = 1;
	int j = 0;
	char **new;
	char *str = malloc(sizeof(char));
	if(ac > 1)
	{
		while (av[i][j] == ' ')
			j++;
		if(!av[i][0] || (av[i][j] == '\0'))
			return(write(1, "Error\n", 6),0);
		
		
		j = 1;
		while (av[j])
			j++;
		while (av[i])
		{
			str = ft_strjoin(str,av[i]);
			if((j - 1) > i)
			str = ft_strjoin(str," ");
			i++;
		}
		new = ft_split(str, ' ');
		i = 0;
		int k = 1;
		int gg= 0;
		while(new[i])
		{
		k = ft_check(new[i]);
			if(k == 0)
				return(write(1, "Error\n", 6),0);
			i++;
		}
		i = 0;
		while (new[i])
		{
		int num = ft_astoi(new[i]);
		printf("%d\n", num);
			i++;
		}
	}
		return(0);	
}