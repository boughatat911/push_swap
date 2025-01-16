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

void    ft_indexing(t_list *stack)
{
    t_list  *tmp;
    t_list  *check;
    int     indix;

    if (!stack)
        return;

    tmp = stack;
    while (tmp)
    {
        indix = 0;
        check = stack;
        while (check)
        {
            if (check->content < tmp->content)
                indix++;
            check = check->next;
        }
        tmp->index = indix;
        tmp = tmp->next;
    }
}
void    sort_5(t_list   **stack)
{
    t_list *tmp;
    pa(stack, &tmp);
    pa(stack, &tmp);
    sort_3(stack);
    pb(stack, &tmp);
    pb(stack, &tmp);
    sort_2(stack);
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
		// sort_5(&a);
    // printf("%d")

		// print_node(a);
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