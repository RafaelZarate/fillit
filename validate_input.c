/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 03:55:46 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/09 10:10:14 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

static	int	check_pounds(int **p, char *s)
{
	int		i;
	int		i2;
	int		sum;

	i = -1;
	while (++i < count_tets(s))
	{
		i2 = -1;
		sum = 0;
		while (++i2 < 16)
			sum += p[i][i2];
		if (sum != 4)
			return (0);
	}
	return (1);
}

static	int	check_chars(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static	int	check_nl(char *s)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (((i - c + 1) % 5 == 0) && s[i] != '\n' && i != 0)
			return (0);
		else if (((i - c) % 20 == 0) && s[i] != '\n' && i != 0)
			return (0);
		if ((i - c) % 20 == 0 && i != 0)
		{
			c++;
			i++;
			if (s[i] == '\n')
				return (0);
		}
		i++;
	}
	return (1);
}

int			check_input(char *s)
{
	size_t	i;
	int		**a;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	if (!s[i])
		return (-1);
	if (count_tets(s) > 26)
		return (0);
	if (s[len - 1] == '\n' && s[len - 2] == '\n')
		return (0);
	else if (check_chars(s) && check_nl(s))
	{
		a = parse_tets(s);
		if (check_pounds(a, s))
			return (1);
	}
	return (0);
}
