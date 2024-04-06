/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:25:23 by jeandrad          #+#    #+#             */
/*   Updated: 2024/04/06 14:48:57 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_str_check(const char *str)
{
	int	n;

	n = 0;
	while (*str)
	{
		if ((!ft_isdigit(*str) && *str != 32) || ft_isalpha(*str))
		{
			ft_display_error();
			return (1);
		}
		if (ft_isdigit(*str))
			n++;
		str++;
	}
	if (n > 0)
		return (0);
	else
	{
		ft_display_error();
		return (1);
	}
}

int	arg_n_check(const char *str)
{
	if (*str != '+' && *str != '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			ft_display_error();
			return (1);
		}
		str++;
	}
	return (0);
}
