/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:13:25 by oait-laa          #+#    #+#             */
/*   Updated: 2023/09/16 13:36:25 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	newtab;

	i = 0;
	while (i != size / 2)
	{
		newtab = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = newtab;
		i++;
	}
}
