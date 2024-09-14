/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:37:22 by jeandrad          #+#    #+#             */
/*   Updated: 2024/09/14 15:24:37 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//It checks if the list is empty or if the list has only one element.

static void	ft_lstcheck_c(t_list *stack_a, int check)
{
	t_list	*tmp;

	tmp = stack_a;
	while (stack_a->next != NULL)
	{
		if (stack_a->content == check)
		{
			stack_a = tmp;
			ft_lst_delete(&stack_a);
			ft_display_error();
		}
		stack_a = stack_a->next;
	}
	return ;
}

//It writes the list with the values of the arguments.

void	ft_check_write_lst(t_list **stack_a, int argc, char **argv, int i)
{
	t_list	*tmp;
	int		num;

	tmp = NULL;
	while (i < argc)
	{
		num = ft_atoi_mod(argv[i], stack_a, argv);
		tmp = ft_lstnew(num);
		ft_lstadd_back(stack_a, tmp);
		ft_lstcheck_c(*stack_a, tmp->content);
		i++;
	}
	tmp = NULL;
}
