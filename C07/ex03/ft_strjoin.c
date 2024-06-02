/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:25:10 by oait-laa          #+#    #+#             */
/*   Updated: 2023/10/02 19:46:05 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}

int	ft_strlen(char **strs, int size)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_addsep(char *sep, int *sep_i, int *j, char *chars)
{
	while (sep[*sep_i] != 0)
	{
		chars[*j] = sep[*sep_i];
		(*j)++;
		(*sep_i)++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*chars;
	int		j;
	int		l;
	int		sep_i;

	i = 0;
	j = 0;
	sep_i = 0;
	chars = malloc(ft_strlen(strs, size) 
			+ size * ft_len(sep) + 1);
	while (i < size)
	{
		l = 0;
		while (strs[i][l])
			chars[j++] = strs[i][l++];
		if (i != size - 1)
			ft_addsep(sep, &sep_i, &j, chars);
		sep_i = 0;
		i++;
	}
	chars[j] = '\0';
	return (chars);
}
