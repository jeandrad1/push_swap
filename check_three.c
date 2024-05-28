/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:35:02 by jeandrad          #+#    #+#             */
/*   Updated: 2024/05/16 17:24:01 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Continuation of the movements function ft_exec_sort.
//It executes the movement rra.
//It rotates the stack a down.

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

//Continuation of the movements function ft_exec_sort.
//It executes the movement rrb.
//It rotates the stack b down.

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

//Continuation of the movements function ft_exec_sort.
//It almost executes the movement rrr.
//It rotates the stack a and stack b down.
//Is used in the function below

void	ft_rotate_stack(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	tmp = *stack;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	tmp->next = NULL;
}

//Continuation of the movements function ft_exec_sort.
//It really executes the movement rrr.
//It rotates the stack a and stack b down.

void	ft_rrr_check(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_stack(stack_a);
	ft_rotate_stack(stack_b);
}
