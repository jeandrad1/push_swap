/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:37:22 by jeandrad          #+#    #+#             */
/*   Updated: 2024/05/08 18:56:35 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstcheck_c(t_list *stack_a, int check)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content == check)
			ft_display_error();
		stack_a = stack_a->next;
	}
	return ;
}

void	ft_check_write_lst(t_list **stack_a, int argc, char **argv, int i)
{
	t_list	*tmp;

	tmp = NULL;
	while (i < argc)
	{
		tmp = ft_lstnew(ft_atoi_mod(argv[i]));
		ft_lstadd_back(stack_a, tmp);
		ft_lstcheck_c(*stack_a, tmp->content);
		i++;
	}
	tmp = NULL;
}
