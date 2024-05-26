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

/*
int	*ft_lis_util(int *dst, int *arr, int max, int size)
{
	int	i;
	int	j;
	int	*val;
	int	x;

	j = size;
	if (max <= 1 || max > size)
		return (NULL);
	val = ft_lis_util_helper(max - 1);
	while (max-- >= 1)
	{
		i = j;
		x = 0;
		while (--i >= 0)
		{
			if (arr[i] == max && ((dst[i] < val[max])
					|| val[max - 1] == 2147483647)
				&& ((dst[i] > val[max - 1]) || (x == 0)))
			{
				val[max - 1] = dst[i];
				j = i;
				x = 1;
			}
		}
	}
	free(arr);
	return (val);
}
*/

int	process_inner_loop(int *dst, int *arr, int *val, int max, int j)
{
    int	i;
    int	x;

    i = j;
    x = 0;
    while (--i >= 0)
    {
        if (arr[i] == max && ((dst[i] < val[max])
                || val[max - 1] == 2147483647)
            && ((dst[i] > val[max - 1]) || (x == 0)))
        {
            val[max - 1] = dst[i];
            j = i;
            x = 1;
        }
    }
    return (j);
}

int	*ft_lis_util(int *dst, int *arr, int max, int size)
{
    int	j;
    int	*val;

    j = size;
    if (max <= 1 || max > size)
        return (NULL);
    val = ft_lis_util_helper(max - 1);
    while (max-- >= 1)
    {
        j = process_inner_loop(dst, arr, val, max, j);
    }
    free(arr);
    return (val);
}

int	*ft_define_lis(int *dst, int size, int *max)
{
	int	*arr;
	int	i;
	int	j;

	i = 0;
	j = -1;
	arr = (int *) malloc (sizeof(int) * size);
	if (!arr)
		ft_display_error();
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
	return (ft_lis_util(dst, arr, *max + 1, size));
}
