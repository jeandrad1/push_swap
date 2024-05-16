/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:35:02 by jeandrad          #+#    #+#             */
/*   Updated: 2024/05/16 17:02:29 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra_check(t_list **stack_a)
{
	t_list	*last;
	t_list	*tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	tmp = *stack_a;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	tmp->next = NULL;
}

void	ft_rrb_check(t_list **stack_b)
{
	t_list	*last;
	t_list	*tmp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	tmp = *stack_b;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack_b;
	*stack_b = last;
	tmp->next = NULL;
}

void	ft_rotate_reverse(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	last = *stack;
	tmp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	tmp->next = NULL;
}

void	ft_rrr_check(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_reverse(stack_a);
	ft_rotate_reverse(stack_b);
}
