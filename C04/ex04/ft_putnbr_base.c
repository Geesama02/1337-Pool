/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:45:06 by oait-laa          #+#    #+#             */
/*   Updated: 2023/10/01 14:23:31 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checker(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == ' ' || base[i] == '-' || base[i++] == '+')
			return (0);
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (1);
}

int	len(char *str, int *os, char *base)
{
	int	i;

	i = 0;
	while (str[*os] && ((str[*os] >= '0' && str[*os] <= '9') || (str[*os] >= 'a'
				&& str[*os] <= 'z') || (str[*os] >= 'A' && str[*os] <= 'Z')))
		(*os)++;
	while (base[i])
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		l;
	long	n;
	char	c;

	l = 0;
	n = nbr;
	while (base[l])
		l++;
	if (l != 0 && checker(base))
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = n * -1;
		}
		if (n / l > 0)
			ft_putnbr_base(n / l, base);
		c = base[n % l];
		write(1, &c, 1);
	}
}
