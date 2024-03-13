/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:51:55 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/12 09:51:57 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *) str;
	while (n > 0)
	{
		*s = (unsigned char) c;
		s++;
		n--;
	}
	return (str);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char str[50] = "GeeksForGeeks is for programming geeks."; 
    printf("\nBefore ft_memset(): %s\n", str); 
    ft_memset(str, 'k', 8); 
    printf("After ft_memset():  %s\n", str); 
	return (0);
}
*/
