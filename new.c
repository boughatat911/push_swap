
#include "push_swap.h"

void f()
{
    system("leaks a.out");
}
void del(int *content)
{
    if (content)
        free(content);
}
void	free2darray(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

long	ft_astoi(const char *str)
{
	int			sign;
	long		num;

	sign = 1;
	num  = 0;
	if ((*str == '-' || *str == '+') && *(str + 1)) //"++123"
	{
		if (*(str) == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10 )+ (*str - '0');
		if ((num * sign) > 2147483647 || ((num * sign) < -2147483648))
			return (2147483648);
		str++;
	}
	if (*str)
		return(2147483648);
	return (sign * num);
}

int ft_check_empty(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		return (false);
	return true;
}


t_list	*node_stored(t_list **lst)
{
	t_list *news;

	news = ft_atoi_to_node();
	while (news)
	{
		t_list *new_check = news->next;
		while (new_check)
		{
			if(new_check->content == news->content)
				write(2, "Error= likd_list\n", 17) , exit (1);
			new_check = new_check->next;
		}
		news = news->next;
	}
}

void	t_main(int ac, char **av)
{
	// int 	i;
	// int 	j;
	// char 	**new;
	// t_list 	*head;

	// (1) && (head = NULL,i = 1, j = 0);
	// while(av[i])
	// 	{
	// 		if(ft_check_empty(av[i]))
	// 			return(write(1, "Error_ft_check_empty\n", 21),1);
	// 		i++;
	// 	}
	
	// return(0);
}
