t_list *news = head;
while (news)
{
    t_list *new_check = news->next;  // Start from next node
    while (new_check)
    {
        if (*(int *)new_check->content == *(int *)news->content)  // Compare values, not pointers
            return(write(1, "Error\n", 6), 0);  // Return error for duplicates
        new_check = new_check->next;
    }
    news = news->next;
}