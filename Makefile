# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 04:49:32 by nbougrin          #+#    #+#              #
#    Updated: 2025/01/19 05:50:11 by nbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

CC=cc 

# CFLAGS=-Wall -Wextra -Werror

RM=rm -f

AR=$(CC)

SRCS=fun_linked_list.c parsing.c push_swap.c ft_split.c op_1.c op_2.c op_3.c sorting.c algo.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
