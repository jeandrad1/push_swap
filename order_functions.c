/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:24:49 by jeandrad          #+#    #+#             */
/*   Updated: 2024/03/30 10:40:11 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function checks the position of a number in an array that matches the content of the list.
// If it doesn't find a match, it returns -1.

int	ft_best_nbr_a(t_list *stack_a, int size, int *arr, int max)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (stack_a != NULL)
	{
		i = 0;
		while (stack_a->content != arr[i] && i < max)
		{
			if (i == max - 1)
				return (pos);
			i++;
		}
		stack_a = stack_a->next;
		pos++;
	}
	size = -1;
	return (size);
}

// This function finds the position of the smallest number in the array 'tmp'
// and then frees the memory allocated for the arrays 'arr_a', 'arr_b', and 'tmp'.

int	ft_best_comb_helper(int *arr_a, int *arr_b, int *tmp, int size)
{
	int	i;
	int	pos;

	pos = 0;
	i = -1;
	while (++i < size)
	{
		if (tmp[i] < tmp[pos])
			pos = i;
	}
	free(arr_a);
	free(arr_b);
	free(tmp);
	return (pos);
}

// This function calculates the best combination of moves to sort the stacks.
// It creates a new array 'tmp' and fills it with the maximum value of 'arr_a' and 'arr_b' if they have the same sign,
// or the sum of their absolute values if they have different signs.
// It then calls 'ft_best_comb_helper' to find the position of the smallest number in 'tmp'.

int	ft_best_comb(int *arr_a, int *arr_b, int size)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = (int *) malloc (sizeof(int) * size);
	if (!tmp || !arr_a || !arr_b)
		ft_display_error();
	while (++i < size)
	{
		if ((arr_a[i] > 0 && arr_b[i] > 0)
			|| (arr_a[i] < 0 && arr_b[i] < 0))
			tmp[i] = ft_max_nbr(arr_a[i], arr_b[i]);
		else
		{
			if (arr_a[i] < 0)
				arr_a[i] *= -1;
			if (arr_b[i] < 0)
				arr_b[i] *= -1;
			tmp[i] = arr_a[i] + arr_b[i];
		}
	}
	return (ft_best_comb_helper(arr_a, arr_b, tmp, size));
}

// This function moves the elements of 'stack_a' and 'stack_b' to sort them.
// It performs a series of rotations and reverse rotations based on the values of 'a' and 'b'.

int	ft_move_a(int a, int b, t_list **stack_a, t_list **stack_b)
{
	while (a < 0 && b < 0)
	{
		ft_rrr(stack_a, stack_b);
		a++;
		b++;
	}
	while (a > 0 && b > 0)
	{
		ft_rr(stack_a, stack_b);
		a--;
		b--;
	}
	if (a < 0)
		while (a++ < 0)
			ft_rra(stack_a);
	else if (a > 0)
		while (a-- > 0)
			ft_ra(stack_a);
	return (b);
}

// This function calculates the best number of moves to sort 'stack_b'.
// It creates two arrays 'arr_a' and 'arr_b' and fills them with the number of moves needed to sort 'stack_a' and 'stack_b', respectively.
// It then calls 'ft_best_comb' to find the best combination of moves and performs the moves on 'stack_a' and 'stack_b'.

int	ft_best_nbr_b(t_list **stack_b, int size_b, t_list **stack_a, int size_a)
{
	int		*arr_b;
	int		*arr_a;
	t_list	*tmp_b;
	int		i;

	i = -1;
	tmp_b = *stack_b;
	arr_a = (int *) malloc (sizeof(int) * size_b);
	arr_b = (int *) malloc (sizeof(int) * size_b);
	if (!arr_b || !arr_a)
		ft_display_error();
	while (++i < size_b)
		arr_b[i] = ft_the_needed_b(i, size_b);
	i = -1;
	while (++i < size_b && tmp_b != NULL)
	{
		arr_a[i] = ft_the_needed_a(*stack_a, tmp_b->content, size_a);
		tmp_b = tmp_b->next;
	}
	i = ft_best_comb(ft_intcpy(arr_a, size_b),
			ft_intcpy(arr_b, size_b), size_b);
	i = ft_move_a(arr_a[i], arr_b[i], stack_a, stack_b);
	free(arr_a);
	free(arr_b);
	return (i);
}
