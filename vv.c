void    sort_5(t_list **stack)
{
    t_list  *stack_b;
    
    stack_b = NULL;
    // First push 2 numbers to stack b
    pb(stack, &stack_b);
    pb(stack, &stack_b);
    
    // Sort remaining 3 in stack
    if ((*stack)->content > (*stack)->next->content)
        sa(stack);
    if ((*stack)->next->content > (*stack)->next->next->content)
    {
        rra(stack);
        if ((*stack)->content > (*stack)->next->content)
            sa(stack);
    }
    
    // Push back from b and insert in correct position
    while (stack_b)
    {
        if (stack_b->content < (*stack)->content)
            pa(&stack_b, stack);
        else if (stack_b->content > (*stack)->next->next->content)
        {
            ra(stack);
            pa(&stack_b, stack);
            rra(stack);
        }
        else
        {
            ra(stack);
            pa(&stack_b, stack);
        }
    }
}