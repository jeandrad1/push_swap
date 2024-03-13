/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:00:02 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/19 11:27:16 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
    ft_lstadd_front(&list, new1);
    ft_lstadd_front(&list, new2);
    printf("%s\n", ft_lstlast(list)->content);
    return (0);
}
*/
