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
		rra(&a);
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