/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:41:00 by oait-laa          #+#    #+#             */
/*   Updated: 2023/09/21 19:55:12 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	dest_len(char *dest, int *i)
{
	while (dest[*i] != '\0')
		(*i)++;
}

void	src_len(char *src, int *l)
{
	*l = 0;
	while (src[*l] != '\0')
		(*l)++;
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	unsigned int	j;
	unsigned int	d;
	int				l;

	i = 0;
	j = 0;
	dest_len(dest, &i);
	src_len(src, &l);
	d = i;
	if (d < size)
	{
		while (src[j] != '\0' && j < size - d - 1)
		{
			dest[i] = src[j];
			j++;
			i++;
		}
		dest[i] = '\0';
	}
	else
		return (l + size);
	return (d + l);
}
