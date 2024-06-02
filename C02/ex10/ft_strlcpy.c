/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:11:39 by oait-laa          #+#    #+#             */
/*   Updated: 2023/09/19 17:03:22 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (size != 0)
	{
		while (i != size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	while (src[j] != '\0')
	{
		j++;
	}
	dest[i] = '\0';
	return (j);
}
