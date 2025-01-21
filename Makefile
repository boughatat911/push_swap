# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 04:49:32 by nbougrin          #+#    #+#              #
#    Updated: 2025/01/20 22:17:12 by nbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

CC=cc 

 CFLAGS= -g -fsanitize=address #-Wall -Wextra -Werror

RM=rm -f


SRCS= ../util/fun_linked_list.c parsing.c push_swap.c ../util/ft_split.c ../sort/op_1.c ../sort/op_2.c ../sort/op_3.c ../sort/sorting.c ../sort/algo.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
