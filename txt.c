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
static int count_nodes(t_list *stack)
{
    int count;
    t_list *tmp;
    
    count = 0;
    tmp = stack;
    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }
    return (count);
}


void    sort_5(t_list **stack)
{
    t_list  *stack_b;
    int     size;
    
    if (!stack || !*stack)
        return;
        
    size = count_nodes(*stack);
    if (size == 1)
        return;
    if (size == 2)
    {
        sort_21(stack);
        return;
    }
    if (size == 3)
    {
        sort_31(stack);
        return;
    }
    
    stack_b = NULL;
    
    // For 4 or 5 elements
    if (size >= 4)
        pb(stack, &stack_b);
    if (size == 5)
        pb(stack, &stack_b);
        
    // Sort remaining 3
    sort_31(stack);
    
    // Push back and insert in correct position
    while (stack_b)
    {
        pa(&stack_b, stack);
        if ((*stack)->content > (*stack)->next->content)
            sa(stack);
    }
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
		sort_5(&a);
		print_node(a);
	}
		return(0);	
}

// 
// #include <libc.h>
// int main() {
//     // Create and populate stacks
//     t_list *stack_a = NULL;
//     t_list *stack_b = NULL;

//     // Populate stack A
//     stack_a = new_node(2);
//     stack_a->next = new_node(3);
//     // stack_a->next->next = NULL;

//     // Populate stack B
//     // stack_b = new_node(6);
//     // stack_b->next = new_node(5);
//     // stack_b->next->next = new_node(4);
// 	// ra(&stack_a);
// 	sort_21(&stack_a);
// 	print_node(stack_a);
// 	// printf("\n");
// 	// print_node(stack_b);
//     return 0;
// }