//Biblioteca
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


//Funciones de listas
t_list* ft_lstnew(void *content)
{
    t_list	*new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->content = content;
    new_node->next = 0;
    return new_node;
}
void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
    t_list	*tmp;

    if (!*lst)
    {
        *lst = new_node;
        return ;
    }
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;
}

void    ft_lstcheck(t_list *lst, int content)
{
    while (lst)
    {
        if (*(int*)(lst->content) == content)
        //if (lst->content == content)
        {
            printf("Error\n");
			return ;
        }
        lst = lst->next;
    }
}

void    ft_lst_order(t_list **lst)
{
    t_list	*tmp;
    t_list	*tmp2;
    int		aux;

    tmp = *lst;
    aux = *(int*)(tmp->content);
    while (tmp)
    {
        tmp2 = tmp->next;
        while (tmp2)
        {
		if (*(int*)(tmp->content) > *(int*)(tmp2->content))
			{
    			aux = *(int*)(tmp->content);
    			*(int*)(tmp->content) = *(int*)(tmp2->content);
    			*(int*)(tmp2->content) = aux;
			}
        tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
}

void   ft_lst_inverted(t_list **lst)
{
    t_list	*tmp;
    t_list	*tmp2;
    int		aux;

    tmp = *lst;
    while (tmp)
    {
        tmp2 = tmp->next;
        while (tmp2)
        {
			if (*(int*)(tmp->content) < *(int*)(tmp2->content))
			{
				aux = *(int*)(tmp->content);
				*(int*)(tmp->content) = *(int*)(tmp2->content);
				*(int*)(tmp2->content) = aux;
			} 
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
}

void	ft_lstprint(t_list *lst)
{
    t_list	*tmp;

    tmp = lst;
    while (tmp)
    {
        printf("%d\n", *(int*)(tmp->content));
        tmp = tmp->next;
    }
}

//Libft
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
int	ft_atoi(const char *str)
{
	int	numsign;
	int	i;
	int	num;

	i = 0;
	numsign = 1;
	num = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		numsign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]) > 0)
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * numsign);
}

size_t    ft_strlen(const char *s)
{
    size_t	i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

static void	*ft_free(char **str, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free (str[i]);
		i++;
	}
	free (str);
	return (0);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (*str)
	{
		if (*str != c && t == 0)
		{
			i++;
			t = 1;
		}
		else if (*str == c)
			t = 0;
		str++;
	}
	return (i);
}

static char	*dup_word(const char *str, int fl, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *) malloc((end - fl + 1) * sizeof(char));
	if (!word)
		return (0);
	while (fl < end)
		word[i++] = str[fl++];
	word[i] = '\0';
	return (word);
}

static char	**ft_split_core(char const *s, char c, char **st)
{
	int		count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	count = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && count < 0)
			count = i;
		else if ((s[i] == c || i == ft_strlen(s)) && count >= 0)
		{
			st[j] = dup_word(s, count, i);
			if (!st[j])
			{
				return (ft_free(st, j));
			}
			count = -1;
			j++;
		}
		i++;
	}
	st[j] = 0;
	return (st);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	split = ft_split_core(s, c, split);
	return (split);
}

//Funcion principal push_swap
void	ft_write_lst(t_list **stack_a, int argc, char **argv, int i)
{
	t_list	*tmp;

	tmp = 0;
	while (i < argc)
	{
		int *num = malloc(sizeof(int));
	*num = ft_atoi(argv[i]);
	tmp = ft_lstnew(num);
		ft_lstadd_back(stack_a, tmp);
		ft_lstcheck(*stack_a, *(int*)(tmp->content));
		i++;
	}
	ft_lst_order(stack_a);
	ft_lst_inverted(stack_a);
	tmp = 0;
}

void	ft_check_argv(int argc, char **argv, t_list **stack_a)
{
	int		size;
	char	**arg;

	arg = 0;
	size = 0;
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		while (arg[size] != 0)
			size++;
		ft_write_lst(stack_a, size, arg, 0);
		free(arg);
	}
	else if (argc >= 3)
		ft_write_lst(stack_a, argc, argv, 1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	char	**arg;

	stack_a = 0;
	stack_b = 0;
	arg = 0;
	size = 0;
	if (argc < 2 )
    {
        printf("Error 1\n");
		return (0);
    }
	ft_check_argv(argc, argv, &stack_a);
    ft_lstprint(stack_a);
    printf("Stack A\n");
	return (1);
}
