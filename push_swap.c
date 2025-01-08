/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:49:29 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/08 17:51:40 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"
#include "/mnt/homes/nbougrin/Desktop/push_swap/LIBFT/libft.h"

void f()
{
    system("leaks a.out");
}
void del(void *content)
{
    if (content)
        free(content);
}
void	free2darray(char **array, int n)
{
	while (n--)
		free(array[n]);
	free(array);
}

int	ft_check(char *str)
{
		int i;
		int y;
		char *nb;
		int k;

		i = 0;
		k = 0;
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

int	ft_astoi(const char *str)
{
	int		sign;
	long	num;
	long	tmp;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		tmp = num;
		num = (num * 10) + (*str - 48);
		if (tmp != num / 10 && sign == 1)
			return (-1);
		else if (tmp != num / 10 && sign == -1)
			return (0);
		str++;
	}
	if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return (sign * (int)num);
}
int main(int ac, char **av)
{
	int		i;
	int		j;
	char	**new;
	t_list 	*head;
	char 	*temp;
	int 	*vo;

	i = 1;
	j = 0;
	head = NULL;
	char *str;//= malloc(sizeof(char));
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
			temp = str;
			str = ft_strjoin(str,av[i]);
			free(temp);
			if((j - 1) > i)
			{
				temp = str;
				str = ft_strjoin(str," ");
				free(temp);
			}
			i++;
		}
		new = ft_split(str, ' ');
		free (str);
		i = 0;
		j = 1; // int k = 1;
		// int gg= 0;
		while(new[i])
		{
		j = ft_check(new[i]);
			if(j == 0)
				return(write(1, "Error\n", 6),0);
			i++;
		}
		i = 0;	
		while (new[i])
		{
			vo = malloc(sizeof(int));
			*vo = ft_astoi(new[i]);
			t_list *test = ft_lstnew(vo);
			ft_lstadd_back(&head,test);
			i++;
		}
		printf("{%d}\n",i);
		t_list *news = head;
		while (news)
    {
	 t_list *new_check = news->next;
		while (new_check)
		{
			if(*(int *)new_check->content == *(int *)news->content)
				return(write(2, "Error= likd_list\n", 17), 2);
        	new_check = new_check->next;
		}
        news = news->next;
    }
    // ft_lstclear(&news, del);
    ft_lstclear(&head, del);
		i = 0;		
		while (new[i]) ////////////////// mzal
			i++;
			free2darray(new,i);
		}
		// del(head);
	atexit(f);
		return(0);	
	}
    // ft_lstclear(&new, ft_del);
	
