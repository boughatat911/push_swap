#include "push_swap.h"

static	size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

static	size_t	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static	char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

static	void	free2darray(char **array, int n)
{
	while (n--)
		free(array[n]);
	free(array);
}

char	**ft_split(char const *s, char c)
{
	size_t		count;
	size_t		i;
	char		**res;

	i = 0;
	if (!s)
		return (NULL);
	count = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		res[i] = malloc(sizeof (char) * (word_len(s, c) + 1));
		if (!res[i])
			return (free2darray(res, i), NULL);
		ft_strncpy(res[i], s, word_len(s, c));
		res[i++][word_len(s, c)] = '\0';
		s = s + word_len(s, c);
	}
	res[i] = NULL;
	return (res);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*final;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	final = ft_lstlast(*lst);
	final->next = new;
	return ;
}



void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void ft_lstclear(t_list **lst)
{
    t_list *n;

    if (!lst)  // Check if the list pointer is NULL
        return;
    while (*lst)
    {
        n = (*lst)->next;  // Save the next node
        free(*lst);        // Free the node itself
        *lst = n;
    }
    *lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// t_list	*ft_lstnew(int content)
// {
// 	t_list	*node;

// 	node = malloc(sizeof(t_list));
// 	if (!node)
// 		return (NULL);
// 	node->content = content;
// 	node->next = NULL;
// 	return (node);
// }

// t_list *ft_lstnew(int content)
// {
//     t_list *node;

//     node = malloc(sizeof(t_list));  // Allocate memory for the node
//     if (!node)
//         return (NULL);

//     node->content = malloc(sizeof(int));  // Allocate memory for the integer content
//     if (!node->content) {
//         free(node);  // Free the node if memory allocation for content fails
//         return (NULL);
//     }

//     *(node->content) = content;  // Store the value of content in the allocated memory
//     node->next = NULL;

//     return (node);
// }
t_list *ft_lstnew(int content)
{
    t_list *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = content;  // Directly store the integer
    node->next = NULL;
    return (node);
}


int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*sin;

	sin = lst;
	count = 0;
	while (sin)
	{
		sin = sin->next;
		count++;
	}
	return (count);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (s2 && !s1)
		return (ft_strdup(s2));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
static	char	*str_cpy(const char *str, char *dest)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dest;

	i = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	return (str_cpy(s1, dest));
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}
