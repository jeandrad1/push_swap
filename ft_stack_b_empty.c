/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_b_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:41:31 by jeandrad          #+#    #+#             */
/*   Updated: 2024/04/20 12:24:51 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_b_empty(t_list *stack_b)
{
	while (stack_b->next != NULL)
	{
		if (stack_b->content != NULL)
			ft_display_error();
		stack_b = stack_b->next;
	}
	return ;
}
