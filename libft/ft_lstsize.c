/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:01:51 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/19 10:02:08 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int main(){
    t_list *list;
    t_list *new1;
    t_list *new2;
    char str []= "Hello World";
    char str2 []= "Hello World2";
    char str3 []= "Hello World3";
    list = ft_lstnew(str);
    new1 = ft_lstnew(str2);
    new2 = ft_lstnew(str3);
    ft_lstadd_front(&list, new1);
    ft_lstadd_front(&list, new2);
    printf("%d\n", ft_lstsize(list));
    return (0);
}
*/