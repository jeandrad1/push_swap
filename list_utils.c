/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:23:47 by jeandrad          #+#    #+#             */
/*   Updated: 2024/03/27 12:13:44 by jeandrad         ###   ########.fr       */
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
	while (stack_a->next != NULL)
	{
		if (*(int *) stack_a -> content == check)
			ft_display_exit();
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
	int		*num;

	tmp = NULL;
	num = malloc(sizeof(int));
	if (num == NULL)
	{
		return ;
	}
	while (i < argc)
	{
		*num = ft_atoi(argv[i]);
		tmp = ft_lstnew(num);
		ft_lstadd_back(stack_a, tmp);
		ft_lstcheck(*stack_a, *(int *) tmp->content);
		i++;
	}
	ft_lst_order(stack_a);
	ft_lst_inverted(stack_a);
	tmp = NULL;
}
