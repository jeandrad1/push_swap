/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:25:43 by jeandrad          #+#    #+#             */
/*   Updated: 2024/03/27 10:25:47 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function finds the best combination of moves to sort the list of 3 elements.

void	ft_sort_three(t_list **stack_a)
{
	int		i;
	int		j;
	int		x;
	t_list	*tmp;

	tmp = NULL;
	i = 0;
	j = 0;
	x = 0;
	while (!(i < j && j < x && x > i))
	{
		tmp = *stack_a;
		i = tmp->content;
		tmp = tmp->next;
		j = tmp->content;
		tmp = tmp->next;
		x = tmp->content;
		if ((i > j && j < x && x > i)
			|| (i > j && j > x && x < i) || (i < j && j > x && x > i))
			ft_sa(stack_a);
		if (i > j && j < x && x < i)
			ft_ra(stack_a);
		if (i < j && j > x && x < i)
			ft_rra(stack_a);
	}
}

// This function finds the best combination of moves to sort the list of 5 elements.

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 2;
	while (i-- > 0)
		ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_move_to_a(stack_a, stack_b);
	ft_search_min(stack_a, ft_lstsize(*stack_a));
}

//It moves the elements from stack_b to stack_a the best way possible

void	ft_move_to_a(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	while (*stack_b != NULL)
	{
		i = ft_best_nbr_b(stack_b, size_b, stack_a, size_a);
		if (i < 0)
			while (i++ < 0)
				ft_rrb(stack_b);
		else if (i > 0)
			while (i-- > 0)
				ft_rb(stack_b);
		ft_pa(stack_b, stack_a);
		size_a++;
		size_b--;
	}
}

//It moves the elements from stack_a to stack_b the best way possible

void	ft_move_to_b(t_list **stack_a, t_list **stack_b, int *arr, int max)
{
	int	i;
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	i = ft_best_nbr_a(*stack_a, size_a, arr, max);
	while (i != -1)
	{
		if (i > 0)
		{
			while (i-- > 0)
				ft_ra(stack_a);
		}
		ft_pb(stack_a, stack_b);
		i = ft_best_nbr_a(*stack_a, --size_a, arr, max);
	}
}
