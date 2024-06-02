/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:30:28 by oait-laa          #+#    #+#             */
/*   Updated: 2023/10/02 17:50:47 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	word_count(char *str, char *charset)
{
	int	count;
	int	i;
	int	j;
	int	n;

	i = 0;
	count = 0;
	while (str[i])
	{
		n = 0;
		j = 0;
		while (charset[j] && str[i] == charset[n])
		{
			n++;
			i++;
			if (charset[n] == '\0')
				count++;
			j++;
		}
		i++;
	}
	return (count + 1);
}

int	check_sep(char *str, char *charset, int *i)
{
	int	l;
	int	j;
	int	n;
	int	re;

	l = 0;
	j = 0;
	n = 0;
	re = *i;
	while (charset[l++])
	{
		while (charset[j] && str[*i] == charset[n])
		{
			n++;
			if (charset[n] == '\0' && str[*i + 1] != charset[0])
				return (1);
			else
				(*i)++;
			j++;
		}
	}
	*i = re;
	return (0);
}

int	count_len(char *str, char *charset, int i)
{
	int	c;

	c = i;
	while (str[i] && check_sep(str, charset, &c) == 0)
		c++;
	return (c - i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		n;
	int		l;
	char	**chars;

	i = 0;
	n = 0;
	l = 0;
	chars = (char **)malloc(word_count(str, charset) * sizeof(char *));
	while (str[i])
	{
		n = 0;
		chars[l] = (char *)malloc(count_len(str, charset, i) + 1);
		while (str[i] && check_sep(str, charset, &i) == 0)
			chars[l][n++] = str[i++];
		chars[l][n] = '\0';
		i++;
		l++;
	}
	chars[l] = 0;
	return (chars);
}
