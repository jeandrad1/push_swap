/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:56:12 by jeandrad          #+#    #+#             */
/*   Updated: 2024/03/27 11:47:22 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
		ft_lstlast(*lst)->next = new;
}
/*
#include <stdio.h>
int main(){
    t_list *list;
    t_list *new1;
    t_list *new2;
    char str []= "Test1";
    char str2 []= "Test2";
    char str3 []= "Test3";
    list = ft_lstnew(str);
    new1 = ft_lstnew(str2);
    new2 = ft_lstnew(str3);
    ft_lstadd_back(&list, new);
    ft_lstadd_back(&list, new2);
    printf("%s\n", ft_lstlast(list)->content);
    return (0);
}
*/