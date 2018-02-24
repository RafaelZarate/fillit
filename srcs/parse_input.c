/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 05:24:40 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/24 04:59:26 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		count_tets(char *s)
{
	int i;
	int c;

	i = ft_strlen(s) - 1;
	c = 1;
	while (--i > 0)
	{
		if (s[i] == '\n' && s[i - 1] == '\n')
			c++;
	}
	return (c);
}

// int	*parse_tets(char *s)
// {
// 	//int	**aa;
// 	int	*a;
// 	int	i;
// 	int	i2;

// 	printf("%d\n", count_tets(s));
// 	a = (int *)ft_memalloc((int)(16 * count_tets(s)));
// 	i = -1;
// 	i2 = 0;
// 	while (s[++i])
// 	{
// 		printf("%i\t", i);
// 		if (s[i] != '\n')
// 		{
// 			if (s[i] == '#')
// 				a[i2] = 1;
// 			else if (s[i] == '.')
// 				a[i2] = 0;
// 			i2++;
// 		}
// 	}
// 	return (a);
// }

int	**parse_tets(char *s)
{
	int	**a;
	int		i;
	int		i2;
	int		x;

	a = (int **)ft_memalloc(sizeof(int *) * count_tets(s));
	i = -1;
	x = -1;
	while (++i < count_tets(s))
	{
		a[i] = (int *)ft_memalloc(sizeof(int) * 16);
		i2 = 0;
		while (++x < (20 * (i + 1) + i))
		{
			if (s[x] != '\n')
			{
				if (s[x] == '#')
					a[i][i2] = 1;
				else if (s[x] == '.')
					a[i][i2] = 0;
				i2++;
			}
		}
	}
	return (a);
}

int	*make_tets(int	**at)
{
	int	*r;

	at = NULL;
	r = NULL;
	return (r);
}
