/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:34:20 by oait-laa          #+#    #+#             */
/*   Updated: 2023/09/14 17:09:51 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char b2, char a1, char a2, char b1)
{
	while (b2 <= '9')
	{
		write(1, &a1, 1);
		write(1, &a2, 1);
		write(1, " ", 1);
		write(1, &b1, 1);
		write(1, &b2, 1);
		if (a1 == '9' && a2 == '8' && b1 == '9' && b2 == '9')
		{
			write(1, "", 0);
		}
		else
		{
			write(1, ", ", 2);
		}
		b2++;
	}
}

void	ft_print_comb2(void)
{
	char	a1;
	char	a2;
	char	b1;
	char	b2;

	a1 = '0';
	while (a1 <= '9')
	{
		a2 = '0';
		a1 = a1 + 0;
		while (a2 <= '8')
		{
			b1 = a1;
			while (b1 <= '9')
			{
				b2 = a2 + 1;
				print_char(b2, a1, a2, b1);
				b1++;
			}
			a2++;
		}
		a1++;
	}
}
