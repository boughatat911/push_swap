#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
// typedef struct s_list
// {
//     int *content;
//     struct s_list *next;
// } t_list;

void del(int *content)
{
    if (content)
        free(content);
}

void free2darray(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        free(array[i++]);  // Free each string
    free(array);  // Free the array itself
}

long ft_astoi(const char *str)
{
    long sign = 1;
    long num = 0;

    if ((*str == '-' || *str == '+') && *(str + 1))
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        num = (num * 10) + (*str - '0');
        if ((num * sign) > LONG_MAX || ((num * sign) < LONG_MIN))
            return (LONG_MAX + 1);  // Return a value outside the range of long
        str++;
    }
    if (*str)
        return (LONG_MAX + 1);  // Return a value outside the range of long
    return (sign * num);
}

void ft_check_empty(char **av)
{
    int i;
    int j = 1;

    while (av[j])
    {
        i = 0;
        while (av[j][i] && av[j][i] == ' ')
            i++;
        if (!av[j][i])
            (write(1, "Error_ft_check_empty\n", 21), exit(1));
        j++;
    }
}

void fill_stack(char **av, t_list **head)
{
    char **new;
    int i = 1;
    long atoi;

    while (av[i])
    {
        int j = 0;
        new = ft_split(av[i], ' ');
        if (new == NULL)  // Check if memory allocation was successful
        {
            ft_lstclear(head);
            write(1, "Error_ft_split\n", 16);
            exit(1);
        }
        while (new[j])
        {
            atoi = ft_astoi(new[j]);
            if (atoi == LONG_MAX + 1)  // Check for overflow
            {
                ft_lstclear(head);
                (write(1, "Error_ft_atoi\n", 14), free2darray(new), exit(1));
            }
            ft_lstadd_back(head, ft_lstnew(atoi));
			t_list *test = head;
			printf("%d\n",)test->content);
            j++;
        }
        free2darray(new);
        i++;
    }
}

void check_dup(t_list *head)
{
    t_list *news = head;
    while (news)
    {
        t_list *new_check = news->next;
        while (new_check)
        {
            if (*(int*)new_check->content == *(int*)news->content)  // Compare values, not pointers
            {
                ft_lstclear(&head);
                write(2, "Error= linked_list\n", 19);
                exit(1);
            }
            new_check = new_check->next;
        }
        news = news->next;
    }
}

void print_node(t_list *head)
{
    t_list *news = head;
    while (news)
    {
        printf("%d\n", *(news->content));  // Print the value of the content, not the pointer
        news = news->next;
    }
}

void parse_it(char **av, t_list **head)
{
    ft_check_empty(av);
    fill_stack(av, head);
    check_dup(*head);
}

int main(int ac, char **av)
{
    t_list *head = NULL;

    if (ac > 1)
    {
        parse_it(av, &head);
        print_node(head);
        ft_lstclear(&head);
    }
    return 0;
}
