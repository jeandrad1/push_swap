/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:07:30 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/22 11:40:20 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*ft_free(char **str, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free (str[i]);
		i++;
	}
	free (str);
	return (NULL);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (*str)
	{
		if (*str != c && t == 0)
		{
			i++;
			t = 1;
		}
		else if (*str == c)
			t = 0;
		str++;
	}
	return (i);
}

static char	*dup_word(const char *str, int fl, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *) malloc((end - fl + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (fl < end)
		word[i++] = str[fl++];
	word[i] = '\0';
	return (word);
}

static char	**ft_split_core(char const *s, char c, char **st)
{
	int		count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	count = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && count < 0)
			count = i;
		else if ((s[i] == c || i == ft_strlen(s)) && count >= 0)
		{
			st[j] = dup_word(s, count, i);
			if (!st[j])
			{
				return (ft_free(st, j));
			}
			count = -1;
			j++;
		}
		i++;
	}
	st[j] = 0;
	return (st);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_split_core(s, c, split);
	return (split);
}
/*
#include <stdio.h>
int main(void) {
    char const *s = "Hello,World,How,Are,You";
    char c = ',';
    char **result = ft_split(s, c);
    if (result) {
        int i = 0;
        while (result[i]) {
            printf("%s\n", result[i]);
            i++;
        }
    }
    return 0;
}
*/