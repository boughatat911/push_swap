# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 04:49:32 by nbougrin          #+#    #+#              #
#    Updated: 2025/01/11 20:22:24 by nbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap.a

CC=cc

CFLAGS=-Wall -Wextra -Werror

AR=ar cr

RM=rm -f

SRCS= fun_linked_list.c parsing.c push_swap.c ft_split.c

OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c push_swap.h
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
