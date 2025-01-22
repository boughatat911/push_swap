# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 04:49:32 by nbougrin          #+#    #+#              #
#    Updated: 2025/01/22 21:31:26 by nbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap

B_NAME	= 	checker

Flags	= 	-Wall -Wextra -Werror
FILES	=	Mandatory/push_swap.c Mandatory/parsing.c \
			Mandatory/sort/algo.c Mandatory/sort/sorting.c Mandatory/sort/op_1.c Mandatory/sort/op_2.c Mandatory/sort/op_3.c \
			Mandatory/utils/ft_split.c Mandatory/utils/fun_linked_list.c Mandatory/utils/utils.c \

B_FILES =	Bonus/checker.c \
			Bonus/utils/ft_split.c Bonus/utils/fun_linked_list.c Bonus/utils/parsing.c Bonus/utils/utils.c \
			Bonus/utils/get_next_line.c Bonus/utils/get_next_line_utils.c \
			Bonus/op/op_b_1.c Bonus/op/op_b_2.c Bonus/op/op_b_3.c \

OBJ	=	$(FILES:.c=.o)

B_OBJ	=	$(B_FILES:.c=.o)

all		: $(NAME)

$(B_NAME)	: $(B_OBJ)
		cc $(Flags) $(B_OBJ) -o $(B_NAME)

$(NAME)		: $(OBJ)
		cc $(Flags) $(OBJ) -o $(NAME) 

bonus		: $(B_NAME)

bonus/%.o	: bonus/%.c /bonus/push_swap_bonus.h
		cc $(Flags) -c $< -o $@

Mandatory/%.o	: mandatory/%.c /mandatory/push_swap.h
		cc $(Flags) -c $< -o $@
	
clean		:
		@rm -rf $(OBJ) $(B_OBJ)

fclean		: clean
		@rm -rf $(NAME) $(B_NAME)

re		: fclean all