/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:59:16 by oait-laa          #+#    #+#             */
/*   Updated: 2023/10/02 16:47:38 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	skip(char *str, int *i, int *neg);
int		power(int n, int l);

int	checker(char *base, char *str, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!((str[n] >= '0' && str[n] <= '9') || (str[n] >= 'a' && str[n] <= 'z')
			|| (str[n] >= 'A' && str[n] <= 'Z')))
		return (0);
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == ' ' || base[i] == '-' || base[i] == '+')
			return (0);
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	os;
	int	r;
	int	h;
	int	neg;

	i = 0;
	r = 0;
	neg = 1;
	skip(str, &i, &neg);
	os = i;
	len(str, &os, base);
	while (str[i] && checker(base, str, i))
	{
		h = 0;
		while (base[h] && base[h++] != str[i])
			if (str[i] == base[h])
				r = r + h * power(len(str, &os, base), os - i - 1);
		i++;
	}
	return (r * neg);
}

void	ft_putnbr_base(int nbr, char *base, char *test, int *index)
{
	int		l;
	int		i;
	long	n;

	l = 0;
	i = 0;
	n = nbr;
	while (test[i])
		i++;
	while (base[l])
		l++;
	if (l != 0 && checker(base, "0", 0))
	{
		if (n < 0)
		{
			test[(*index)++] = '-';
			n = n * -1;
		}
		if (n / l > 0)
			ft_putnbr_base(n / l, base, test, index);
		test[(*index)++] = base[n % l];
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		j;
	int		num;
	char	test[100];
	char	*result;

	i = 0;
	j = 0;
	num = ft_atoi_base(nbr, base_from);
	ft_putnbr_base(num, base_to, test, &i);
	result = (char *)malloc(i + 1);
	while (test[j])
	{
		result[j] = test[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}
