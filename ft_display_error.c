/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:02:56 by jeandrad          #+#    #+#             */
/*   Updated: 2024/05/30 17:59:26 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//It displays an error message and exits the program
//The error message is displayed in the standard error output

void	ft_display_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
