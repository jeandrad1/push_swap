/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_and_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:37:36 by jeandrad          #+#    #+#             */
/*   Updated: 2024/05/30 18:42:49 by jeandrad         ###   ########.fr       */
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
				arg++;
			}
			i++;
		}
	}
}
