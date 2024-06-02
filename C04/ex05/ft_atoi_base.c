/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:12:11 by oait-laa          #+#    #+#             */
/*   Updated: 2023/10/01 14:55:57 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	skip(char *str, int *i, int *neg)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
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
