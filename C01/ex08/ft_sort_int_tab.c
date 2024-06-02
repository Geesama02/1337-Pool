/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:27:19 by oait-laa          #+#    #+#             */
/*   Updated: 2023/09/16 16:43:23 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (i != size)
	{
		j = 0;
		while (j != size)
		{
			if (tab[i] < tab[j])
			{
				n = tab[i];
				tab[i] = tab[j];
				tab[j] = n;
			}
			j++;
		}
		i++;
	}
}
