/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:05:36 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/13 18:20:45 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void f()
{
    system("leaks a.out");
}
// --------------------------------------------------------------------

void	s_rotate(t_list	**stack_a)
{
	t_list *tmp;
	t_list *tmp2;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return;
	tmp = (*stack_a);
	tmp2 = (*stack_a)->next;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	tmp2->next = tmp;
}

void	sa(t_list **stack_a)
{
	s_rotate(stack_a);
	write(1, "sa\n", 3);
}
// --------------------------------------------------------------------

void	sb(t_list **stack_b)
{
	s_rotate(stack_b);
	write(1, "sb\n", 3);
}

// --------------------------------------------------------------------
void	ss(t_list	**stack_a, t_list	**stack_b)
{
	s_rotate(stack_a);
	s_rotate(stack_b);
	write(1, "ss\n", 3);
}	
// --------------------------------------------------------------------
void	pa(t_list **stack_a, t_list  **stack_b)
{
	t_list	*new;
	t_list *last_b;
	t_list *temp;

	temp = *stack_b; 
	last_b->content = (*stack_b)->content;
	ft_lstadd_front(stack_a,last_b);
	*stack_b = temp->next;
	free(temp);
	write(1, "pa\n", 3);
}
// --------------------------------------------------------------------
void	pb(t_list **stack_a, t_list  **stack_b)
{
	t_list	*new;
	t_list *last_a;
	t_list *temp;

	temp = *stack_a; 
	last_a->content = (*stack_a)->content;
	ft_lstadd_front(stack_b,last_a);
	*stack_a = temp->next;
	free(temp);
	write(1, "pb\n", 3);
}
// --------------------------------------------------------------------
void	ra(t_list **stack_a)
{
	t_list *tmp;
	
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_a,tmp);
	write(1, "rb\n", 3);
}
// --------------------------------------------------------------------

void	rb(t_list **stack_b)
{
	t_list *tmp;
	
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_b,tmp);
	write(1, "rb\n", 3);
}

// --------------------------------------------------------------------
void	rr(t_list **stack_a, t_list  **stack_b)
{
	t_list *tmp_a;
	t_list *tmp_b;
	
	tmp_a = *stack_a;
	*stack_a = tmp_a->next;
	tmp_a->next = NULL;
	ft_lstadd_back(stack_a,tmp_a);

	tmp_b = *stack_b;
	*stack_b = tmp_b->next;
	tmp_b->next = NULL;
	ft_lstadd_back(stack_b,tmp_b);
	write(1, "rr\n", 3);
}
// --------------------------------------------------------------------
void	rra(t_list **stack_a)
{
	t_list	*temp;

	
}
// rra	
// rrb
// rrr

// --------------------------------------------------------------------


void	print_node(t_list *head)
{
	t_list *news = head;
	while (news)
	{
		printf("%d ", news->content);
		news = news->next;
	}
}
// --------------------------------------------------------------------
t_list *new_node(int value) 
{
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->content = value;
    node->next = NULL;
    return node;
}
// --------------------------------------------------------------------
int main(int ac, char **av)
{
	// atexit(f);
	t_list 	*a;
	t_list 	*b;
	a = NULL;
	b = NULL;
	if(ac > 1)
	{
		parse_it(av, &a);
		// pa(&head_1,&head);
		sa(&a);
		print_node(a);
	// int t =0;
	// t = a->content;
	// a->content = a->next->content;
	// printf("%d\n",a->content);
	// printf("%d\n",a->next->content);
		// ft_lstclear(&head);
	}
		return(0);	
}


#include <libc.h>
// int main() {
//     // Create and populate stacks
//     t_list *stack_a = NULL;
//     t_list *stack_b = NULL;

//     // Populate stack A
//     stack_a = new_node(3);
//     stack_a->next = new_node(2);
//     stack_a->next->next = new_node(1);

//     // Populate stack B
//     stack_b = new_node(6);
//     stack_b->next = new_node(5);
//     stack_b->next->next = new_node(4);
// 	ra(&stack_a);
// 	// print_node(stack_a);
// 	// printf("\n");
// 	// print_node(stack_b);
//     return 0;
// }