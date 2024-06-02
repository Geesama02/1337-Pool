/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:07:37 by oait-laa          #+#    #+#             */
/*   Updated: 2023/09/30 09:36:40 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	r;
	int	i;

	i = 0;
	r = 0;
	if (s1[i] == '\0')
	{
		r = s1[i] - s2[i];
		return (r);
	}
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			r = s1[i] - s2[i];
			return (r);
		}
		i++;
	}
	r = s1[i] - s2[i];
	return (r);
}

void	swap_str(char **s1, char **s2)
{
	char	*t;

	t = *s1;
	*s1 = *s2;
	*s2 = t;
}

void	ft_print(int i, int j, char **str, int argc)
{
	while (i < argc)
	{
		j = 0;
		while (str[i][j])
		{
			write(1, &str[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
				swap_str(&argv[j], &argv[i]);
			j++;
		}
		i++;
	}
	i = 1;
	j = 0;
	ft_print(i, j, argv, argc);
	return (0);
}
