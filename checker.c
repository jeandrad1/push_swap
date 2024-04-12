/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:36:04 by jeandrad          #+#    #+#             */
/*   Updated: 2024/04/10 16:36:48 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr_or_death(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strncmp(str, "rra\n",4))
		ft_rra_check(stack_a);
	else if (ft_strncmp(str, "rrb\n",4))
		ft_rrb_check(stack_b);
	else if (ft_strncmp(str, "rrr\n",4))
		ft_rrr_check(stack_a, stack_b);
	else
		ft_display_error();
}

void	ft_exec_sort(t_list **stack_a, t_list **stack_b, char *str)
{
	while (str != NULL)
	{
		if (ft_strncmp(str, "sa\n",3))
			ft_sa_check(stack_a);
		else if (ft_strncmp(str, "sb\n",3))
			ft_sb_check(stack_b);
		else if (ft_strncmp(str, "ss\n",3))
			ft_ss_check(stack_a, stack_b);
		else if (ft_strncmp(str, "pa\n",3))
			ft_pa_check(stack_b, stack_a);
		else if (ft_strncmp(str, "pb\n",3))
			ft_pb_check(stack_a, stack_b);
		else if (ft_strncmp(str, "ra\n",3))
			ft_ra_check(stack_a);
		else if (ft_strncmp(str, "rb\n",3))
			ft_rb_check(stack_b);
		else if (ft_strncmp(str, "rr\n",3))
			ft_rr_check(stack_a, stack_b);
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
		arg = ft_split(argv[1], ' ');
		while (arg[size] != NULL)
			size++;
		ft_check_write_lst(stack_a, size, arg, 0);
		free(arg);
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