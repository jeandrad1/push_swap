/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:25:00 by jeandrad          #+#    #+#             */
/*   Updated: 2024/05/31 16:12:04 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function returns the position of the
// maximum or minimum number in the array 'max_n_min'.
// If 'cont' is greater than the maximum number
// in 'max_n_min', it returns the position of the maximum number.
// If 'cont' is less than the minimum number in 
//'max_n_min', it returns the position of the minimum number.
// If 'cont' is neither the maximum nor the minimum, it returns 'size + 1'.

int	return_max_or_min(int cont, int *max_n_min, int size)
{
	if (cont > max_n_min[0])
		return (max_n_min[2]);
	if (cont < max_n_min[1])
		return (max_n_min[3]);
	return (size + 1);
}

// This function finds the maximum and
// minimum numbers in the list 'stack_a' and their positions.
// It stores the maximum and minimum numbers
// in 'max_n_min[0]' and 'max_n_min[1]', respectively,
// and their positions in 'max_n_min[2]' and 'max_n_min[3]', respectively.
// It then calls 'return_max_or_min'
// to return the position of the maximum or minimum number.

int	ft_max_or_min(t_list *stack_a, int cont, int size)
{
	int	max_n_min[5];

	max_n_min[0] = stack_a->content;
	max_n_min[1] = stack_a->content;
	max_n_min[2] = 0;
	max_n_min[3] = 0;
	max_n_min[4] = 1;
	while (stack_a != NULL)
	{
		if (stack_a->content >= max_n_min[0])
		{
			max_n_min[0] = stack_a->content;
			max_n_min[2] = max_n_min[4];
		}
		if (stack_a->content < max_n_min[1])
		{
			max_n_min[1] = stack_a->content;
			max_n_min[3] = max_n_min[4] - 1;
		}
		stack_a = stack_a->next;
		max_n_min[4]++;
	}
	return (return_max_or_min(cont, max_n_min, size));
}

// This function returns the smaller of two numbers 'a' and 'b'.
// If 'a' and 'b' are equal, it returns 'a1' (which is equal to 'a').
// If 'a' is less than 'b', it returns 'a1'.
// If 'b' is less than 'a', it returns 'b1' (which is equal to 'b').

int	ft_min_nbr(int a, int b)
{
	int	a1;
	int	b1;

	a1 = a;
	b1 = b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a == b)
		return (a1);
	if (a < b)
		return (a1);
	return (b1);
}

// This function returns the larger of two numbers 'a' and 'b'.
// If 'a' and 'b' are equal, it returns 'a'.
// If 'a' is greater than 'b', it returns 'a'.
// If 'b' is greater than 'a', it returns 'b'.

int	ft_max_nbr(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (a);
	if (b > a)
		return (b);
	else
		return (a);
}

// This function finds the position of the smallest number in
// 'stack_a' and performs the necessary moves to bring it to the top.
// It first calls 'ft_min' to find the position of the smallest number.
// If the position is less than or equal to 'size / 2',
// it performs 'pos' number of rotations.
// If the position is greater than 'size / 2',
// it performs 'size - pos' number of reverse rotations.

void	ft_search_min(t_list **stack_a, int size)
{
	int		pos;
	int		pos_min;
	int		min;
	t_list	*tmp;

	pos_min = 0;
	pos = 0;
	tmp = *stack_a;
	min = tmp->content;
	while (pos < size)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			pos_min = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	tmp = NULL;
	pos = ft_the_needed_b(pos_min, size);
	ft_move_a(pos, 0, stack_a, &tmp);
}
