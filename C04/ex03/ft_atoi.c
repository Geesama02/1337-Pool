/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:30:06 by oait-laa          #+#    #+#             */
/*   Updated: 2023/09/26 14:50:41 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	if_num(char *str, int *r, int i, int *sp)
{
	if (str[i] >= '0' && str[i] <= '9')
	{
		*r = *r * 10;
		*r = *r + (str[i] - '0');
		*sp = 1;
	}
}

void	if_neg(char str, int *neg, int sp)
{
	if (str == '-' && sp == 0)
	{
		*neg = !*neg;
	}
}

void	if_space(char *str, int *index)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	*index = i;
}

int	ft_atoi(char *str)
{
	int	i;
	int	r;
	int	neg;
	int	sp;

	sp = 0;
	r = 0;
	neg = 0;
	if_space(str, &i);
	while (str[i])
	{
		if_neg(str[i], &neg, sp);
		if (!(str[i] >= '0' && str[i] <= '9')
			&& ((str[i] != '-' && str[i] != '+') || sp == 1))
		{
			if (neg == 1)
				r = r * -1;
			return (r);
		}
		if_num(str, &r, i, &sp);
		i++;
	}
	if (neg == 1)
		r = r * -1;
	return (r);
}
