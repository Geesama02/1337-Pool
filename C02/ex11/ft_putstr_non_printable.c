/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:43:13 by oait-laa          #+#    #+#             */
/*   Updated: 2023/09/19 14:57:56 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_txt(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			write_txt(str[i]);
		}
		else
		{
			write_txt('\\');
			write_txt("0123456789abcdef"[str[i] / 16]);
			write_txt("0123456789abcdef"[str[i] % 16]);
		}
		i++;
	}
}
