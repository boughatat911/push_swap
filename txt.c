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
void    sort_21(t_list   **stack)
{
    t_list *tmp;

    tmp = *stack;
    tmp = tmp->next;
    if(tmp->index < (*stack)->index)
        sa(stack);
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
        // print_node(a);
		// printf("{%d}\n",check_in(&a));
	}
	return(0);
}
