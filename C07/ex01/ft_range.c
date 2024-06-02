/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:19:46 by oait-laa          #+#    #+#             */
/*   Updated: 2023/10/02 19:47:45 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ints;
	int	size;

	size = max - min;
	i = 0;
	if (min >= max)
		return (NULL);
	ints = (int *)malloc(size * 4);
	if (ints != 0)
	{
		while (i < size)
		{
			ints[i] = min + i;
			i++;
		}
	}
	return (ints);
}
