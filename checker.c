/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:36:04 by jeandrad          #+#    #+#             */
/*   Updated: 2024/04/13 12:20:14 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr_or_death(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "rra\n"))
		ft_rra(stack_a);
	else if (ft_strcmp(str, "rrb\n"))
		ft_rrb(stack_b);
	else if (ft_strcmp(str, "rrr\n"))
		ft_rrr(stack_a, stack_b);
	else
		ft_display_error();
}

void	ft_exec_sort(t_list **stack_a, t_list **stack_b, char *str)
{
	while (str != NULL)
	{
		if (ft_strcmp(str, "sa\n"))
			ft_sa(stack_a);
		else if (ft_strcmp(str, "sb\n"))
			ft_sb(stack_b);
		else if (ft_strcmp(str, "ss\n"))
			ft_ss(stack_a, stack_b);
		else if (ft_strcmp(str, "pa\n"))
			ft_pa(stack_b, stack_a);
		else if (ft_strcmp(str, "pb\n"))
			ft_pb(stack_a, stack_b);
		else if (ft_strcmp(str, "ra\n"))
			ft_ra(stack_a);
		else if (ft_strcmp(str, "rb\n"))
			ft_rb(stack_b);
		else if (ft_strcmp(str, "rr\n"))
			ft_rr(stack_a, stack_b);
		else
			ft_rrr_or_death(stack_a, stack_b, str);
		str = ft_get_next_line_gnl(0);
	}
}

void	ft_check_sort(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content > (stack_a->next)->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		stack_a = stack_a->next;
	}
	write(1, "OK\n", 3);
	return ;
}

void	ft_check_argv_c(int argc, char **argv, t_list **stack_a)
{
	int		size;
	char	**arg;

	arg = NULL;
	size = 0;
	if (argc == 2)
	{
		if (ft_str_format_check(argv[1]) == 1)
			return ;
		arg = ft_split(argv[1], ' ');
		while (arg[size] != NULL)
			size++;
		ft_check_write_lst(stack_a, size, arg, 0);
		fr_free_arg(arg);
	}
	else if (argc >= 3)
		ft_check_write_lst(stack_a, argc, argv, 1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*str;
//	int		size;

	stack_a = NULL;
	stack_b = NULL;
//	size = 0;
	if (argc < 2)
		return (0);
	else
		ft_check_argv_c(argc, argv, &stack_a);
	str = ft_get_next_line_gnl(0);
	ft_exec_sort(&stack_a, &stack_b, str);
	ft_check_sort(stack_a);
	return (0);
}
