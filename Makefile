# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 04:49:32 by nbougrin          #+#    #+#              #
#    Updated: 2024/12/27 16:50:26 by nbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=cc

CFLAGS=-Wall -Wextra -Werror

AR=ar cr

RM=rm -f

SRCS=			

SRCS_BONUS=		

OBJS= $(SRCS:.c=.o)

OBJS_BONUS=$(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c libft.h
	$(CC) -c $(CFLAGS) $< -o $@

bonus : $(OBJS_BONUS)
	@$(AR) $(NAME) $(OBJS_BONUS)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all