/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:49:29 by nbougrin          #+#    #+#             */
/*   Updated: 2024/12/30 21:12:22 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "/mnt/homes/nbougrin/Desktop/push_swap/LIBFT/libft.h"

// int main(int argc, char **argv)
// {
// 	int i = 1;
// 	while (argc > i)
// 	{
// 		char **intput = ft_split(argv[i],' ');
// 		int j = 0;
// 		while (intput[j])
// 		{
// 		int in = ft_atoi(intput[j]);
// 		printf("%d\n",in);	
// 			j++;
// 		free(intput);
// 		}
// 	i++;
// 	}	
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **split_string(char *str, char delimiter) {
    char **result = malloc(100 * sizeof(char *));
    int index = 0;

    char *token = strtok(str, &delimiter);
    while (token != NULL) {
        result[index++] = strdup(token);
        token = strtok(NULL, &delimiter);
    }
    result[index] = NULL;
    return result;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        char **split_values = split_string(argv[i], ' ');
        for (int j = 0; split_values[j] != NULL; j++) {
            printf("Parsed Value: %s\n", split_values[j]);
        }
        free(split_values);
    }
    return 0;
}
