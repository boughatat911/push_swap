/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 02:30:00 by nbougrin          #+#    #+#             */
/*   Updated: 2024/12/31 02:45:00 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include <stdlib.h>
# include <unistd.h>
void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	ft_satoi(const char *str, int *error)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		else
			sign = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			*error = 1;
		i++;
	}
	if (str[i] != '\0')
		*error = 1;
	return ((int)(result * sign));
}

int	input_check(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	parse_arguments(int argc, char **argv, int **numbers, int *error)
{
	int	i;

	*numbers = malloc(sizeof(int) * (argc - 1));
	if (!*numbers)
		exit(1);
	i = 1;
	while (i < argc)
	{
		if (!input_check(argv[i]))
			*error = 1;
		else
			(*numbers)[i - 1] = ft_satoi(argv[i], error);
		if (*error)
		{
			free(*numbers);
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*numbers;
	int	error;
	int	i;

	error = 0;
	if (argc < 2)
		return (0);
	parse_arguments(argc, argv, &numbers, &error);
	if (check_duplicates(numbers, argc - 1))
	{
		free(numbers);
		write(2, "Error\n", 6);
		return (1);
	}

	// Print parsed numbers for verification
	i = 0;
	while (i < argc - 1)
	{
		ft_putnbr(numbers[i]);
		write(1, "\n", 1); // Print a newline after each number
		i++;
	}
	free(numbers);
	return (0);
}
