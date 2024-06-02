/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:02:18 by oait-laa          #+#    #+#             */
/*   Updated: 2023/09/21 09:34:53 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	to_find_len(char *to_find, int *i)
{
	while (to_find[*i] != '\0')
	{
		*i = *i + 1;
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	l = 0;
	to_find_len(to_find, &i);
	if (i == 0)
		return (str);
	while (str[j] != '\0')
	{
		if (str[j] == to_find[l])
		{
			l++;
			if (l == i)
				return (str + j - i + 1);
		}
		else
			l = 0;
		j++;
	}
	return (0);
}
