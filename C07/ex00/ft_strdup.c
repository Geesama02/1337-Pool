/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:48:03 by oait-laa          #+#    #+#             */
/*   Updated: 2023/09/27 18:52:24 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	new_str = (char *)malloc(i * 1 + 1);
	if (new_str != 0)
	{
		while (src[j])
		{
			new_str[j] = src[j];
			j++;
		}
		new_str[j] = '\0';
	}
	return (new_str);
}
