/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:00:18 by oait-laa          #+#    #+#             */
/*   Updated: 2023/10/02 19:56:09 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	skip(char *str, int *i, int *neg)
{
	while (str[*i] == ' ' || str[*i] >= 9 && str[*i] <= 13)
	{
		(*i)++;
	}
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*neg = *neg * -1;
		(*i)++;
	}
}

int	power(int n, int l)
{
	int	r;

	r = 1;
	while (l > 0)
	{
		r = r * n;
		l--;
	}
	return (r);
}
