/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:33:03 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/03 12:33:03 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int ch)
{
	if (ch <= 122 && ch >= 97)
		ch = ch - 32;
	return (ch);
}

/*
#include <stdio.h>
int main() {
	char lowercase = 'a';
	char uppercase = toupper(lowercase);
	printf("Lowercase: %c\n", lowercase);
	printf("Uppercase: %c\n", uppercase);
	return (0);
}
*/