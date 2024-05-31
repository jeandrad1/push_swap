/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:25:39 by jeandrad          #+#    #+#             */
/*   Updated: 2024/05/31 19:24:42 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//It checks if the string has a valid format.

int	ft_str_format_check(char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i])
	{
		if ((!ft_isdigit(str[i]) && str[i] != 32
				&& !(str[i] == '-') && !(str[i] == '+'))
			|| ft_isalpha(str[i]))
			return (1);
		if (ft_isdigit(str[i]) && ft_isspace(str[i + 1]) && str[i + 2] != '\0')
			n++;
		i++;
	}
	if (n >= 1)
		return (0);
	else
		return (2);
}

//It checks the sign of the number and moves the pointer.
//It's used below

int	ft_check_sign_and_move_pointer(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == 45 || (str[*i] == 43 && ft_isdigit(str[*i + 1])))
	{
		if (str[*i] == 45)
			sign = -1;
		(*i)++;
	}
	return (sign);
}

//Modified atoi function to check if the number is valid.

int	ft_atoi_mod(char *str, t_list **stack_a, char **argv)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	n = 0;
	sign = ft_check_sign_and_move_pointer(str, &i);
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
	{
		ft_free_arg(argv);
	 	ft_lst_delete(stack_a);
		write(1, "KKKKK\n", 6);
		ft_display_error();
	}
	return (n);
}

//It checks the input to make movements.
//For the checker program.

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}
