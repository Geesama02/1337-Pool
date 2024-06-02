/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:30:28 by oait-laa          #+#    #+#             */
/*   Updated: 2023/10/05 09:36:31 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && check_sep(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !check_sep(str[i], charset))
			i++;
	}
	return (count + 1);
}

int	count_len(char *str, char *charset, int i)
{
	int	c;

	c = 0;
	while (str[i] && check_sep(str[i], charset) == 0)
	{
		c++;
		i++;
	}
	return (c);
}

char	*one_char(char *str, char *charset, int i)
{
	int		j;
	char	*one_word;

	j = 0;
	one_word = (char *)malloc(count_len(str, charset, i) + 1);
	while (j < count_len(str, charset, i))
	{
		one_word[j] = str[j + i];
		j++;
	}
	one_word[j] = '\0';
	return (one_word);
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
		while (str[i] && check_sep(str[i], charset))
			i++;
		if (str[i])
		{
			chars[l] = one_char(str, charset, i);
			l++;
		}
		while (str[i] && !check_sep(str[i], charset))
			i++;
	}
	chars[l] = NULL;
	return (chars);
}
