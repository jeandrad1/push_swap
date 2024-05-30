/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:23:47 by jeandrad          #+#    #+#             */
/*   Updated: 2024/05/30 19:03:34 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_delete(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
}

void	ft_lstcheck(t_list *stack_a, int check)
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

void	ft_lst_order(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->content > tmp2->content)
			return ;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	exit(0);
}

void	ft_lst_inverted(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->content < tmp2->content)
			return ;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	ft_sa(stack_a);
	return ;
}

void	ft_write_lst(t_list **stack_a, int argc, char **argv, int i)
{
	t_list	*tmp;

	tmp = NULL;
	while (i < argc)
	{
		tmp = ft_lstnew(ft_atoi_mod(argv[i]));
		ft_lstadd_back(stack_a, tmp);
		ft_lstcheck(*stack_a, tmp->content);
		i++;
	}
	ft_lst_order(stack_a);
	ft_lst_inverted(stack_a);
	tmp = NULL;
}
