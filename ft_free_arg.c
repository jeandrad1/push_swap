/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:02:04 by jeandrad          #+#    #+#             */
/*   Updated: 2024/05/14 20:01:04 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_free_arg(char **arg)
{
	int	i;

	i = 0;
	if (arg == NULL)
		return (NULL);
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
	return (NULL);
}
