/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 05:24:40 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/23 09:36:28 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static	int		count_tets(char *s)
{
	int i;
	int c;

	i = -1;
	c = 1;
	while (++i < (int)ft_strlen(s) -1)
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			c++;
	}
	return (c);
}

char	**parse_tets(char *s)
{
	char	**a;
	int		i;
	int		i2;
	int		x;
	int		c;

	a = (char **)ft_memalloc(sizeof(char *) * (count_tets(s) + 1));
	i = 0;
	x = 0;
	c = 0;
	while (i < count_tets(s))
	{
		a[i] = ft_strnew(16);
		i2 = 0;
		while (i2 == 0 || (x - c) % 20 != 0)
		{
			if (s[x] != '\n')
			{
				a[i][i2] = s[x];
				i2++;
			}	
			x++;
		}
		i++;
		x++;
		c++;
	}
	a[i] = NULL;
	return (a);
}
