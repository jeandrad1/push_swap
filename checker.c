/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:36:04 by jeandrad          #+#    #+#             */
/*   Updated: 2024/05/31 18:12:05 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Continuation of the movements function ft_exec_sort.
//It does some movements or displays an error and exits the program

void	ft_rrr_or_death(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "rra\n"))
		ft_rra_check(stack_a);
	else if (ft_strcmp(str, "rrb\n"))
		ft_rrb_check(stack_b);
	else if (ft_strcmp(str, "rrr\n"))
		ft_rrr_check(stack_a, stack_b);
	else
	{
		free(str);
		ft_lst_delete(stack_a);
		ft_lst_delete(stack_b);
		ft_display_error();
	}
}

//This function executes the movements of the checker program
//It continues in a loop until ctrl + D is pressed

void	ft_exec_sort(t_list **stack_a, t_list **stack_b, char *str)
{
	while (str)
	{
		if (ft_strcmp(str, "sa\n"))
			ft_sa_check(stack_a);
		else if (ft_strcmp(str, "sb\n"))
			ft_sb_check(stack_b);
		else if (ft_strcmp(str, "ss\n"))
			ft_ss_check(stack_a, stack_b);
		else if (ft_strcmp(str, "pa\n"))
			ft_pa_check(stack_b, stack_a);
		else if (ft_strcmp(str, "pb\n"))
			ft_pb_check(stack_a, stack_b);
		else if (ft_strcmp(str, "ra\n"))
			ft_ra_check(stack_a);
		else if (ft_strcmp(str, "rb\n"))
			ft_rb_check(stack_b);
		else if (ft_strcmp(str, "rr\n"))
			ft_rr_check(stack_a, stack_b);
		else
			ft_rrr_or_death(stack_a, stack_b, str);
		free(str);
		str = ft_get_next_line_gnl(0);
	}
}

//This function checks if the stack a is sorted and stack b is empty
//It ends the program with a KO or OK message

void	ft_check_sort(t_list *stack_a, t_list *stack_b)
{
	t_list	*original_stack_a;

	original_stack_a = stack_a;
	if (stack_a == NULL)
	{
		ft_lst_delete(&stack_a);
		ft_lst_delete(&stack_b);
		write(1, "KO\n", 3);
		exit (1);
	}
	while (stack_a->next != NULL)
	{
		if (stack_a->content > (stack_a->next)->content)
		{
			ft_lst_delete(&original_stack_a);
			ft_lst_delete(&stack_b);
			write(1, "KO\n", 3);
			exit (1);
		}
		stack_a = stack_a->next;
	}
	write(1, "OK\n", 3);
	return ;
}

//This function checks the arguments passed to the program
//It checks if the arguments are numbers and if they are in the correct format

void	ft_check_argv_c(int argc, char **argv, t_list **stack_a)
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
		arg = ft_split(argv[1], ' ');
		while (arg[size] != NULL)
			size++;
		ft_check_write_lst(stack_a, size, arg, 0);
		ft_free_arg(arg);
	}
	else if (argc >= 3)
		ft_check_write_lst(stack_a, argc, argv, 1);
}

//Main function of the checker program
//It checks the arguments.
//it executes the movements and checks if the stack is sorted

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*str;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else
	{
		val_args(argc, argv);
		ft_check_argv_c(argc, argv, &stack_a);
	}
	str = ft_get_next_line_gnl(0);
	ft_exec_sort(&stack_a, &stack_b, str);
	if (ft_lstsize(stack_b) != 0)
	{
		ft_lst_delete(&stack_a);
		ft_lst_delete(&stack_b);
		ft_display_error();
	}
	ft_check_sort(stack_a, stack_b);
	ft_lst_delete(&stack_a);
	ft_lst_delete(&stack_b);
	return (0);
}
