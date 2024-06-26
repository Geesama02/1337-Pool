/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:39:59 by oait-laa          #+#    #+#             */
/*   Updated: 2023/09/27 16:53:30 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;
	long	n;

	n = nb;
	i = 2;
	if (nb == 1)
		return (1);
	while (i * i <= n)
	{
		if (i * i == n)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
