void    pa(t_list **stack_b, t_list **stack_a)
{
    t_list  *temp;

    if (!stack_b || !*stack_b || !stack_a)
        return;
    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = *stack_a;
    *stack_a = temp;

    write(1, "pa\n", 3);
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    t_list  *temp;

    if (!stack_a || !*stack_a || !stack_b)
        return;
    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = *stack_b;
    *stack_b = temp;
    write(1, "pb\n", 3);
}
-----------------------------------------


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
	stack_a = *stack;
	while (i > 0 )
	{
		ra(&stack_a);
		i--;
	}
	pb(&stack_a, &stack_b);
	//-------------------------------
	i = 0;	 
	*stack = stack_a;
	while (!(stack_a->index == 1))
	{
		// if (stack_a->content == 0)
		// {
		// stack_a = stack_a->next;
		// break;
		// }
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
	*stack = stack_a;
}