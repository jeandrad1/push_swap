/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:24:17 by jeandrad          #+#    #+#             */
/*   Updated: 2024/03/04 17:24:17 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_split(t_list **stack_a, t_list **stack_b, int size)
{
	int	*dst;
	int	*arr;
	int	i;

	i = 0;
	if (size == 3)
	{
		ft_sort_three(stack_a);
		return ;
	}
	if (size == 5)
	{
		ft_sort_five(stack_a, stack_b);
		return ;
	}
	dst = ft_copy_cont(*stack_a, size);
	arr = ft_define_lis(dst, size, &i);
	ft_move_to_b(stack_a, stack_b, arr, i);
	ft_move_to_a(stack_a, stack_b);
	ft_search_min(stack_a, size);
	free (dst);
	free (arr);
}

int ft_check_format(char *str) {
    char *endptr;

    while (*str != '\0') 
	{
        while (ft_isspace((unsigned char)*str)) str++;
        if (*str == '\0') break;
        ft_strtol(str, &endptr, 10);
        if (endptr == str) return -1;
        str = endptr;
    }
    return 0;
}

void	ft_check_argv(int argc, char **argv, t_list **stack_a)
{
	int		size;
	char	**arg;

	arg = NULL;
	size = 0;

//	ft_check_format(argc, argv);
	if (argc == 2 && argv[1][0] != '\0')
	{
		arg = ft_split(argv[1], ' ');
		while (arg[size] != NULL)
			size++;
		ft_write_lst(stack_a, size, arg, 0);
		free(arg);
	}
	else if (argc >= 3)
		ft_write_lst(stack_a, argc, argv, 1);
	else
		return ;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
//	char	**arg;

	stack_a = NULL;
	stack_b = NULL;
//	arg = NULL;
	size = 0;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
	{
		ft_display_error();
		return (1);
	}
	else
		ft_check_argv(argc, argv, &stack_a);
	size = ft_lstsize(stack_a);
	if (size == 2)
		return (0);
	ft_lst_split(&stack_a, &stack_b, size);
	ft_lst_delete(&stack_a);
	ft_lst_delete(&stack_b);
	return (0);
}
