/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:25:39 by jeandrad          #+#    #+#             */
/*   Updated: 2024/04/13 12:37:40 by jeandrad         ###   ########.fr       */
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
	if (n > 1)
		return (0);
	else
	{
		ft_display_error();
		return (1);
	}

}

int	ft_atoi_mod(const char *str)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;

	if (str[i] == 45 || (str[i] == 43 && ft_isdigit(str[i + 1])))
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (!(ft_isdigit(str[i]) && str[i] != 32) || ft_isalpha(str[i]))
			ft_display_error();
		n = n * 10 + (str[i] - 48);
		i++;
	}
	if (!ft_isdigit(str[i]) && str[i] != '\0')
		ft_display_error();
	n *= sign;
	if (n > 2147483647 || n < -2147483648)
		ft_display_error();
	return ((int) n);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
