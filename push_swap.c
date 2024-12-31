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
#include "/mnt/homes/nbougrin/Desktop/pp/LIBFT/libft.h"

int main(int argc, char **argv)
{
	int i = 1;
	if (argc >= 2)
	{
		char *m;
		int j = 0;
		char *temp;	
		char *s;
		int ff;
			
		while (argv[i])
		{
			m = ft_strdup(argv[i]);
			s = ft_strjoin(m," ");
			temp = ft_strjoin(temp,s);
			i++;
		}	
		if(ff >= 2147483647 || ff < 0)
		printf("Error\n");
			ff = ft_atoi(temp);
		printf("%d\n",ff);
		i++;
	}
}
// int main(int argc, char **argv)
// {
//         int i = 1;
//     if (argc >= 2)
//     {
//         char *temp = NULL; // Initialize temp
//         while (i < argc)
//         {
//             char *m = strdup(argv[i]); // Duplicate the argument string
//             char *new_temp = ft_strjoin(temp, m);
//             temp = new_temp;            
//             i++;
//         }
//         printf("%s\n", temp);
//     }
//     return 0;
// }