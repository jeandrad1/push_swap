/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:25:21 by jeandrad          #+#    #+#             */
/*   Updated: 2024/03/30 10:40:44 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function adjusts the values of 'min' and 'max' based on the size of the list.
// If 'min' or 'max' is greater than half the size of the list, it subtracts the size of the list from 'min' or 'max'.
// This is done to handle the case where the list is circular and the minimum or maximum value is closer to the end of the list than the beginning.

int	ft_the_needed(int min, int max, int size)
{
	int	i;

	if (min > (size / 2))
		min = min - size;
	if (max > (size / 2))
		max = max - size;
	i = ft_min_nbr(max, min);
	return (i);
}

// This function adjusts the value of 'max' based on the size of the list.
// If 'max' is greater than half the size of the list, it subtracts the size of the list from 'max'.
// This is done to handle the case where the list is circular and the maximum value is closer to the end of the list than the beginning.

int	ft_the_needed_b(int max, int size)
{
	if (max > (size / 2))
		max = max - size;
	return (max);
}

// This function finds the position of 'cont' in 'stack_a' and adjusts it based on the size of the list.
// If the position is greater than half the size of the list, it subtracts the size of the list from the position.
// This is done to handle the case where the list is circular and 'cont' is closer to the end of the list than the beginning.

int	ft_the_needed_a(t_list *stack_a, int cont, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stack_a;
	i = ft_max_or_min(stack_a, cont, size);
	if (i != size + 1)
		return (ft_the_needed_b(i, size));
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (cont < stack_a->content && cont > tmp->content)
		return (0);
	i = 1;
	while (!(cont > stack_a->content && cont < (stack_a->next)->content))
	{
		stack_a = stack_a->next;
		i++;
	}
	return (ft_the_needed_b(i, size));
}

// This function copies the content of the linked list 'stack_a' into a new dynamically allocated array 'arr'.
// It first allocates memory for 'arr' with a size of 'size + 1'.
// If the allocation fails, it calls 'ft_display_error' to handle the error.
// It then traverses 'stack_a', copying each 'content' into 'arr'.
// It returns the pointer to the new array 'arr'.

int	*ft_copy_cont(t_list *stack_a, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *) malloc (sizeof(int) * size + 1);
	if (!arr)
		ft_display_error();
	while (stack_a != NULL)
	{
		arr[i++] = (stack_a)->content;
		stack_a = (stack_a)->next;
	}
	return (arr);
}

// This function copies the contents of the array 'arr' into a new array 'cpy'.
// It first allocates memory for 'cpy' with the same size as 'arr'.
// If the allocation fails or if 'arr' is NULL, it calls 'ft_display_error' to handle the error.
// It then copies each element of 'arr' into 'cpy'.

int	*ft_intcpy(int	*arr, int size)
{
	int	i;
	int	*cpy;

	i = 0;
	cpy = (int *) malloc (sizeof(int) * size);
	if (!arr || !cpy)
		ft_display_error();
	while (i < size)
	{
		cpy[i] = arr[i];
		i++;
	}
	return (cpy);
}
