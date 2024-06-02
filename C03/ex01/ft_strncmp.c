/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:56:17 by oait-laa          #+#    #+#             */
/*   Updated: 2023/09/21 15:24:04 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				r;

	i = 0;
	r = s1[i] - s2[i];
	if (n == 0)
		return (0);
	if (s1[i] == '\0')
	{
		r = s1[i] - s2[i];
		return (r);
	}
	while (i != n)
	{
		if (s1[i] != s2[i])
		{
			r = s1[i] - s2[i];
			return (r);
		}
		i++;
	}
	return (r);
}
