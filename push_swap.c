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

//It splits the list into two parts and sorts them.

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

//It checks the format of the arguments.

int	ft_check_format(int argc, char **argv)
{
	int	control;

	control = 0;
	if (argc == 2)
		control = ft_str_format_check(argv[1]);
	return (control);
}

//It checks the arguments and writes them to the list.

void	ft_check_argv(int argc, char **argv, t_list **stack_a)
{
	int		size;
	char	**arg;

	arg = NULL;
	size = 0;
	if (argc == 2)
	{
		if (ft_str_format_check(argv[1]) == 1)
		{
			ft_lst_delete(stack_a);
			ft_display_error();
		}
		if (ft_str_format_check(argv[1]) == 2)
		{
			ft_lst_delete(stack_a);
			exit(1);
		}
		arg = ft_split(argv[1], ' ');
		while (arg[size] != NULL)
			size++;
		ft_write_lst(stack_a, size, arg, 0);
		ft_free_arg(arg);
	}
	else if (argc >= 3)
		ft_write_lst(stack_a, argc, argv, 1);
}

//Main call to the program.

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	if (argc < 2)
		return (0);
	else
	{
		val_args(argc, argv);
		ft_check_argv(argc, argv, &stack_a);
	}
	size = ft_lstsize(stack_a);
	if (size == 2)
	{
		ft_lst_delete(&stack_a);
		ft_lst_delete(&stack_b);
		return (0);
	}
	ft_lst_split(&stack_a, &stack_b, size);
	ft_lst_delete(&stack_a);
	ft_lst_delete(&stack_b);
	return (0);
}
