/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:57:56 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/19 09:58:57 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>

int main(){
    t_list *list;
    t_list *new1;
    char str []= "Hello World";
    char str2 []= "Hello World2";
    list = ft_lstnew(str);
    new1 = ft_lstnew(str2);
    ft_lstadd_front(&list, new1);
    printf("%s\n", list->content);
    printf("%s\n", list->next->content);
    return (0);
}
*/