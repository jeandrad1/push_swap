/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:09:45 by jeandrad          #+#    #+#             */
/*   Updated: 2024/05/08 18:55:53 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Continuation of the movements function ft_exec_sort.
//It executes the movement sa.
//It swaps the first two elements of stack a.

void	ft_sa_check(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	tmp2 = tmp->next;
	*stack_a = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return ;
}

//Continuation of the movements function ft_exec_sort.
//It executes the movement sb.
//It swaps the first two elements of stack b.

void	ft_sb_check(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = *stack_b;
	tmp2 = tmp->next;
	*stack_b = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return ;
}

//Continuation of the movements function ft_exec_sort.
//It executes the movement ss.
//It swaps the first two elements of stack a and stack b.

void	ft_ss_check(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	tmp2 = tmp->next;
	*stack_a = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	tmp = NULL;
	tmp2 = NULL;
	tmp = *stack_b;
	tmp2 = tmp->next;
	*stack_b = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return ;
}

//Continuation of the movements function ft_exec_sort.
//It executes the movement pa.
//It moves the first element of stack b to the top of stack a.

void	ft_pa_check(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	return ;
}

//Continuation of the movements function ft_exec_sort.
//It executes the movement pb.
//It moves the first element of stack a to the top of stack b.

void	ft_pb_check(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	return ;
}
