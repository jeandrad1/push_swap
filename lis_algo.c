/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:23:23 by jeandrad          #+#    #+#             */
/*   Updated: 2024/03/30 10:41:05 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_lis_util_helper(int max)
{
	int	*val;

	val = (int *) malloc (sizeof(int) * (max + 1));
	if (!val || max <= 0)
		ft_display_error();
	ft_memset(val, 0, sizeof(int) * max);
	val[max] = 2147483647;
	return (val);
}

static int	process_inner_loop(int **dst_arr, int *val, int max_j[2])
{
	int	i;
	int	x;

	i = max_j[1];
	x = 0;
	while (--i >= 0)
	{
		if (dst_arr[1][i] == max_j[0] && ((dst_arr[0][i] < val[max_j[0]])
				|| val[max_j[0] - 1] == 2147483647)
			&& ((dst_arr[0][i] > val[max_j[0] - 1]) || (x == 0)))
		{
			val[max_j[0] - 1] = dst_arr[0][i];
			max_j[1] = i;
			x = 1;
		}
	}
	return (max_j[1]);
}

int	*ft_lis_util(int *dst, int *arr, int max, int size)
{
	int	*val;
	int	*dst_arr[2];
	int	max_j[2];

	dst_arr[0] = dst;
	dst_arr[1] = arr;
	max_j[0] = max;
	max_j[1] = size;
	if (max <= 1 || max > size)
		return (NULL);
	val = ft_lis_util_helper(max - 1);
	while (max_j[0]-- >= 1)
	{
		max_j[1] = process_inner_loop(dst_arr, val, max_j);
	}
	free(arr);
	return (val);
}

static void	ft_define_lis_aux(int *dst, int *arr, int size, int *max)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (i < size)
		arr[i++] = 1;
	while (++j < size)
	{
		i = j - 1;
		while (++i < size)
		{
			if (dst[j] < dst[i] && arr[j] == arr[i])
			{
				arr[i] += 1;
				if (arr[i] > *max)
					*max = arr[i];
			}
		}
	}
}

int	*ft_define_lis(int *dst, int size, int *max)
{
	int	*arr;
	int	*result;

	arr = (int *) malloc (sizeof(int) * size);
	if (!arr)
		ft_display_error();
	ft_define_lis_aux(dst, arr, size, max);
	result = ft_lis_util(dst, arr, *max + 1, size);
	return (result);
}
