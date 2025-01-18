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

	while (!(stack_a->index == 0))
	{
		stack_a = stack_a->next;
			i++;
	}
	// printf("<<%d>>\n",stack_a->index);
			// printf("%d\n",i);
			// int  j = 0;
		stack_a = *stack;
	while (i > 0 )
	{
		ra(&stack_a);
		i--;
	}
   		 pb(&stack_a, &stack_b);
		 //-------------------------------
		 i = 0;
	// printf("\n-----------\n stack_a = ");

		//  print_node(stack_a);
		 
	*stack = stack_a;
	while (!(stack_a->index == 1))
	{
		if (stack_a->content == 0)
		{
			stack_a = stack_a->next;
			break;
		}
		
		stack_a = stack_a->next;
			i++;
	}
		stack_a = *stack;
	while (i > 0 )
	{
		ra(&stack_a);
		i--;
	}
   		 pb(&stack_a, &stack_b);
		 //-------------------------------

		sort_3(&stack_a);			
	   		 pa(&stack_b, &stack_a);
	   		 pa(&stack_b, &stack_a);
	sort_2(&stack_a);

    // stack_a = *stack;
	print_node(stack_a);
	printf("\n-----------\n");
	print_node(stack_b);
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
		// ra(&a);
		// pb(&a,&b);
		// pb(&a,&b);
    // printf("\n----\n");
        // print_node(a);
		// printf("\n");
        // print_node(b);
	}
		return(0);	
}
