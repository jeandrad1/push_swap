/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:25:39 by jeandrad          #+#    #+#             */
/*   Updated: 2024/04/06 15:47:22 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_str_format_check(const char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i])
	{
		if ((!ft_isdigit(str[i]) && str[i] != 32) || ft_isalpha(str[i]))
		{
			ft_display_error();
			return (1);
		}
		if (ft_isdigit(str[i]))
			n++;
		i++;
	}
	if (n > 0)
		return (0);
	else
	{
		ft_display_error();
		return (1);
	}

}

int	ft_n_format_check(const char *str)
{
	int	i;

	i = 0;
	if (str[i] != '+' && str[i] != '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_display_error();
			return (1);
		}
		i++;
	}
	return (0);
}
