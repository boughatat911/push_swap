#include "push_swap.h"
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

void sort_5(t_list **stack)
{
    t_list *stack_b = NULL;  // Initialize stack_b to NULL
    t_list *stack_a = *stack;
    t_list *tmp;

	int i = 0;
    while (stack_a)
	{
		if (stack_a->index == 0 || stack_a->index == 1)
		{
   		 pb(&stack_a, &stack_b);
			printf("{i => %d || node => %d}\n",i,stack_a->content);
		}
		else
		{
			printf("{i => %d || node => %d}\n",i,stack_a->content);
			ra(&stack_a);
		}
		i++;
	}
// while (*stack) // Use *stack, which always points to the current stack head
// {
//     if ((*stack)->index == 0 || (*stack)->index == 1) 
//     {
//         pb(stack, &stack_b);  // Pass the actual pointer to pb
//         // printf("{i => %d || node => %d}\n", i, stack_b->content); // Print stack_b's new head
//     } 
//     else 
//     {
//         // printf("{i => %d || node => %d}\n", i, (*stack)->content);
//         *stack = (*stack)->next;  // Advance the stack_a pointer manually
//     }
//     i++;
// }

// Reset stack_a to *stack for further processing
// stack_a;
print_node(stack_a);



    stack_a = *stack;
	print_node(stack_a);
    // printf("\n----\nstack_b = ");
    // print_node(stack_b);

    // // sort_3(&stack_a);
    // printf("\n----\n");
    // stack_a = *stack;
    // print_node(stack_a);
    // pb(&stack_b, &stack_a);
    // *stack = stack_a;
    // sort_2(stack);
}


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
        ft_indexing(a);
        sort_5(&a);
		// pb(&a,&b);
		// pb(&a,&b);
    // printf("\n----\n");
        // print_node(a);
		// printf("\n");
        // print_node(b);
	}
		return(0);	
}
