/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_and_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:37:36 by jeandrad          #+#    #+#             */
/*   Updated: 2024/05/31 16:45:16 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function parses and checks if the arguments are valid.

void	val_args(int argc, char **argv)
{
	int		i;
	char	*arg;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			arg = argv[i];
			while (*arg != '\0')
			{
				if (!ft_isdigit(*arg) && !ft_isspace(*arg)
					&& *arg != '-' && *arg != '+')
				{
					ft_display_error();
				}
				if ((*arg == '-' && !ft_isdigit(*(arg +1)))
					|| (*arg == '+' && !ft_isdigit(*(arg +1))))
					ft_display_error();
				arg++;
			}
			i++;
		}
	}
}
